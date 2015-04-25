/*
** funct_channel.c for funct_channel in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Wed Apr  1 13:29:27 2015 Jérémy MATHON
** Last update Sat Apr 25 16:40:41 2015 Pierre NOEL
*/

#include	"client.h"

int		list_channel(char **argv, t_client *client)
{
  char		*tmp;

  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "LIST ");
  strcat(tmp, argv[1]);
  strcat(tmp, "\r\n");
  client->toServer = tmp;
  return (0);
}

int		join_channel(char **argv, t_client *client)
{
  char		*tmp;

  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "JOIN ");
  strcat(tmp, argv[1]);
  strcat(tmp, "\r\n");
  client->toServer = tmp;
  return (0);
}

int		part_channel(char **argv, t_client *client)
{
  char		*tmp;

  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "PART ");
  strcat(tmp, argv[1]);
  strcat(tmp, "\r\n");
  client->toServer = tmp;
  return (0);
}
