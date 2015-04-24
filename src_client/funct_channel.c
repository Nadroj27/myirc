/*
** funct_channel.c for funct_channel in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Wed Apr  1 13:29:27 2015 Jérémy MATHON
** Last update Fri Apr 24 19:14:17 2015 Jérémy MATHON
*/

#include	"client.h"

int		list_channel(char **argv, int sfd)
{
  if (argv && sfd)
    return (0);
  return (0);
}

int		join_channel(char **argv, int sfd)
{
  char		*tmp;

  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "JOIN ");
  strcat(tmp, argv[1]);
  strcat(tmp, "\r\n");
  write(sfd, tmp, strlen(tmp));
  return (0);
}

int		part_channel(char **argv, int sfd)
{
  if (argv && sfd)
    return (0);
  return (0);
}
