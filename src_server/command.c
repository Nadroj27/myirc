/*
** command.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Mon Apr  6 15:00:33 2015 Pierre NOEL
** Last update Mon Apr  6 18:50:51 2015 Pierre NOEL
*/

#include			"server.h"

static int			have_prefix(char *str)
{
  int				i;

  i = 0;
  while (str[i] != 0 && str[i] != ':')
    {
      if (str[i] != ':' && str[i] != ' ')
	return (0);
      i++;
    }
  if (str[i] == 0)
    return (0);
  return (1);
}

static char			*return_n_word(char *str, int j)
{
  if (j == 0)
    {
      free(str);
      return (NULL);
    }
  str[j] = 0;
  return (str);
}

static char			*get_n_word(char *str, int n, int i, int j)
{
  char				*result;
  int				n_word;

  n_word = 1;
  if ((result = malloc(4096)) == NULL)
    my_error("Malloc failed", 0);
  while (str[i] != 0 && n_word <= n)
    {
      if (str[i] == ' ')
	{
	  while (str[i + 1] != 0 && str[i + 1] == ' ')
	    i++;
	  n_word++;
	}
      else
	if (n == n_word)
	  result[j++] = str[i];
      i++;
    }
  return (return_n_word(result, j));
}

t_cmd				*check_command(char *str, int j, int n)
{
  t_cmd				*result;
  char				*tmp;

  if ((result = malloc(sizeof(t_cmd))) == NULL)
    my_error("FAiled to malloc", 0);
  result->prefix = NULL;
  result->cmd = NULL;
  if (have_prefix(str))
    {
      result->prefix = get_n_word(str, n, 0, 0);
      n++;
    }
  result->cmd = get_n_word(str, n, 0, 0);
  n++;
  while ((tmp = get_n_word(str, n, 0, 0)) != NULL && j < 15)
    {
      result->opt[j] = strdup(tmp);
      j++;
      n++;
      free(tmp);
    }
  result->opt[j] = NULL;
  return (result);
}
