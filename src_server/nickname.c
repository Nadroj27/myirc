/*
** nickname.c for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 14:25:22 2015 Pierre NOEL
** Last update Fri Apr 10 14:57:39 2015 Pierre NOEL
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

  //Vérifier que le nickname n'est pas déjà utilisé
  // 433 : NICKNAMEINUSE
  // 432 : NICKNAME INVALID
  // 431 : PAS DE NICK (juste NICK)

void				my_nickname(t_env *e, t_cmd *cmd, t_env *client)
{
  if (cmd->opt[0] == NULL)
    client->return_code = strdup("431\r\n");
  /*else if () // valid
    client->return_code = strdup("432\r\n");*/
  else if (check_use(e, cmd->opt[0]))
    client->return_code = strdup("433\r\n");
  else
    {
      //client->return_code = strdup("300\r\n");
      free(client->nickname);
      client->nickname = strdup(cmd->opt[0]);
      //client->nickname = NULL;
    }
}
