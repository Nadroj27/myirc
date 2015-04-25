/*
** write_client.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sat Apr 25 15:11:29 2015 Pierre NOEL
** Last update Sat Apr 25 20:50:42 2015 Jérémy MATHON
*/

#include			"client.h"

void				write_client(t_client *client)
{
  if (client->toClient != NULL)
    {
      write(1, client->toClient, strlen(client->toClient));
      free(client->toClient);
      client->toClient = NULL;
    }
}
