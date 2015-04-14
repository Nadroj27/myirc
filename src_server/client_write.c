/*
** client_write.c for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:23:35 2015 Pierre NOEL
** Last update Tue Apr 14 14:22:34 2015 Pierre NOEL
*/

#include			"server.h"

void				client_write(t_env *e, int fd)
{
  t_env				*client;
  //  char				*info;

  client = find_by_id(e, fd);
  if (client->return_code != NULL)
    {
      printf("Write to  client\n");
      /*if ((info = malloc(512)) == NULL)
	my_error("Malloc Failed", 0);*/
      /*sprintf(info, ":%s!%s@%s %s",
	      client->nickname,
	      client->pseudo,
	      client->host,
	      client->return_code);*/
      //sprintf(info, ":%s %s", client->nickname, client->return_code);
      printf("info  = %s\n", client->return_code);
      write(fd, client->return_code, strlen(client->return_code));
      free(client->return_code);
      //free(info);
      client->return_code = NULL;
    }
}
