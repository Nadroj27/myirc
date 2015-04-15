/*
** funct_user.c for funct_user in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Wed Apr  1 13:01:44 2015 Jérémy MATHON
** Last update Wed Apr 15 15:16:30 2015 Jérémy MATHON
*/

#include	"client.h"

int		connection_server(char **argv, int sfd)
{
  (void)argv;
  (void)sfd;
  return (0);
}

int		msg_user(char **argv, int sfd)
{
  return (0);
}

int		change_nickname(char **argv, int sfd)
{
  int		i;
  char		*tmp;

  i = 1;
  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "NICK ");
  strcat(tmp, argv[1]);
  strcat(tmp, "\r\n");
  write(sfd, tmp, strlen(tmp));
  return (0);
}

int		list_user(char **argv, int sfd)
{
  return (0);
}
