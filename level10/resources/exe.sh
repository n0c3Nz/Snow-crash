# Crea un archivo inicial
echo "test" > /tmp/myfile
# En otra terminal, prepara el cambio
while true; do ln -sf /home/user/level10/token /tmp/myfile; done
# Ejecuta el binario
/home/user/level10/level10 /tmp/myfile 127.0.0.1