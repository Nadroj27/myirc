/*
** client.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sun Mar 29 22:34:24 2015 Pierre NOEL
** Last update Thu Apr 16 11:49:33 2015 Pierre NOEL
*/

#include		"client.h"

static t_client		*init_client(t_client *client)
{
  client = malloc(sizeof(t_client));
  client->nickname = NULL;
  client->channel = NULL;
  return (client);
}

static void		mloop(int sfd)
{
  int			ret;
  char			buffer[4096];
  t_map			*map;
  t_client		*client;

  map = NULL;
  client = NULL;
  client = init_client(client);
  map = init_map(map);
  while (1)
    {
      if (map->hasWrite)
	{
	  if ((ret = read(sfd, buffer, 4096)) == -1)
	    {
	      fprintf(stderr, "Read failed\n");
	      break;
	    }
	  map->hasWrite = 0;
	}
      buffer[ret - 2] = 0;
      check_input(sfd, map, buffer, client);
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
