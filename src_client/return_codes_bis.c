/*
** return_codes_bis.c for return_codes_bis in /home/mathon_j/rendu/PSU_2014_myirc
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Sat Apr 25 20:51:16 2015 Jérémy MATHON
** Last update Sat Apr 25 20:53:35 2015 Jérémy MATHON
*/

#include			"client.h"

static char			*getChannel(char *arg)
{
  int				i;
  char				*tmp;

  tmp = malloc(512);
  i = 0;
  while (arg[i] != 0 && arg[i] != '\n' && arg[i] != '\r')
    {
      tmp[i] = arg[i];
      i++;
    }
  tmp[i] = 0;
  return (tmp);
}

int				channel_changed(char **arg,
						t_client *client)
{
  char				command[1024];

  if (arg[1] != NULL)
    {
      if (arg[1][0] == ':')
	arg[1]++;
    if (client->channel != NULL)
	free(client->channel);
      client->channel = getChannel(arg[1]);
      sprintf(command, "You join %s", client->channel);
      client->toClient = xstrcat(client->toClient,
				 textcolor(GREEN, command, 1));
      return (0);
    }
  return (1);
}

int				channel_clean(char **arg,
						t_client *client)
{
  char				command[1024];

  if (arg[1] != NULL)
    {
      if (arg[1][0] == ':')
	arg[1]++;
      sprintf(command, "You quit the channel : %s", arg[1]);
      client->toClient = xstrcat(client->toClient,
				 textcolor(GREEN, command, 1));
      if (client->channel != NULL)
	free(client->channel);
      client->channel = NULL;
      return (0);
    }
  return (1);
}
