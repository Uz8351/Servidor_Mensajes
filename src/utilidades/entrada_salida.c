/*
entrada_salida.c
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include "Servidor_Variables.h"
//Declaración de la estructura sockaddr contenidas en #include<netinet/in.h>

   
// Declaramos una función destinada para el chat cliente servidor.
void lafunc(int chatServClient)
{
    char buferIntercambio[90]; //Reserva de buffer para el intercambio de 90bytes write y read
    int h;
    // Este es un bucle  repetitivo read >-> write para el  chat interactivo
    for (;;) {
        bzero(buferIntercambio, 90);//borra los datos en los n bytes de la memoria
       //comenzando en la ubicación señalada , escribiendo ceros (bytes que contiene '\0') en esa área.
   
        // Leemos el mensaje del cliente y lo copiamos en buferIntermedio.
        read(chatServClient, buferIntercambio, sizeof(buferIntercambio));

        // Imprimimos el contenido del buffer del cliente.
        printf("Mensaje del cliente: %s\t : ", buferIntercambio);
        bzero( buferIntercambio,90);//volvemos a borrar datos
        h = 0;
        // Copiamos el mensaje del Servidor en el buffer. 
        while ((buferIntercambio[h++] = getchar()) != '\n');
        //repetir bucle mientras no sea igual.
        //chatServClient es el nuevo descriptor de socket creado por aceppt.
        //Para cada cliente aceptado se crear'un nuevo Descriptor Socket
   
        //  Mandamos el contenido del bufer al client utilizando la función write().
        write(chatServClient, buferIntercambio, sizeof(buferIntercambio));
   
        /* Si el mensaje contiene hasta luego lucas 
         entonces el seridor sale y el chat termina.*/
        if (strncmp("hasta luego lucas", buferIntercambio, 16) == 0)
           // la llamada strncmp compara caracteres, 
            //en este caso le decimos que compare 16.
            // si el servidor manda el mensaje "hasta luego lucas" 16 bytes --16) == 0)
            //el servidor saldrá de la conexión
         {
            printf("Salida del Servidor\n");
            break;
            
        }
        }
        }