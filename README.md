# Snow Crash: Introducción a la Ciberseguridad

Este proyecto constituye una base práctica en seguridad informática, diseñada para identificar y explotar debilidades en el software con el fin de comprender los riesgos a los que se exponen los usuarios y aprender a evitarlos. A través de una serie de retos técnicos, se fomenta el desarrollo de un pensamiento lógico y analítico aplicable en diversas áreas de IT.

## Configuración y Acceso al Entorno

El desarrollo de los desafíos se realiza sobre una máquina virtual de 64 bits suministrada mediante una imagen ISO. Una vez iniciada la máquina, el acceso principal se efectúa mediante una conexión SSH a través del puerto 4242, utilizando las credenciales iniciales `level00:level00`. En caso de que la dirección IP no sea visible en el prompt de inicio, puede recuperarse utilizando el comando `ifconfig` una vez establecida la sesión.

## Metodología de Progresión

La estructura del proyecto es incremental y se basa en la escalada de privilegios. El objetivo en cada etapa es localizar la contraseña o vulnerabilidad que permita acceder a la cuenta de usuario `flagXX` correspondiente al nivel actual. Tras obtener dicho acceso, la ejecución del comando `getflag` proporcionará el token necesario para autenticarse en el siguiente nivel de la serie. Si no es posible una conexión directa, se deben explorar métodos alternativos como la inyección de comandos según los permisos del sistema.

## Alcance del Proyecto

La sección obligatoria del proyecto comprende desde el `level00` hasta el `level09` . Los niveles de bonificación, del `level10` al `level14`, solo se tomarán en cuenta si la parte obligatoria se completa de manera perfecta, sin errores de comportamiento o uso inadecuado .
