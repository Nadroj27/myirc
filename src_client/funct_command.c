/*
** funct_command.c for funct_command in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Thu Apr  9 16:03:28 2015 Jérémy MATHON
** Last update Thu Apr  9 17:05:32 2015 Jérémy MATHON
*/

#include	"client.h"

char   		*modif_input(char *str)
{
  int		len;
  char		*tmp;

  len = strlen(str);
  tmp = malloc(sizeof(char) * (len + 2));
  strcpy(tmp, str);
  tmp[len] = '\r';
  tmp[len + 1] = '\n';
  tmp[len + 2] = 0;
  return (tmp);
}
