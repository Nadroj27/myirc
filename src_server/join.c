/*
** join.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 15:50:57 2015 Pierre NOEL
** Last update Wed Apr  8 16:23:28 2015 Pierre NOEL
*/

#include			"server.h"

void				my_join(t_env *e, t_cmd *cmd, t_env *client)
{
  if (e)
    {
      if (cmd->opt[0] == NULL)
	client->return_code = strdup("461\r\n");
      else
	{
	  if (client->channel != NULL)
	    free(client->channel);
	  client->channel = strdup(cmd->opt[0]);
	  client->return_code = strdup("303\r\n");
	}
    }
}
