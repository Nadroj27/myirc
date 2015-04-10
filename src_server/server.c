/*
** main2.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 14:38:36 2015 Pierre NOEL
** Last update Fri Apr 10 15:25:49 2015 Pierre NOEL
*/

#include	"server.h"

/* buffer circulaire ???  */
void		client_read(t_env *e, int fd)
{
  char		*msg;
  t_cmd		*cmd;
  t_env		*client;

  client = find_by_id(e, fd);
  msg = my_read_irc(fd);
  printf("okok");
  if (msg == NULL || strlen(msg) < 1)
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      client->fd_type = FD_FREE;
    }
  else
    {
      printf("Client %d: %s\n", fd, msg);
      cmd = check_command(msg, 0, 1);
      choose_cmd(e, cmd, client);
    }
  if (msg != NULL)
    free(msg);
  // cmd à free;
}

void		client_write(t_env *e, int fd)
{
  t_env		*client;
  char		*info = malloc(512);

  client = find_by_id(e, fd);
  if (client->return_code != NULL)
    {
      printf("Write to  client\n");
      /*   sprintf(info, ":127.0.0.1 %s",
	      client->return_code);
 */
      sprintf(info, ":%s!%s@%s %s",
	      client->nickname,
	      client->pseudo,
	      client->host,
	      client->return_code);
      printf("info  = %s\n", info);
      write(fd, info, strlen(info));
      free(client->return_code);
      client->return_code = NULL;
    }
}

void		add_client(t_env *e, int s)
{
  int		cs;
  struct sockaddr_in client_sin;
  socklen_t    	client_sin_len;
  t_env		*a;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  if (cs == -1)
    my_error("Failed to accept", 1);
  a = add_event(&e, client_read, client_write, ntohs(client_sin.sin_port));
  a->fd_type = FD_CLIENT;
  a->id = cs;
  a->channel = NULL;
  a->nickname = NULL;//strdup("Anonymous");
  a->pseudo = NULL;strdup("Anonymous");
  a->return_code = NULL;
}

void		server_read(t_env *e, int fd)
{
  printf("New client\n");
  add_client(e, fd);
}

void				add_server(t_env *e)
{
  int				s;
  struct sockaddr_in		sin;
  struct protoent		*pe;

  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    my_error("Failed to socket", 1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    my_error("Failed to bind", 1);
  if (listen(s, 42) == -1)
    my_error("Failed to listen", 1);
  e->fd_type = FD_SERVER;
  e->fct_read = server_read;
  e->fct_write = NULL;
  e->channel = NULL;
  e->nickname = NULL;
  e->return_code = NULL;
  e->next = NULL;
  e->id = s;
}

int		my_fd_set_list(t_env *e, fd_set *read, fd_set *write)
{
  int		fd_max;
  t_env		*tmp;

  FD_ZERO(read);
  FD_ZERO(write);
  tmp = e;
  fd_max = 1;
  while (tmp)
    {
      if (tmp->fd_type != FD_FREE)
	{
	  FD_SET(tmp->id, read);
	  FD_SET(tmp->id, write);
	  fd_max = tmp->id;
	}
      tmp = tmp->next;
    }
  return (fd_max);
}


void		my_fd_isset_write(t_env *e, fd_set *write)
{
  t_env		*tmp;

  tmp = e;
  while (tmp)
    {
      if (FD_ISSET(tmp->id, write))
	{
	  if (tmp->fct_write != NULL)
	    tmp->fct_write(e, tmp->id);
	}
      tmp = tmp->next;
    }
}


void		my_fd_isset(t_env *e, fd_set *read, fd_set *write)
{
  t_env		*tmp;

  tmp = e;
  while (tmp)
    {
      if (FD_ISSET(tmp->id, read))
	tmp->fct_read(e, tmp->id);
      my_fd_isset_write(e, write);
      tmp = tmp->next;
    }
}

int		main(int ac, char **av)
{
  t_env		*e;
  int		fd_max;
  fd_set	fd_read;
  fd_set	fd_write;
  struct timeval tv;

  if (ac != 2)
    my_error("Usage : ./server [port]", 0);
  if ((e = malloc(sizeof(t_env))) == NULL)
    my_error("Malloc failed", 0);
  if (atoi(av[1]) <= 0) // et checker overflow A FAIRE
    my_error("Port need to be positif and not overflow", 0);
  e->port = atoi(av[1]);
  e->next = NULL;
  add_server(e);
  tv.tv_sec = 20;
  tv.tv_usec = 0;
  while (1)
    {
      fd_max = my_fd_set_list(e, &fd_read, &fd_write);
      if (select(fd_max + 1, &fd_read, &fd_write, NULL, &tv) == -1)
	my_error("select failed", 1);
      my_fd_isset(e, &fd_read, &fd_write);
      sleep(2);
    }
  return (0);
}
