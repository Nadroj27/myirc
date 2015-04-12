/*
** create_server.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:59:05 2015 Pierre NOEL
** Last update Sun Apr 12 19:30:33 2015 Pierre NOEL
*/

#include				"server.h"

t_env					*server_read(t_env *e, int fd)
{
  printf("New Client\n");
  add_client(e, fd);
  return (e->next);
}

static void				initialise_serv(t_env *e)
{
  e->fct_read = server_read;
  e->fct_write = NULL;
  e->channel = NULL;
  e->nickname = NULL;
  e->real_name = NULL;
  e->host_name = NULL;
  e->pseudo = NULL;
  e->return_code = NULL;
  e->next = NULL;
}

void					add_server(t_env *e)
{
  int					s;
  struct sockaddr_in			sin;
  struct protoent			*pe;

  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  if ((s = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    my_error("Failed to socket", 1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    my_error("Failed to bind", 1);
  if (listen(s, 42) == -1)
    my_error("Failed to listen", 1);
  e->fd_type = FD_SERVER;
  e->host = inet_ntoa(sin.sin_addr);
  e->id = s;
  initialise_serv(e);
}
