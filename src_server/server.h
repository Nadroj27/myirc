/*
** server.h for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:14:36 2015 Pierre NOEL
** Last update Wed Apr 15 11:12:35 2015 Pierre NOEL
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
# include		<math.h>
# define		color(x, txt) printf("\033[%sm%s\033[0m", x, txt)
# define		FD_FREE 0
# define		FD_CLIENT 1
# define		FD_SERVER 2
# define		MAX_FD 255
# define		RETOUR_C "\r\n"

typedef void(*fct)();
typedef struct s_env*(*fct2)();

typedef struct		s_channel
{
  char			*name;
  struct s_channel	*next;
}			t_channel;

typedef struct		s_env
{
  int			id;
  int			port;
  char			*channel;
  char			*nickname;
  char			*pseudo;
  char			*host;
  char			*host_name;
  char			*real_name;
  char			*return_code;
  t_channel		*channels;
  fct2			fct_read;
  fct			fct_write;
  struct s_env		*next;
  char			fd_type;
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
void			my_error_c(char *, int);
void			response_fail(char **, int);
char			*my_read_irc(int);
t_cmd			*check_command(char *, int, int);
int			choose_cmd(t_env *, t_cmd *, t_env *);
t_env			*add_event(t_env *, fct2, fct, int);
t_env			*find_by_id(t_env *, int);
void			dump(t_env *);
char			*xstrcat(char *, char *);
void			client_write(t_env *, int);
t_env			*client_read(t_env*, int);
char			*append_two(char *, char *);
void			add_client(t_env *, int);
char			*uint_to_char(unsigned int );
t_env			*server_read(t_env *, int);
void			add_server(t_env *);
int			my_fd_set_list(t_env *, fd_set *, fd_set *);
void			my_fd_isset_write(t_env *, fd_set *);
void			my_fd_isset(t_env *, fd_set *, fd_set *);
char			**concatDoubleChar(char **, char **);
void			free_my_double_char(char **);
char			**list_canal(t_env*, char *, char **, char **);
void			my_nickname(t_env*, t_cmd *, t_env *);
void			my_list(t_env*, t_cmd *, t_env *);
void			my_join(t_env*, t_cmd *, t_env *);
void			my_msg(t_env*, t_cmd*, t_env *);
void			my_user(t_env*, t_cmd*, t_env*);
void			my_part(t_env*, t_cmd*, t_env*);
void			add_channel(t_env *, char *);
int			del_channel(t_env *, char *);
int			have_channel(t_env *, char *);

#endif			/* _SERVER_H_ */
