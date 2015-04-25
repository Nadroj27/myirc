/*
** write_server.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sat Apr 25 15:08:39 2015 Pierre NOEL
** Last update Sat Apr 25 16:05:10 2015 Pierre NOEL
*/

#include			"client.h"

void				write_server(int sfd,
					     t_client *client)
{
  int				ret;

  if (client->toServer != NULL)
    {
      ret = write(sfd, client->toServer, strlen(client->toServer));
      if (ret == -1)
	fprintf(stderr, "Failed to write");
      free(client->toServer);
      client->toServer = NULL;
    }
}
