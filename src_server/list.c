/*
** list.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 14:51:24 2015 Pierre NOEL
** Last update Wed Apr  8 15:54:58 2015 Pierre NOEL
*/

#include			"server.h"

static int			is_like(char *str, char *pattern)
{
  int				i;

  i = 0;
  while (str[i] != 0)
    {
      if (strlen(str) - i >= strlen(pattern))
	if (strncmp(str + i, pattern, strlen(pattern)) == 0)
	  return (1);
      i++;
    }
  return (0);
}

char		       		**list_canal(t_env *e, char *canal, int i)
{
  t_env				*tmp;
  char				**result;

  if ((result = malloc(4096 * sizeof(char*))) == NULL)
    my_error("Malloc failed", 0);
  while (tmp)
    {
      if (canal != NULL)
	{
	  if (is_like(tmp->channel, canal))
	    {
	      result[i] = strdup(tmp->channel);
	      i++;
	    }
	}
      else
	{
	  result[i] = strdup(tmp->channel);
	  i++;
	}
      tmp = tmp->next;
    }
  result[i] = NULL;
  return (result);
}

void				my_list(t_env *e, t_cmd *cmd, t_env *client)
{

}
