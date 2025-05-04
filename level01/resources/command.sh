#!/bin/bash

# Ahora investigando ficheros con información relevante en el sistema
# he dado con el fichero /etc/passwd, que guarda la lista de usuarios
# registrados en el sistema, entre ellos veo que el único que tiene
# un hash DES es el flag01, este hash es una versión encriptada de
# la password del usuario que utilizaban antiguamente los sistemas
# UNIX para comparar si las contraseñas introducidas eran correctas,
# a esta se le aplica un salt, un número aleatorio lo que hace que
# todas sean únicas.
#
# Sabiendo que la primera flag la conseguí en un fichero llamado jhon
# me doy cuenta de que es una pista clara para que utilice esta tool
# para romper el hash y conseguir la contraseña.
#

echo "Hash  de /etc/passwd:"
cat /etc/passwd | grep flag01 | cut -d: -f2

# john --format=descrypt hash.txt
# john --format=descrypt hash.txt --show
#
# ¡Tachán!, tenemos la contraseña de flag01.

