/*
** operation_list.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Tue Apr 14 15:03:38 2015 Pierre NOEL
** Last update Tue Apr 14 15:35:41 2015 Pierre NOEL
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

static char			**is_like_list(t_channel *channels,
					     char *pattern)
{
  t_channel			*tmp;
  char				**result;
  int				i;

  i = 0;
  if ((result = malloc(512 * sizeof(char *))) == NULL)
    my_error("Failed to Malloc", 0);
  result[0] = NULL;
  tmp  = channels;
  while (tmp)
    {
      if (pattern != NULL)
	{
	  if (is_like(tmp->name, pattern) == 1)
	    result[i++] = strdup(tmp->name);
	}
      else
	result[i++] = strdup(tmp->name);
      tmp = tmp->next;
    }
  result[i] = NULL;
  return (result);
}

static int			check_is_present(char **channels, char *tolook)
{
  int				i;

  i = 0;
  while (channels[i] != NULL)
    {
      if (strcmp(channels[i], tolook) == 0)
	return (1);
      i++;
    }
  return (0);
}

static char			**epur_doublon(char **chanels)
{
  char				**result;
  int				i;
  int				j;

  j = 0;
  i = 0;
  if ((result = malloc(512 * sizeof(char*))) == NULL)
    my_error("Malloc failed", 0);
  result[0] = NULL;
  while (chanels[i] != NULL)
    {
      if (!check_is_present(result, chanels[i]))
	{
	  result[j++] = strdup(chanels[i]);
	  result[j] = NULL;
	}
      i++;
    }
  free_my_double_char(chanels);
  return (result);
}

char		       		**list_canal(t_env *e, char *canal)
{
  t_env				*tmp;
  char				**result;
  char				**tmp_ch;

  tmp = e;
  if ((result = malloc(4096 * sizeof(char*))) == NULL)
    my_error("Malloc failed", 0);
  result[0] = NULL;
  while (tmp)
    {
      if (tmp->channels != NULL)
	{
	  tmp_ch = is_like_list(tmp->channels, canal);
	  concatDoubleChar(tmp_ch, result);
	  free_my_double_char(tmp_ch);
	}
      tmp = tmp->next;
    }
  result = epur_doublon(result);
  return (result);
}
