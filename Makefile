##*******************************
## Makefile en  /home/margaritu/pro
## Primera versión de prueba.
## 
## Login   <mininoxeixo28@gmail.com>
## Iniciado   lun 03 Jun 2022 16∶03∶58
## Finalizado lun 18 Jul 2022 19∶04∶02  
## **********************************

SRC	= src/main.c \
	src/utilidades/entrada_salida.c \
	
    
OBJ	= $(SRC:.c=.o)

NAME	= Sevidor_Mensajes

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -pedantic-errors
CFLAGS	+= -I./include

all: $(NAME) ## multples nombres

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all cl