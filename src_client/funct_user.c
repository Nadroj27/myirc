/*
** funct_user.c for funct_user in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Wed Apr  1 13:01:44 2015 Jérémy MATHON
** Last update Tue Apr 28 16:22:52 2015 Pierre NOEL
*/

#include	"client.h"

int		connection_server(char **argv, t_client * client)
{
  if (argv && client)
    return (0);
  return (0);
}

int		msg_user(char **argv, t_client * client)
{
  char		*tmp;
  int		i;

  i = 2;
  if (argv[0] != 0 && argv[1] != NULL)
    {
      tmp = malloc(sizeof(char) * 512);
      strcpy(tmp, "PRIVMSG ");
      strcat(tmp, argv[1]);
      strcat(tmp, " ");
      while (argv[i] != NULL)
	{
	  strcat(tmp, argv[i]);
	  strcat(tmp, " ");
	  i++;
	}
      strcat(tmp, "\r\n");
      client->toServer = tmp;
    }
  else
    client->toClient = textcolor(RED, "You need more argument", 1);
  return (0);
}

int		change_nickname(char **argv, t_client *client)
{
  char		*tmp;

  if (argv[1] != NULL)
    {
      tmp = malloc(sizeof(char) * 512);
      strcpy(tmp, "NICK ");
      strcat(tmp, argv[1]);
      strcat(tmp, "\r\n");
      client->toServer = tmp;
    }
  else
    client->toClient = textcolor(RED, "You need more argument", 1);
  return (0);
}

int		list_user(char **argv, t_client * client)
{
  char		*tmp;

  if (client->channel != NULL)
    {
      tmp = malloc(sizeof(char) * 512);
      strcpy(tmp, "NAMES ");
      strcat(tmp, client->channel);
      strcat(tmp, "\r\n");
      client->toServer = tmp;
    }
  else
    client->toClient = textcolor(RED, "You are not in a channel yet", 1);
  if (argv[1] != NULL)
    client->toClient = textcolor(RED, "You do not need more argument", 1);
  return (0);
}
