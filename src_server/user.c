/*
** user.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 17:26:40 2015 Pierre NOEL
** Last update Wed Apr 15 09:36:35 2015 Pierre NOEL
*/

#include			"server.h"

void				my_user(t_env *e, t_cmd *cmd, t_env *client)
{
  if (e && cmd && client)
    {
      client->return_code = malloc(512);
      if (client->return_code == NULL)
	my_error("Malloc failed", 0);
      if (cmd->opt[0] != NULL && cmd->opt[1] != NULL && cmd->opt[2]
	  && cmd->opt[3] != NULL)
	{
	  client->pseudo = strdup(cmd->opt[0]);
	  client->host = strdup(cmd->opt[1]);
	  client->host_name = strdup(cmd->opt[2]);
	  client->real_name = strdup(cmd->opt[3]);
	  if (0 > sprintf(client->return_code, ":%s 300\r\n", client->nickname))
	    response_fail(&(client->return_code), client->id);
	}
      else
	if (0 > sprintf(client->return_code, ":%s 461\r\n", client->nickname))
	  response_fail(&(client->return_code), client->id);
    }
}
