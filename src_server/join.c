/*
** join.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 15:50:57 2015 Pierre NOEL
** Last update Wed Apr 22 15:52:47 2015 Pierre NOEL
*/

#include			"server.h"

static char			*getUsr(t_env *e,
					char *channel,
					char *c)
{
  t_env				*tmp;
  char				*info;

  if ((info = malloc(512)) == NULL)
    my_error("Malloc failed", 0);
  info[0] = 0;
  if (0 > sprintf(info, "353 %s = %s :",
		  c, channel))
    return (NULL);
  tmp = e;
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT && tmp->channels != NULL)
	{
	  if (have_channel(tmp, channel))
	    {
	      info = xstrcat(info, " @");
	      info = xstrcat(info, tmp->nickname);
	    }
	}
      tmp = tmp->next;
    }
  info = xstrcat(info, RETOUR_C);
  return (info);
}

static char			*getEnd(char *n, char *c)
{
  char				*info;

  if ((info = malloc(35 + 2 * strlen(n) + strlen(c))) == NULL)
    my_error("Failed Malloc", 0);
  if (0 > sprintf(info, "366 %s %s :End of /NAMES list\r\n", n, c))
    {
      response_fail(&(info), -1);
      return (NULL);
    }
  return (info);
}

void				my_join(t_env *e,
					t_cmd *cmd,
					t_env *client)
{
  if (e)
    {
      if ((client->return_code = malloc(512)) == NULL)
	    my_error("Malloc failed", 0);
      if (cmd->opt[0] == NULL)
	{
	  if (0 > sprintf(client->return_code, "461\r\n"))
	    response_fail(&(client->return_code), client->id);
	}
      else
	{
	  if (!have_channel(client, cmd->opt[0]))
	    add_channel(client, cmd->opt[0]);
	  if (0 > sprintf(client->return_code, "JOIN %s%s%s%s",
			  cmd->opt[0],
			  RETOUR_C,
			  getUsr(e, cmd->opt[0], client->nickname),
			  getEnd(client->nickname, cmd->opt[0])))
	    response_fail(&(client->return_code), client->id);
	}
    }
}
