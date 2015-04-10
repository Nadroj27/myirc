/*
** char_function.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:31:41 2015 Pierre NOEL
** Last update Fri Apr 10 16:56:48 2015 Pierre NOEL
*/

#include			"server.h"
#include			<math.h>
/*
static void			function_usual(unsigned int i,
					       unsigned int nb,
					       char *str,
					       unsigned int j)
{
  str[j] = (nb / ((int)pow(10, i))) + '0';
  str[j + 1] = 0;
  if (i > 1)
    function_usual(i - 1, nb / ((int)pow(10, i)), str, j + 1);
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
  tmp = nb / 10;
  while (tmp)
    {
      i++;
      tmp /= 10;
    }
  tmp = 0;
  function_usual(i, nb, result, tmp);
  return (result);
}
*/
char				*append_two(char *str, char *str2)
{
  char				*result;

  result = malloc(strlen(str) + strlen(str2));
  if (result == NULL)
    my_error("Malloc failed", 0);
  result[0] = 0;
  result = strcat(result, str);
  result = strcat(result, str2);
  return (result);
}
