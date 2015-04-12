/*
** client_read.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:26:03 2015 Pierre NOEL
** Last update Sun Apr 12 13:59:17 2015 Pierre NOEL
*/

#include			"server.h"

static void	       		free_cmd(t_cmd *cmd, char *msg)
{
  int				i;

  i = 0;
  if (msg != NULL)
    free(msg);
  if (cmd->full_cmd != NULL)
    free(cmd->full_cmd);
  if (cmd->prefix != NULL)
    free(cmd->prefix);
  if (cmd->cmd != NULL)
    free(cmd->cmd);
  while (i < 16)
    {
      if (cmd->opt[i] != NULL)
	free(cmd->opt[i]);
      i++;
    }
  free(cmd);
}

static int			delete_client(t_env *e, t_env *client)
{
  t_env				*tmp;
  if (client->channel != NULL)
    free(client->channel);
  if (client->nickname != NULL)
    free(client->nickname);
  if (client->pseudo != NULL)
    free(client->pseudo);
  if (client->real_name != NULL)
    free(client->real_name);
  /* if (client->host != NULL)
    free(client->host);
  if (client->host_name != NULL)
    free(client->host_name);
  if (client->return_code != NULL)
  free(client->return_code);*/
  tmp = e;
  while (tmp)
    {
      if (tmp->next != NULL && tmp->next == client)
	{
	  tmp->next = client->next;
	  free(client);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}

void				client_read(t_env *e, int fd)
{
  char				*msg;
  t_cmd				*cmd;
  t_env				*client;

  client = find_by_id(e, fd);
  msg = my_read_irc(fd);
  if (msg == NULL || strlen(msg) < 1)
    {
      printf("%d: Connection closed\n", fd);
      if (msg != NULL)
	free(msg);
      close(fd);
      delete_client(e, client);
    }
  else
    {
      printf("Client %d: %s\n", fd, msg);
      cmd = check_command(msg, 0, 1);
      choose_cmd(e, cmd, client);
      free_cmd(cmd, msg);
    }
}
