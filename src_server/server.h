/*
** server.h for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:14:36 2015 Pierre NOEL
** Last update Thu Apr  9 15:29:26 2015 Pierre NOEL
*/

#ifndef			_SERVER_H_
# define		_SERVER_H_

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
# define		FD_FREE 0
# define		FD_CLIENT 1
# define		FD_SERVER 2
# define		MAX_FD 255

typedef void(*fct)();

typedef struct		s_env
{
  int			id;
  char			fd_type;
  fct			fct_read;
  fct			fct_write;
  int			port;
  char			*channel;
  char			*nickname;
  char			*real_name;
  char			*host;
  char			*host_name;
  char			*return_code;
  struct s_env		*next;
}			t_env;



typedef struct		s_cmd
{
  char			*full_cmd;
  char			*prefix;
  char			*cmd;
  char			*opt[16];
}			t_cmd;

typedef struct		s_list_cmd
{
  char			*name;
  void			(*fct)(t_env *, t_cmd*, t_env*);
  struct s_list_cmd	*next;
}			t_list_cmd;

void			my_error(char *, int);
char			*my_read_irc(int);
t_cmd			*check_command(char *, int, int);
int			choose_cmd(t_env *, t_cmd *, t_env *);
t_env			*add_event(t_env **, fct, fct, int);
t_env			*find_by_id(t_env *, int);
void			dump(t_env *a);
char			*xstrcat(char *dest, char *src);

/* Commandes */

void			my_nickname(t_env*, t_cmd *, t_env *);
void			my_list(t_env*, t_cmd *, t_env *);
void			my_join(t_env*, t_cmd *, t_env *);
void			my_msg(t_env*, t_cmd*, t_env *);
void			my_user(t_env*, t_cmd*, t_env*);
#endif			/* _SERVER_H_ */
