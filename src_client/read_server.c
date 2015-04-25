/*
** read_server.c for irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sat Apr 25 14:59:14 2015 Pierre NOEL
** Last update Sat Apr 25 16:39:56 2015 Pierre NOEL
*/

#include			"client.h"

void				read_server(int sfd,
					    t_client *client,
					    t_map *map)
{
  char			buffer[4096];
  int			ret;

  if ((ret = read(sfd, buffer, 4096)) == -1)
    fprintf(stderr, "Read failed\n");
  else
    {
      buffer[ret - 2] = 0;
      if (display_info(buffer, client, map))
	client->toClient = xstrcat(client->toClient,
				   textcolor(RED, "code unknow", 1));
    }
}
