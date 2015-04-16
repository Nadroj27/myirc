/*
** command.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_client
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 16 10:47:50 2015 Pierre NOEL
** Last update Thu Apr 16 11:54:15 2015 Pierre NOEL
*/

#include		"client.h"

int			command_in_the_map(t_map *this, char **arg, int sfd)
{
  t_map			*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, arg[0]) == 0)
	{
	  this->hasWrite = 1;
	  return (tmp->ptr_fct(arg, sfd));
	}
      tmp = tmp->next;
    }
  printf("Commande non implémentée\n");
  return (1);
}

void			check_command(char *buff, int sfd, t_map *map)
{
  char			**arg;
  char			*tmp;

  if (buff[0] != '/')
    {
      tmp = malloc(sizeof(char) * 512);
      strcat(tmp, buff);
      strcat(tmp, "\r\n");
      write(sfd, tmp, strlen(tmp));
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
      arg = my_str_to_wordtab(buffer, ' ');
      while (map)
	{
	  if (strcmp(map->name, arg[1]) == 0)
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
    fprintf(stderr, "Error return code");
  if ((length = read(0, buff, 4095)) > 0)
    {
      buff[length - 1] = 0;
      check_command(buff, sfd, map);
    }
  buffer[0] = 0;
}
