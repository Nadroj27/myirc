/*
** nickname.c for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 14:25:22 2015 Pierre NOEL
** Last update Tue Apr 14 14:51:40 2015 Pierre NOEL
*/

#include			"server.h"

static int			check_use(t_env *e, char *nickname)
{
  t_env*			tmp;

  tmp = e;
  while (tmp)
    {
      if (tmp->fd_type == FD_CLIENT && tmp->nickname != NULL)
	if (strcmp(tmp->nickname, nickname) == 0)
	  return (1);
      tmp = tmp->next;
    }
  return (0);
}

void				my_nickname(t_env *e, t_cmd *cmd, t_env *client)
{
  if (cmd->opt[0] == NULL)
    {
      if ((client->return_code = malloc(512)) == NULL)
	my_error("Malloc failed", 0);
      if (0 > sprintf(client->return_code, ":%s 431\r\n", client->nickname))
	response_fail(&(client->return_code), client->id);
    }
  else if (check_use(e, cmd->opt[0]))
    {
      if ((client->return_code = malloc(512)) == NULL)
	my_error("Malloc failed", 0);
      if (0 > sprintf(client->return_code, ":%s 433\r\n", client->nickname))
	response_fail(&(client->return_code), client->id);
    }
  else
    {
      free(client->nickname);
      client->nickname = strdup(cmd->opt[0]);
    }
}
