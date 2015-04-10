/*
** my_msg.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 16:02:56 2015 Pierre NOEL
** Last update Thu Apr  9 16:06:47 2015 Pierre NOEL
*/

#include			"server.h"

void				do_for_all_channel(char *message, t_env *e, char *channel)
{
  t_env				*tmp;

  tmp = e;
  while (tmp)
    {
      if (tmp->channel != NULL)
	if (strcmp(tmp->channel, channel) == 0)
	  tmp->return_code = strdup(message);
      tmp = tmp->next;
    }
}

void				my_msg(t_env *e, t_cmd *cmd, t_env *client)
{
  char				*message;

  message = malloc(strlen(cmd->full_cmd) + 3);
  if (message == NULL)
    my_error("Strdup failed", 0);
  message = strcpy(message, cmd->full_cmd);
  message = xstrcat(message, "\r\n");
  client->return_code = message;
  do_for_all_channel(message, e, client->channel);
}
