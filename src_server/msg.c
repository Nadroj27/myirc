/*
** my_msg.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 16:02:56 2015 Pierre NOEL
** Last update Wed Apr 15 11:08:23 2015 Pierre NOEL
*/

#include			"server.h"

static void			do_for_all_channel(char *message,
						   t_env *e,
						   char *channel,
						   t_env *client)
{
  t_env				*tmp;

  tmp = e;
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT && tmp->channels != NULL)
	if (have_channel(tmp, channel)
	    && strcmp(client->nickname, tmp->nickname) != 0)
	  tmp->return_code = strdup(message);
      tmp = tmp->next;
    }
  free(message);
}

static int			isForChannel(char *channel, t_env *e)
{
  t_env				*tmp;

  tmp = e;
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT && tmp->channels != NULL)
	if (have_channel(tmp, channel))
	  return (1);
      tmp = tmp->next;
    }
  return (0);
}

static t_env			*isForUser(char *channel, t_env *e)
{
  t_env				*tmp;

  tmp = e;
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT && tmp->nickname != NULL)
	if (strcmp(tmp->nickname, channel) == 0)
	  return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void				my_msg(t_env *e, t_cmd *cmd, t_env *client)
{
  char				*message;
  t_env				*tmp;

  message = malloc(strlen(cmd->full_cmd) + strlen(client->nickname) + 5);
  if (message == NULL)
    my_error("Strdup failed", 0);
  if (0 > sprintf(message, ":%s %s\r\n", client->nickname, cmd->full_cmd))
    response_fail(&(message), client->id);
  else
    {
      if (cmd->opt[0] != NULL && isForChannel(cmd->opt[0], e))
	do_for_all_channel(message, e, cmd->opt[0], client);
      else if (cmd->opt[0] != NULL && (tmp  = isForUser(cmd->opt[0], e)))
	tmp->return_code = message;
      else if (client->channel != NULL)
	do_for_all_channel(message, e, client->channel, client);
    }
}
