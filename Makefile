##
## Makefile for myirc in /home/noel_h/rendu/PSU_2014_myirc
## 
## Made by Pierre NOEL
## Login   <noel_h@epitech.net>
## 
## Started on  Wed Mar 25 10:36:32 2015 Pierre NOEL
## Last update Wed Mar 25 10:39:21 2015 Pierre NOEL
##

NAME_S			=		server

NAME_C			=		client

SRC_S			=		src_server/server.c

SRC_C			=		src_client/client.c

OBJ_S			=		$(SRC_S:.c=.o)

OBJ_C			=		$(SRC_C:.c=.o)

CFLAGS			=		-W -Wall -Wextra

all:			$(NAME_S) $(NAME_C)

$(NAME_S):		$(OBJ_S)
			gcc -o $(NAME_S) $(OBJ_S) $(CFLAGS)

$(NAME_C):		$(OBJ_C)
			gcc -o $(NAME_C) $(OBJ_C) $(CFLAGS)

clean:
			rm -rf $(OBJ_S)
			rm -rf $(OBJ_C)

fclean:			clean
			rm -rf $(NAME_S)
			rm -rf $(NAME_C)

re:			fclean all
