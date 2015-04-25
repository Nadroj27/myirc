/*
** command.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_client
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 16 10:47:50 2015 Pierre NOEL
** Last update Sat Apr 25 16:47:14 2015 Pierre NOEL
*/

#include		"client.h"

int			command_in_the_map(t_map *this, char **arg,
					   t_client * client)
{
  t_map			*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, arg[0]) == 0)
	return (tmp->ptr_fct(arg, client));
      tmp = tmp->next;
    }
  client->toClient = textcolor(RED, "Command not implemented", 1);
  return (1);
}

void			check_command(char *buff,
				      t_map *map, t_client *client)
{
  char			**arg;
  char			*tmp;

  if (buff[0] != '/')
    {
      if (client->channel == NULL)
	client->toClient = textcolor(RED, "You didn't enter a channel yet", 1);
      else
	{
	  tmp = malloc(512);
	  cutbuff(buff, 500 - strlen(client->channel));
	  sprintf(tmp, "PRIVMSG %s :%s\r\n", client->channel, buff);
	  client->toServer = tmp;
	}
    }
  else
    {
      buff++;
      arg = my_str_to_wordtab(buff, ' ');
      command_in_the_map(map, arg, client);
    }
}

int			display_info(char *buffer,
				     t_client *client,
				     t_map *map)
{
  char			**arg;
  int			i;

  i = 0;
  if (strlen(buffer) > 0)
    {
      client->toClient =  textcolor(YELLOW, buffer, 1);
      arg = my_str_to_wordtab(buffer, ' ');
      while (map)
	{
	  if (strcmp(map->name, arg[0]) == 0)
	    return (map->ptr_fct(arg, client));
	  map = map->next;
	}
    }
  while (arg[i] != NULL)
    free(arg[i++]);
  free(arg);
  return (0);
}

void			check_input(t_map *map,
				    t_client *client)
{
  char			buff[4096];
  int			length;

  if ((length = read(0, buff, 4095)) > 0)
    {
      if (length > 1)
	buff[length - 1] = 0;
      check_command(buff, map, client);
    }
}
