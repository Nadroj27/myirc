/*
** funct_user.c for funct_user in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Wed Apr  1 13:01:44 2015 Jérémy MATHON
** Last update Thu Apr 16 10:47:04 2015 Pierre NOEL
*/

#include	"client.h"

int		connection_server(char **argv, int sfd)
{
  if (argv && sfd)
    return (0);
  return (0);
}

int		msg_user(char **argv, int sfd)
{
  if (argv && sfd)
    return (0);
  return (0);
}

int		change_nickname(char **argv, int sfd)
{
  char		*tmp;

  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "NICK ");
  strcat(tmp, argv[1]);
  strcat(tmp, "\r\n");
  write(sfd, tmp, strlen(tmp));
  return (0);
}

int		list_user(char **argv, int sfd)
{
  if (argv && sfd)
    return (0);
  return (0);
}
