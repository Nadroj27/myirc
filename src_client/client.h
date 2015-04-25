/*
** server.h for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:14:36 2015 Pierre NOEL
** Last update Sat Apr 25 16:47:26 2015 Pierre NOEL
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
}			t_map;

typedef struct		s_client
{
  char			*nickname;
  char			*channel;
  char			*toServer;
  char			*toClient;
}			t_client;

t_map			*init_map(t_map *);
t_map			*add_element(t_map *, const char *,
				     int (*)(char **, t_client *));
t_map			*add_element2(t_map *, const char *,
				      int (*)(char **, t_client *));
void			my_error(char *, int );
void			check_input(t_map *, t_client *);
void			check_command(char *, t_map *, t_client *);
void			init_tab(char *);
int			command_in_the_map(t_map *, char **, t_client *);
char			**my_str_to_wordtab(char *str, char c);
int			my_strnlen(char *str, char c);
int			count_words(char *str, char c);
char			*modif_input(char *str);
int			connection_server(char **, t_client *);
int			msg_user(char **, t_client *);
int			change_nickname(char **, t_client *);
int			list_user(char **, t_client *);
int			list_channel(char **, t_client *);
int			join_channel(char **, t_client *);
int			part_channel(char **, t_client *);
int			send_file(char **, t_client *);
int			accept_file(char **, t_client *);
t_map			*init_return_code();
int			nickname_changed(char **, t_client *);
int			server_connected(char **, t_client *);
int			channel_changed(char **, t_client *);
int			channel_clean(char **, t_client *);
char			*textcolor(int, char *, int);
void			cutbuff(char *, unsigned int);
int			my_select(int, fd_set *, fd_set *);
void			read_server(int, t_client *, t_map*);
void			write_server(int, t_client *);
void			write_client(t_client *);
int			display_info(char *, t_client *, t_map*);
char			*xstrcat(char *s, char *d);

#endif			/* _CLIENT_H_ */
