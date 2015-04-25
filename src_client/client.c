/*
** client.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sun Mar 29 22:34:24 2015 Pierre NOEL
** Last update Sat Apr 25 20:49:56 2015 Jérémy MATHON
*/

#include		<sys/select.h>
#include		"client.h"

static t_client		*init_client(t_client *client)
{
  client = malloc(sizeof(t_client));
  client->nickname = NULL;
  client->channel = NULL;
  client->toServer = NULL;
  client->toClient = NULL;
  return (client);
}

void			init_fd(fd_set *read, fd_set *write, int sfd)
{
  FD_ZERO(read);
  FD_ZERO(write);
  FD_SET(0, read);
  FD_SET(1, write);
  FD_SET(sfd, read);
  FD_SET(sfd, write);
}

void			init_init(t_client **client, t_map **map, t_map **map2)
{
  *client = init_client(*client);
  *map = init_map(*map);
  *map2 = init_return_code();
  if (map2)
    return ;
}

static void		mloop(int sfd)
{
  t_map			*map = NULL;
  t_client		*client = NULL;
  t_map			*map2 = NULL;
  fd_set		read;
  fd_set		write;

  init_init(&client, &map, &map2);
  while (1)
    {
      init_fd(&read, &write, sfd);
      if (my_select(3, &read, &write) != -1)
	{
	  if (FD_ISSET(0, &read))
	    check_input(map, client);
	  if (FD_ISSET(sfd, &read))
	    read_server(sfd, client, map2);
	  if (FD_ISSET(1, &write))
	    write_client(client);
	  if (FD_ISSET(sfd, &write))
	    write_server(sfd, client);
	}
      else
	fprintf(stderr, "Bad fd");
    }
}

int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			sfd;
  struct sockaddr_in	my_addr;

  if (ac != 3)
      my_error("Usage : ./client [adress] [port]\n", 0);
  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  sfd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (sfd == - 1)
    my_error("Failed to create socket", 1);
  memset(&my_addr, '\0', sizeof(my_addr));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(atoi(av[2]));
  my_addr.sin_addr.s_addr = inet_addr(av[1]);
  if (connect(sfd, (struct sockaddr *) &my_addr,
	      sizeof(my_addr)) ==  - 1)
    my_error("Failed to connect", 1);
  mloop(sfd);
  return (0);
}
