/*
** join.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 15:50:57 2015 Pierre NOEL
** Last update Thu Apr  9 15:23:27 2015 Pierre NOEL
*/

#include			"server.h"

char				*getUser(t_env *e, char *channel, char *h, char *c)
{
  t_env				*tmp;
  char				*info;

  if ((info = malloc(512)) == NULL)
    my_error("Malloc failed", 0);
  info[0] = 0;
  info = xstrcat(info, ":");
  info = xstrcat(info, h);
  info = xstrcat(info, " 353 ");
  info = xstrcat(info, c);
  info = xstrcat(info, " ");
  info = xstrcat(info, channel);
  tmp = e;
  while (tmp)
    {
      if (tmp->channel != NULL)
	if (strcmp(tmp->channel, channel) == 0)
	  {
	    info = xstrcat(info, " :@");
	    info = xstrcat(info, tmp->nickname);
	  }
      tmp = tmp->next;
    }
  info = xstrcat(info, "\r\n");
  return (info);
}

char				*getEnd(char *n, char *c, char *h)
{
  char				*info;

  if ((info = malloc(31 + strlen(n) + strlen(c) + strlen(h))) == NULL)
    my_error("Failed Malloc", 0);
  info[0] = 0;
  info = xstrcat(info, ":");
  info = xstrcat(info, h);
  info = xstrcat(info, " 366 ");
  info = xstrcat(info, n);
  info = xstrcat(info, " ");
  info = xstrcat(info, c);
  info = xstrcat(info, " ::End of /NAMES list\r\n");
  return (info);
}


void				my_join(t_env *e, t_cmd *cmd, t_env *client)
{
  if (e)
    {
      if (cmd->opt[0] == NULL)
	client->return_code = strdup("461\r\n");
      else
	{
	  if ((client->return_code = malloc(1024)) == NULL)
	    my_error("Malloc failed", 0);
	  client->return_code[0] = 0;
	  if (client->channel != NULL)
	    free(client->channel);
	  client->channel = strdup(cmd->opt[0]);
	  if (0 > sprintf(client->return_code, "JOIN %s\r\n%s%s",
			  cmd->opt[0],
			  getUser(e, cmd->opt[0], "127.0.0.1", client->nickname),
			  getEnd(client->nickname, cmd->opt[0],"127.0.0.1")))
	    my_error("Failed to create response", 0);

	  printf("%s\n", client->return_code);
	  sleep(1);
	  /*
	    sprintf(client->return_code,
	    "JOIN :%s\r\n:127.0.0.1 353 %s = %s :@%s\r\n
	    :127.0.0.1 366 %s %s :End of /NAMES list\r\n",
	    cmd->opt[0],
	    client->nickname,
	    cmd->opt[0],
	    client->nickname,
	    client->nickname,
	    cmd->opt[0]);
	    }*/
	}
    }
}
