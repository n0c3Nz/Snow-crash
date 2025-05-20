<h1 align="center">Level 09 Walkthrough ~ Manual HEX script Decrypter:</h1>

Al llegar a este nivel veo que en mi home encuentro un fichero llamado `level09`, 
este fichero es un binario en C que hace lo siguiente:

```bash
./level09 "aaa"
output: abc
```
> Me devuelve texto incrementando el valor de cada carácter basado en su posición.

Y también veo un fichero `token`, al hacerle `file token` no me dice que es un ASCII txt,
en su lugar me dice que es `data`, le hago cat y veo `f4kmm6p|=pnDBDu{` pero hay que recordar
que no es tan solo texto ASCII así que lo abro con `vim` que me permite leer correctamente carácteres
en hexadecimal y veo lo siguiente:
```bash
f4kmm6p|=<82>^?p<82>n<83><82>DB<83>Du{^?<8c><89>
```
Esos valores se deben a que como se incrementa el valor de cada carácter basándose en su posición
estos valores "se salen" de la tabla ASCII, por ejemplo, el carácter hexadecimal <82> en decimal
equivale a `130`, este valor se debe a que como el carácter se encuentra en la posición 11 del token
habría que restarle 11 para averiguar el carácter original `(121 -> y)`, se me ocurre montar [un script
en C](reverse.c) que me haga la operación inversa al token para recuperar la contraseña "desencriptada"

Finalmente ejecutando el script me da la contraseña correcta, entro en flag09, ejecuto `getflag` y hasta
aqui la parte obligatoria, desde aqui damos paso paso a los bonus, vamos al [siguiente nivel](../../level05/resources/README.md).
