/*
** join.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 15:50:57 2015 Pierre NOEL
** Last update Sun Apr 12 19:43:28 2015 Pierre NOEL
*/

#include			"server.h"

char				*getUser(t_env *e,
					 char *channel,
					 char *h,
					 char *c)
{
  t_env				*tmp;
  char				*info;

  if ((info = malloc(512)) == NULL)
    my_error("Malloc failed", 0);
  info[0] = 0;
  if (0 > sprintf(info, ":%s 353 %s = %s",
		  h, c, channel))
    my_error_c("Unable to make response");
  tmp = e;
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT && tmp->channel != NULL)
	{
	  if (strcmp(tmp->channel, channel) == 0)
	    {
	      info = xstrcat(info, " :@");
	      info = xstrcat(info, tmp->nickname);
	    }
	}
      tmp = tmp->next;
    }
  info = xstrcat(info, RETOUR_C);
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
  info = xstrcat(info, " :End of /NAMES list");
  info = xstrcat(info, RETOUR_C);
  return (info);
}

void				my_join(t_env *e,
					t_cmd *cmd,
					t_env *client)
{
  if (e)
    {
      if (cmd->opt[0] == NULL)
	client->return_code = strdup("461\r\n");
      else
	{
	  if ((client->return_code = malloc(1024)) == NULL)
	    my_error("Malloc failed", 0);
	  if (client->channel != NULL)
	    free(client->channel);
	  client->channel = strdup(cmd->opt[0]);
	  if (0 > sprintf(client->return_code, "JOIN %s%s%s%s",
			  cmd->opt[0],
			  RETOUR_C,
			  getUser(e, cmd->opt[0], "127.0.0.1", client->nickname),
			  getEnd(client->nickname, cmd->opt[0],"127.0.0.1")))
	    my_error_c("Failed to create response", 0);
	}
    }
}
