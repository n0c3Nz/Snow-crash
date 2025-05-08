#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
char token[] = "f4kmm6p|=pnDBDu{";

int main(void){
    int  j = 0;
    int k = 0;
    char newchar;
    for (int i = 0; i <= 100; i++){
        while (k < 16){
            if (token[k] > 126 || token[k] < 32)
                token[k] = ' ';
            else
                token[k] += k;
            if (token[k] > 126 || token[k] < 32)
                token[k] = ' ';
            k++;
        }
        printf("%s\n", token);
        k = 0;
    }
    printf("\n");
    return 0;
}