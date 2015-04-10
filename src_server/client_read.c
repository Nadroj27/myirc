/*
** client_read.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:26:03 2015 Pierre NOEL
** Last update Fri Apr 10 16:30:16 2015 Pierre NOEL
*/

#include			"server.h"

void				free_cmd(t_cmd *cmd, char *msg)
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
      close(fd);
      client->fd_type = FD_FREE;
    }
  else
    {
      printf("Client %d: %s\n", fd, msg);
      cmd = check_command(msg, 0, 1);
      choose_cmd(e, cmd, client);
    }
  free_cmd(cmd, msg);
}
