/*
** return_codes.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 16 10:56:09 2015 Pierre NOEL
** Last update Thu Apr 23 11:23:02 2015 Pierre NOEL
*/

#include			"client.h"

int				nickname_changed(char **arg,
						 t_client *client)
{
  char				command[1024];

  if (arg[1] != NULL)
    {
      if (arg[1][0] == ':')
	arg[1]++;
      sprintf(command, "Nickname changed into %s", arg[1]);
      textcolor(GREEN, command, 1);
      if (client->nickname != NULL)
	free(client->nickname);
      client->nickname = strdup(arg[1]);
      return (0);
    }
  return (1);
}

int				server_connected(char **arg,
						 t_client *client)
{
  textcolor(GREEN, "Connexion success", 1);
  if (client && arg)
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
