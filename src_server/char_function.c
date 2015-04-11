/*
** char_function.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:31:41 2015 Pierre NOEL
** Last update Sat Apr 11 15:09:16 2015 Pierre NOEL
*/

#include			"server.h"
#include			<math.h>

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
  tmp = nb;// / 10;
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
