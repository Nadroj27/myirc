##
## Makefile for myirc in /home/noel_h/rendu/PSU_2014_myirc
## 
## Made by Pierre NOEL
## Login   <noel_h@epitech.net>
## 
## Started on  Wed Mar 25 10:36:32 2015 Pierre NOEL
## Last update Mon Apr  6 17:19:13 2015 Pierre NOEL
##

NAME_S			=		server

NAME_C			=		client

SRC_S			=		src_server/server.c		\
					src_server/error.c		\
					src_server/read.c		\
					src_server/command.c		\
					src_server/command_make.c

SRC_C			=		src_client/client.c		\
					src_client/my_str_to_wordtab.c	\
					src_client/map_object.c		\
					src_client/funct_user.c		\
					src_client/funct_channel.c	\
					src_client/funct_file.c		\
					src_client/error.c


OBJ_S			=		$(SRC_S:.c=.o)

OBJ_C			=		$(SRC_C:.c=.o)

CFLAGS			=		-W -Wall -Wextra -g

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
