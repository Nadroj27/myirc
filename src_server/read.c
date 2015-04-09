/*
** read.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Mon Apr  6 14:19:40 2015 Pierre NOEL
** Last update Wed Apr  8 16:31:52 2015 Pierre NOEL
*/

#include			"server.h"

char				*my_realloc_irc(char *str, int size)
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

char				*my_read_irc(int fd)
{
  char				*buff;
  char				c;
  int				i;

  buff = NULL;
  i = 0;
  while (read(fd, &c, 1) > 0)
    {
      buff = my_realloc_irc(buff, 1);
      buff[i] = c;
      buff[i + 1] = 0;
      if (i > 1 && buff[i - 1] == '\r' && buff[i] == '\n')
	{
	  buff[i - 1] = 0;
	  return (buff);
	}
      i++;
    }
  printf("Problème read buffer");
  free(buff);
  return (NULL);
}
