/*
** part.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 16:40:41 2015 Pierre NOEL
** Last update Wed Apr 15 13:40:14 2015 Pierre NOEL
*/

#include			"server.h"

void				my_part(t_env *e, t_cmd *cmd, t_env *client)
{
  if (client->channels != NULL && e)
    {
      if (have_channel(client, cmd->opt[0]))
	{
	  del_channel(client, cmd->opt[0]);
	  if ((client->return_code = malloc(512)) == NULL)
	    my_error("Malloc failed", 0);
	  if (0 > sprintf(client->return_code, ":%s PART %s%s",
			  client->nickname,
			  cmd->opt[0],
			  RETOUR_C))
	    response_fail(&(client->return_code), client->id);
	}
      else
	if (0 > sprintf(client->return_code, ":%s 442\r\n", client->nickname))
	  response_fail(&(client->return_code), client->id);
    }
}
