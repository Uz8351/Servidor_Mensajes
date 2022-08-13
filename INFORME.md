Se ha realizado este Sevidor para chat,
con el fin de poder interactuar
con él a través de dos consolas
Linux en el mismo ordenador,
utilizando la dirección Localhost (127.0.0.1),
u otra en la cual la configración del
cortafuegos lo permita.
Una vez abierto, y a la escucha el servidor,
se podrán interactuar mensajes
a través del comando linux, por ejemplo
nc 127.0.0.1 5898, (donde 5898, sería el puerto
elegido en la entrada por consola),o utilizando el antiguo
TELNET.
Deberemos de colocar como atributo del comando
nc de linux la ip y el puerto establecido
en el servidor previamente.
------------------------------------------
Con el fin de poder aprender personalmente
el desarrollo de un proyecto, he dividido lo
que sería un solo el programa de un simple servidor
chat en ANSI-C, en varios módulos con el fin de subirlo
a GITHUB, y poder bajarlo del mismo comprimido
en formato zip,y poder instalarlo con make.
Quiero decir con esto que el programa tiene
una doble finalidad por mi parte: entender un poco el
desarrollo y funcionamiento de sockets, y al mismo
tiempo utilizarlo y dividirlo como un sencillo proyecto
para subirlo a GITHUB.

Por otro lado, para el que quiera, también podría utilizarse con sniffer
Wireshark con el fin de analizar la transferencia
y el comportamientos de de paquetes con los mensajes trasnmitidos.
