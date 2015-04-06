/*
** main2.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 14:38:36 2015 Pierre NOEL
** Last update Mon Apr  6 17:01:30 2015 Pierre NOEL
*/

#include	"server.h"

/* buffer circulaire ???  */
void		client_read(t_env *e, int fd)
{
  char		*msg;
  t_cmd		*cmd;

  if (e)
    {
      msg = my_read_irc(fd);
      printf("Client %d: %s\n", fd, msg);
      if (strlen(msg) <= 1)
	{
	  printf("%d: Connection closed\n", fd);
	  close(fd);
	  e->fd_type[fd] = FD_FREE;
	}
      cmd = check_command(msg, 0, 1);
      if (choose_cmd(cmd))
	{
	  //problem
	}
    }
}

void		client_write(t_env *e, int fd)
{
  if (e)
    {
      printf("Write to  client\n");
      write(fd, "202", 3);
    }
}

void		add_client(t_env *e, int s)
{
  int		cs;
  struct sockaddr_in client_sin;
  socklen_t    	client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = client_write;
}

void		server_read(t_env *e, int fd)
{
  printf("New client\n");
  add_client(e, fd);
}

void		add_server(t_env *e)
{
  int		s;
  struct sockaddr_in sin;
  struct protoent			*pe;

  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  bind(s, (struct sockaddr*)&sin, sizeof(sin));
  listen(s, 42);
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
}


int		main(int ac, char **av)
{
  t_env		e;
  int		i;
  int		fd_max;
  fd_set	fd_read;
  fd_set	fd_write;
  struct timeval tv;

  if (ac != 2)
    my_error("Usage : ./server [port]", 0);
  memset(e.fd_type, FD_FREE, MAX_FD);
  e.port = atoi(av[1]);
  add_server(&e);
  tv.tv_sec = 20;
  tv.tv_usec = 0;
  while (1)
    {
      FD_ZERO(&fd_read);
      FD_ZERO(&fd_write);
      fd_max = 0;
      for (i = 0; i < MAX_FD; i++)
	if (e.fd_type[i] != FD_FREE)
	  {
	    FD_SET(i, &fd_read);
	    FD_SET(i, &fd_write);
	    fd_max = i;
	  }
      if (select(fd_max + 1, &fd_read, &fd_write, NULL, &tv) == -1)
	my_error("select failed", 1);

      for (i = 0; i < MAX_FD; i++)
	if (FD_ISSET(i, &fd_read))
	  e.fct_read[i](&e, i);
      for (i = 0; i < MAX_FD; i++)
	if (FD_ISSET(i, &fd_write))
	  if (e.fct_write != NULL)
	    e.fct_write[i](&e, i);

      printf("Waiting...\n");
      sleep(2);
    }
  return (0);
}
