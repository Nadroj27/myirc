##
## Makefile for myirc in /home/noel_h/rendu/PSU_2014_myirc
## 
## Made by Pierre NOEL
## Login   <noel_h@epitech.net>
## 
## Started on  Wed Mar 25 10:36:32 2015 Pierre NOEL
## Last update Sat Apr 11 14:46:28 2015 Pierre NOEL
##

NAME_S			=		server

NAME_C			=		client

SRC_S			=		src_server/server.c		\
					src_server/error.c		\
					src_server/read.c		\
					src_server/command.c		\
					src_server/command_make.c	\
					src_server/event_client.c	\
					src_server/nickname.c		\
					src_server/join.c		\
					src_server/msg.c		\
					src_server/user.c		\
					src_server/xstrcat.c		\
					src_server/client_write.c	\
					src_server/client_read.c	\
					src_server/add_client.c		\
					src_server/char_function.c	\
					src_server/create_server.c	\
					src_server/my_fd_set_isset.c

SRC_C			=		src_client/client.c		\
					src_client/my_str_to_wordtab.c	\
					src_client/map_object.c		\
					src_client/funct_user.c		\
					src_client/funct_channel.c	\
					src_client/funct_file.c		\
					src_client/funct_command.c	\
					src_client/error.c


OBJ_S			=		$(SRC_S:.c=.o)

OBJ_C			=		$(SRC_C:.c=.o)

CFLAGS			=		-W -Wall -Wextra -g

all:			server client

server:			$(OBJ_S)
			gcc -o $(NAME_S) $(OBJ_S) $(CFLAGS) -lm

client:			$(OBJ_C)
			gcc -o $(NAME_C) $(OBJ_C) $(CFLAGS)

clean:
			rm -rf $(OBJ_S)
			rm -rf $(OBJ_C)

fclean:			clean
			rm -rf $(NAME_S)
			rm -rf $(NAME_C)

re:			fclean all
