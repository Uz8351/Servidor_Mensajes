/*
main.c
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
//Debemos incluir nuestra entrada_salida.h 
#include "Servidor_Variables.h"  
int main()
{
    
/* Creación del Socket y comprobación de su ejecución,
 si devuelve -1 el descriptor habrá error*/
 int sockDescriptor = socket(AF_INET, SOCK_STREAM, 0);
if (sockDescriptor == -1)
   {
        printf("La creación del socket no ha tenido exito\n");
        exit(0);
    }
 
 /*En vez de pasar el puerto por argumento de main,
 lo hacemos por medio de la entrada standard scanf.*/

printf("---Introduce un Puerto superior a 1000-\n");
scanf("%s",puerto);
valor =atoi(puerto); //Esta función convierte el argumento de una cadena  en un número entero (tipo int).
    
    strucServidor.sin_family = AF_INET;
    strucServidor.sin_addr.s_addr = htonl(INADDR_ANY); // (Adaptacion Little Endian o Big Endian) para red
    strucServidor.sin_port = htons(valor); //La función htons convierte un u_short de host
    // a orden de bytes de red TCP/IP ( big-endian).
   
    // Enlace de socket recién creado a IP dada y verificación
    if ((bind(sockDescriptor, (struct sockaddr *)&strucServidor, sizeof(strucServidor))) != 0) {
        printf("socket bind ha fallado...\n");
                exit(0);
    }
    else
        printf("Socket enlazado con éxito.\n");

//printf("La IP local es: %s\n", inet_ntoa(strucServidor.sin_addr));
printf("El Puerto local de conexión es: %d\n", (int) ntohs(strucServidor.sin_port));
//*******************************************************************
   
    // Ahora el Servidor está preparado para escuchar
    if ((listen(sockDescriptor, 5)) != 0) { //Ponemos el socket a escuchar, y  una cola máxima de 5 clientes.
        printf("La escucha de Clientes ha fallado...\n");
        exit(0);
    }
    else
        printf("El Servidor está preparado\n");
    Larg = sizeof(struCliente);
   
    // Aceptamos datos del cliente. 
    chatServClient = accept(sockDescriptor, (struct sockaddr *)&struCliente, &Larg);//Nuevo socket abierto por aceppt()
        if (chatServClient <= 0) {
        printf("El servidor no ha aceptado\n");
        exit(0);
    }
    else
        printf("El servidor acepta CLIENTE con nuevo SOCKET-Descriptor %d: \n",chatServClient);
   
    // Llamada a la función lafunc que trabajará con los buffer
    lafunc(chatServClient);
   
    // El socket descriptor es cerrado
    close(sockDescriptor);
}