Me encuentro con un binario, al descompilarlo veo lo siguiente:
```
void main(void)

{
  __uid_t UserId;
  char *token;
  
  UserId = getuid();
  if (UserId != 4242) {
    UserId = getuid();
    printf("UID %d started us but we we expect %d\n",U serId,4242);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  token = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
  printf("your token is %s\n",token);
  return;
}
```
Es un binario que valida que nuestro UID sea 4242, así que hago uso de la
flag de compilador LD_PRELOAD, para cargar mi propio .so el cual contiene lo
siguiente:

int getuid(){return 4242;}

LD_PRELOAD carga librerías personalizadas y se cargan antes que las inclusiones
del propio binario, por lo que creamos el .so y hacemos que LD_PRELOAD apunte a mi fichero

cd /tmp
gcc -c -fPIC -o types.o types.c
gcc -o types.so -shared types.o
chmod 4777 types.so

export LD_PRELOAD=/tmp/types.so


Después:

./level13
UID 2013 started us but we we expect 4242

Parece que no surte efecto pero si lo monitorizamos con strace entre todos los datos que
nos da podemos observar:

write(1, "your token is 2A31L79asukciNyi8u"..., 40your token is 2A31L79asukciNyi8uppkEuSx
) = 40

