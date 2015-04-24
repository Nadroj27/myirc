/*
** command.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_client
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 16 10:47:50 2015 Pierre NOEL
** Last update Fri Apr 24 19:21:06 2015 Jérémy MATHON
*/

#include		"client.h"

int			command_in_the_map(t_map *this, char **arg, int sfd)
{
  t_map			*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      printf("this : %s\n", tmp->name);
      printf("mon maillon : %s\n", arg[0]);
      if (strcmp(tmp->name, arg[0]) == 0)
	{
	  this->hasWrite = 1;
	  return (tmp->ptr_fct(arg, sfd));
	}
      tmp = tmp->next;
    }
  textcolor(RED, "Command not implemented", 1);
  return (1);
}

void			check_command(char *buff, int sfd,
				      t_map *map, t_client *client)
{
  char			**arg;
  char			tmp[1024];

  if (buff[0] != '/')
    {
      if (client->channel == NULL)
	textcolor(RED, "You didn't enter a channel yet", 1);
      else
	{
	  cutbuff(buff, 500 - strlen(client->channel));
	  sprintf(tmp, "PRIVMSG %s %s\r\n", client->channel, buff);
	  write(sfd, tmp, strlen(tmp));
	}
    }
  else
    {
      buff++;
      arg = my_str_to_wordtab(buff, ' ');
      command_in_the_map(map, arg, sfd);
    }
}

int			display_info(char *buffer, t_client *client)
{
  char			**arg;
  t_map			*map;

  map = init_return_code();
  if (strlen(buffer) > 0)
    {
      textcolor(YELLOW, buffer, 1);
      arg = my_str_to_wordtab(buffer, ' ');
      while (map)
	{
	  if (strcmp(map->name, arg[0]) == 0)
	    return (map->ptr_fct(arg, client));
	  map = map->next;
	}
    }
  return (0);
}

void			check_input(int sfd, t_map *map,
				    char *buffer,
				    t_client *client)
{
  char			buff[4096];
  int			length;

  if (display_info(buffer, client))
    textcolor(RED, "Error return code unknow", 1);
  if ((length = read(0, buff, 4095)) > 0)
    {
      if (length > 0)
	buff[length - 1] = 0;
      check_command(buff, sfd, map, client);
    }
  buffer[0] = 0;
}
