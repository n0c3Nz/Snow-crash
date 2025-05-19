<h1 align="center">Level 02 Walkthrough ~ Network capture file analysis:</h1>

Al llegar a este nivel veo que en mi home encuentro un fichero llamado `level02.pcap`, este fichero es un volcado de tcpdump, 
(se puede apreciar usando `file`) me lo traigo a mi equipo local con scp:
```bash
scp -P 4242 level02@192.168.x.x:/home/user/level02/level02.pcap "$(pwd)"
```
Una vez tengo este fichero en mi poder decido analizarlo con Wireshark para ver qué información puedo sacar, veo una conversación 
entre dos IPs en la que parece que se está dando un intento de login cliente/servidor, lo veo a través de la sección `data` del 
histórico de Wireshark:

<p align="center"><img src="imgs/loginproof"></p>

> Recibimos un header del sistema que nos permite enviar nuestro nombre de usuario y contraseña.


Me da la contraseña de flag02, entro, ejecuto `getflag` y paso al [siguiente nivel](../../level03/resources/README.md).
