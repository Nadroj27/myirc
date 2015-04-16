/*
** add_client.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 16:30:37 2015 Pierre NOEL
** Last update Thu Apr 16 13:03:28 2015 Pierre NOEL
*/

#include			"server.h"

static void			getResponse(t_env *a)
{
  a->return_code = malloc(512);
  if (a->return_code == NULL)
    my_error("Malloc failed", 0);
  if (0 > sprintf(a->return_code, ":%s 001 %s:%s 002 %s:%s 003 %s:%s 004 %s",
		  a->nickname,
		  ":Welcome to this IRC\r\n",
		  a->nickname,
		  ":Your host is serv_irc, running version 1.1\r\n",
		  a->nickname,
		  ":This server was created april, 16th 2015\r\n",
		  a->nickname,
		  ":localhost 1.1 u|o 0|1\r\n"))
    response_fail(&(a->return_code), a->id);
}

void				add_client(t_env *e, int s)
{
  int				cs;
  struct sockaddr_in		client_sin;
  socklen_t			client_sin_len;
  t_env				*a;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  if (cs == -1)
    my_error_c("Failed to accept", 1);
  else
    {
      a = add_event(e, client_read, client_write, ntohs(client_sin.sin_port));
      a->fd_type = FD_CLIENT;
      a->id = cs;
      a->channel = NULL;
      a->nickname = append_two("Anonymous-", uint_to_char((unsigned int)cs));
      a->pseudo = append_two("Anonymous-", uint_to_char((unsigned int)cs));
      a->host = inet_ntoa(client_sin.sin_addr);
      a->host_name = NULL;
      a->next = NULL;
      a->channels = NULL;
      getResponse(a);
    }
}
