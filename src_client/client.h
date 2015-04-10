/*
** server.h for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:14:36 2015 Pierre NOEL
** Last update Thu Apr  9 17:15:12 2015 Jérémy MATHON
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
# define		color(x, txt) printf("\033[%sm%s\033[0m", x, txt)

typedef	void(*fct)();

typedef	struct		s_map
{
  char			*name;
  int			(*ptr_fct)();
  struct	s_map	*next;
}			t_map;

/* METHODS MAP OBJECT */
t_map			*init_map(t_map *);
t_map			*add_element(t_map *, const char *, int (*)(char **, int));

void			my_error(char *s, int opt);
void			check_input(int sfd, t_map *map);
void			check_command(char *str, int sfd, int length, t_map *map);
void			init_tab(char *tab);
void			command_in_the_map(t_map *, char **, int);
char			**my_str_to_wordtab(char *str, char c);
int			my_strnlen(char *str, char c);
int			count_words(char *str, char c);
void			mloop(int sfd);
char			*modif_input(char *str);

/* FUNCTIONS IN MAP OBJECT */
/* funct_user */
int			connection_server(char **argv, int sfd);
int			msg_user(char **argv, int sfd);
int			change_nickname(char **argv, int sfd);
int			list_user(char **argv, int sfd);
/* funct_channel */
int			list_channel(char **argv, int sfd);
int			join_channel(char **argv, int sfd);
int			part_channel(char **argv, int sfd);
/* funct_file */
int			send_file(char **argv, int sfd);
int			accept_file(char **argv, int sfd);

#endif			/* _CLIENT_H_ */
