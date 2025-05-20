<h1 align="center">Level 08 Walkthrough ~ Symbolic links</h1>

Realmente ha sido todo intuición sobre como estaba compuesto el código,
delante tengo un binario compilado en C con permisos SUID para el usuario flag08
y un fichero llamado 'token' que contiene la contraseña de flag08.

¿Cómo procedo?, tras tratar de analizar los procesos con pspy me doy cuenta de que
no tengo capacidad de ver lo que ocurre por fuera así que me centro en analizar el binario. 
Hago algunas pruebas con strace para ver que información me puede dar pero al final vuelvo
a la opción confiable, 'strings' y ahí encuentro salsa de la buena.
Lo primero de todo, el binario lo único que hace es leer información de un fichero.
```bash
./level08
./level08 [file to read]
```
Pero token no me deja leerlo directamente...

```bash
./level08 token
You may not access 'token'
```
Así que se me enciende la bombilla, ¿links simbólicos? al analizar con strings veo cosas 
que me dan a entender que si el fichero se llama token directamente no me deja leerlo, 
lo intuyo por estas 3 líneas de `strings`:
```txt
%s [file to read]
token
You may not access '%s'
```
Creo el link simbólico de la siguiente manera:
```bash
ln -s ~/token /tmp/pwned
```
> Importante escribir su ruta absoluta ya que si no dependeríamos del lugar desde el que
> ejecutemos el binario y el link simbólico estaría roto o inservible.
Y después lo ejecuto:
```
~/level08 /tmp/pwned
```
¡Y tachán!
consigo la flag y paso al [siguiente nivel](../../level09/resources/README.md).
