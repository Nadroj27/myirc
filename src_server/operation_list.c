/*
** operation_list.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Tue Apr 14 15:03:38 2015 Pierre NOEL
** Last update Wed Apr 15 11:07:09 2015 Pierre NOEL
*/

#include			"server.h"

static char			**convert_tochar(t_channel *chan)
{
  char				**result;
  t_channel			*tmp;
  int				i;

  i = 0;
  if ((result = malloc(512 * sizeof(char *))) == NULL)
    my_error("Malloc failed", 0);
  tmp = chan;
  while (tmp)
    {
      result[i] = strdup(tmp->name);
      tmp = tmp->next;
      i++;
    }
  result[i] = NULL;
  return (result);
}

static int			check_is_present(char **result, char *str)
{
  int				i;

  i = 0;
  while (result[i] != NULL)
    {
      if (strcmp(result[i], str) == 0)
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

char		       		**list_canal(t_env *e, char *canal,
					     char **result,
					     char **tmp_ch)
{
  t_env				*tmp;

  tmp = e;
  if ((result = malloc(4096 * sizeof(char*))) == NULL)
    my_error("Malloc failed", 0);
  result[0] = NULL;
  while (tmp)
    {
      if (canal == NULL)
	{
	  tmp_ch = convert_tochar(tmp->channels);
	  concatDoubleChar(tmp_ch, result);
	  free_my_double_char(tmp_ch);
	}
      else
	if (have_channel(tmp, canal))
	  {
	    result[0] = strdup(canal);
	    result[1] = NULL;
	    return (result);
	  }
      tmp = tmp->next;
    }
  result = epur_doublon(result);
  return (result);
}
