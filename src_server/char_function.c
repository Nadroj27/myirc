/*
** char_function.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:31:41 2015 Pierre NOEL
** Last update Tue Apr 14 15:28:29 2015 Pierre NOEL
*/

#include			<math.h>
#include			"server.h"

static void			function_usual(unsigned int i,
					       unsigned int nb,
					       char *str,
					       unsigned int j)
{
  unsigned int			tmp;
  unsigned int			tmp2;
  unsigned int			power;

  power = ((unsigned int)pow(10, i));
  if (power > 0)
    {
      tmp = nb / power;
      tmp2 = nb % power;
      str[j] = tmp + '0';
      str[j + 1] = 0;
      if (i >= 1)
	function_usual(i - 1, tmp2, str, j + 1);
    }
}

char				*uint_to_char(unsigned int nb)
{
  unsigned int	       		i;
  char				*result;
  unsigned int			tmp;

  if ((result = malloc(10)) == NULL)
    {
      fprintf(stderr, "Malloc failed");
      return (NULL);
    }
  i = 0;
  tmp = nb;
  while (tmp)
    {
      i++;
      tmp /= 10;
    }
  function_usual(i - 1, nb, result, 0);
  return (result);
}

char				*append_two(char *str, char *str2)
{
  char				*result;

  result = malloc(strlen(str) + strlen(str2) + 1);
  if (result == NULL)
    my_error("Malloc failed", 0);
  result[0] = 0;
  result = strcat(result, str);
  result = strcat(result, str2);
  return (result);
}

char				**concatDoubleChar(char **src, char **dest)
{
  int				i;
  int				j;

  i = 0;
  j = 0;
  while (dest[i] != NULL)
    i++;
  while (src[j] != NULL)
    {
      dest[i] = strdup(src[j]);
      i++;
      j++;
    }
  dest[i] = NULL;
  return (dest);
}

void				free_my_double_char(char **str)
{
  int				i;

  i = 0;
  while (str[i] != NULL)
    {
      free(str[i]);
      i++;
    }
  free(str);
}
