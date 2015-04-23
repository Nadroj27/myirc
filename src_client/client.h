/*
** server.h for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:14:36 2015 Pierre NOEL
** Last update Thu Apr 23 11:36:49 2015 Pierre NOEL
*/

#ifndef			_CLIENT_H_
# define		_CLIENT_H_

# include		<netdb.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/time.h>
# include		<unistd.h>
# include		<stdio.h>
# include		<stdlib.h>
# include		<errno.h>
# include		<string.h>

# define		RED	1
# define		GREEN	2
# define		YELLOW	3
# define		BLUE	4

typedef	void(*fct)();

typedef	struct		s_map
{
  char			*name;
  int			(*ptr_fct)();
  struct	s_map	*next;
  int			hasWrite;
}			t_map;

typedef struct		s_client
{
  char			*nickname;
  char			*channel;
}			t_client;

t_map			*init_map(t_map *);
t_map			*add_element(t_map *, const char *,
				     int (*)(char **, int));
t_map			*add_element2(t_map *, const char *,
				      int (*)(char **, t_client *));
void			my_error(char *, int );
void			check_input(int , t_map *, char *, t_client *);
void			check_command(char *, int , t_map *, t_client *);
void			init_tab(char *);
int			command_in_the_map(t_map *, char **, int);
char			**my_str_to_wordtab(char *str, char c);
int			my_strnlen(char *str, char c);
int			count_words(char *str, char c);
char			*modif_input(char *str);
int			connection_server(char **argv, int sfd);
int			msg_user(char **argv, int sfd);
int			change_nickname(char **argv, int sfd);
int			list_user(char **argv, int sfd);
int			list_channel(char **argv, int sfd);
int			join_channel(char **argv, int sfd);
int			part_channel(char **argv, int sfd);
int			send_file(char **argv, int sfd);
int			accept_file(char **argv, int sfd);
t_map			*init_return_code();
int			nickname_changed(char **, t_client *);
int			server_connected(char **, t_client *);
void			textcolor(int, char *, int);
void			cutbuff(char *, unsigned int);

#endif			/* _CLIENT_H_ */
