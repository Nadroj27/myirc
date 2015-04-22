/*
** read.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Mon Apr  6 14:19:40 2015 Pierre NOEL
** Last update Wed Apr 22 16:47:36 2015 Pierre NOEL
*/

#include			"server.h"

static char	       		*my_realloc_irc(char *str, int size)
{
  char				*tmp;
  int				size_base;

  size_base = size + 2;
  tmp = NULL;
  if (str != NULL)
    {
      if ((tmp = strdup(str)) == NULL)
	my_error("Strdup failed", 0);
      size_base += strlen(str);
    }
  str = realloc(str, size_base);
  if (str == NULL)
    my_error("Strdup failed", 0);
  if (tmp != NULL)
    str = strcpy(str, tmp);
  else
    str[0] = 0;
  return (str);
}

static char			*return_final(char **buffer_client,
					      int i)
{
  char				*buffer;

  (*buffer_client)[i] = 0;
  buffer = strdup(*buffer_client);
  free(*buffer_client);
  *buffer_client = NULL;
  return (buffer);
}

char				*my_read_irc(int fd, t_env *client)
{
  char				c;
  int				i;
  char				*table;
  int				ret;

  table = malloc(1);
  table[0] = 0;
  i = 0;
  c = 0;
  while ((ret = read(fd, &c, 1)) >= 0)
    {
      if (ret == 0)
	return (table);
      client->buffer = my_realloc_irc(client->buffer, 1);
      client->buffer[i] = c;
      client->buffer[i + 1] = 0;
      if (client->buffer[i] == '\n')
	return (return_final(&client->buffer, i));
      if (c != 0)
	{
	  i++;
	  c = 0;
	}
    }
  return (NULL);
}
