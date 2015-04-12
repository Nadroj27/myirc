/*
** event_client.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Mon Apr  6 18:17:47 2015 Pierre NOEL
** Last update Sun Apr 12 18:57:44 2015 Pierre NOEL
*/

#include			"server.h"

t_env				*add_event(t_env *a, fct2 fct_read,
					   fct fct_write, int port)
{
  t_env				*result;
  t_env				*tmp;

  tmp = a;
  while (tmp->next)
    tmp = tmp->next;
  result = malloc(sizeof(t_env));
  if (result == NULL)
    my_error("Failed to malloc", 0);
  result->fct_read = fct_read;
  result->fct_write = fct_write;
  result->port = port;
  result->next = NULL;
  tmp->next = result;
  return (result);
}

t_env				*find_by_id(t_env *a, int id)
{
  t_env				*tmp;

  tmp = a;
  while (tmp)
    {
      if (tmp->id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void				dump(t_env *e)
{
  t_env				*tmp;

  tmp = e;
  while (tmp)
    {
      printf("id = %d\n", tmp->id);
      printf("fd_type = %d\n", tmp->fd_type);
      printf("port = %d\n", tmp->port);
      tmp = tmp->next;
    }
}
