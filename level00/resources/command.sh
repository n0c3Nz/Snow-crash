#!/bin/bash

# Si se supone que debo acceder al usuario flag00 lo que debería
# hacer en primera instancia es buscar ficheros en el sistema
# cuyo propietario sea flag00, esto lo consigo con find.

binario=$(find / -user "flag00" 2>/dev/null | head -n 1)
cat $binario
echo "--------"
file $binario
echo "--------"
cat $binario
echo "--------"
echo "ROT11"
cat $binario | tr 'A-Za-z' 'L-ZA-Kl-za-k'

# Encuentro el siguiente fichero
#
# /usr/sbin/john
# /rofs/usr/sbin/john
#
# Ejecuto el comando file para ver qué tipo de fichero es jhon
# Resulta que es un simple ascii text y al llamarse así me
# hace pensar en John The Ripper que es un software utilizado
# para romper passwords hasheadas basándose en listas de contraseñas
#
# Intuí por el aspecto del texto que sería un cifrado simple César
# o ROT13, así que comencé a toquetear y haciendo ROT11 descubrí la
# contraseña de flag00.
