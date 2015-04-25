/*
** write_client.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sat Apr 25 15:11:29 2015 Pierre NOEL
** Last update Sat Apr 25 16:02:01 2015 Pierre NOEL
*/

#include			"client.h"

void				write_client(t_client *client)
{
  //  printf("on va écrire client");
  if (client->toClient != NULL)
    {
      write(1, client->toClient, strlen(client->toClient));
      free(client->toClient);
      client->toClient = NULL;
    }
}
