/*
** return_codes.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 16 10:56:09 2015 Pierre NOEL
** Last update Thu Apr 16 11:57:07 2015 Pierre NOEL
*/

#include			"client.h"

int				nickname_changed(char **arg,
						 t_client *client)
{
  if (arg[2] != NULL)
    {
      if (arg[2][0] == ':')
	arg[2]++;
      printf("Nickname changed into %s\n", arg[2]);
      if (client->nickname != NULL)
	free(client->nickname);
      client->nickname = strdup(arg[2]);
      return (0);
    }
  return (1);
}

int				server_connected(char **arg,
						 t_client *client)
{
  int				i;

  i = 1;
  printf("Connexion success\n");
  while (arg[i] != NULL)
    {
      printf("%s ", arg[i]);
      i++;
    }
  printf("\n");
  client->nickname = NULL;
  client->channel = NULL;
  return (0);
}

t_map				*init_return_code()
{
  t_map				*map;

  map = NULL;
  map = add_element2(map, "NICK", nickname_changed);
  map = add_element2(map, "001", server_connected);
  return (map);
}
