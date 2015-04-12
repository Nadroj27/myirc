/*
** part.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 16:40:41 2015 Pierre NOEL
** Last update Sun Apr 12 15:02:05 2015 Pierre NOEL
*/

#include			"server.h"

void				my_part(t_env *e, t_cmd *cmd, t_env *client)
{
  if (client->channel != NULL && e)
    {
      if (strcmp(client->channel, cmd->opt[0]) == 0)
	{
	  free(client->channel);
	  if ((client->return_code = malloc(512)) == NULL)
	    my_error("Malloc failed", 0);
	  if (0 > sprintf(client->return_code, "PART %s%s",
			  cmd->opt[0],
			  RETOUR_C))
	    my_error_c("Failed to create response", 0);
	}
      else
	client->return_code = strdup("442\r\n");
    }
}
