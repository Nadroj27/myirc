/*
** server.h for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:14:36 2015 Pierre NOEL
** Last update Mon Apr  6 17:00:52 2015 Pierre NOEL
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
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			port;
  //  char			*channel;
  //char			*nickname;
  //char			*real_name;
}			t_env;

typedef struct		s_cmd
{
  char			*prefix;
  char			*cmd;
  char			*opt[16];
}			t_cmd;

typedef struct		s_list_cmd
{
  char			*name;
  int			(*fct)(t_cmd*);
  struct s_list_cmd	*next;
}			t_list_cmd;

void			my_error(char *s, int opt);
char			*my_read_irc(int fd);
t_cmd			*check_command(char *str, int, int);
int			choose_cmd(t_cmd *);

#endif			/* _SERVER_H_ */
