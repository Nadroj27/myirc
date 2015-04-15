/*
** client_write.c for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:23:35 2015 Pierre NOEL
** Last update Wed Apr 15 11:05:05 2015 Pierre NOEL
*/

#include			"server.h"

void				client_write(t_env *e, int fd)
{
  t_env				*client;

  client = find_by_id(e, fd);
  if (client->return_code != NULL)
    {
      printf("Write to  client\n");
      printf("info  = %s\n", client->return_code);
      write(fd, client->return_code, strlen(client->return_code));
      free(client->return_code);
      client->return_code = NULL;
    }
}
