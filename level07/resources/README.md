<h1 align="center">Level 07 Walkthrough ~ Environment variables</h1>

Este nivel es absurdamente sencillo, al llegar encuentro un binario compilado de C que al ser ejecutado
me da mi nombre `level07` por lo que instintivamente pienso que debe estar tirando de una variable 
de entorno así que miro en `env` y pruebo lo siguiente:

```bash
LOGNAME="flag07 && getflag" ./level07
```
¡Tachán! y paso al [siguiente nivel](../../level08/resources/README.md).
