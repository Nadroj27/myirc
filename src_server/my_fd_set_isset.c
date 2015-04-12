/*
** my_fd_set_isset.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Fri Apr 10 17:03:14 2015 Pierre NOEL
** Last update Sun Apr 12 19:46:54 2015 Pierre NOEL
*/

#include			"server.h"

int				my_fd_set_list(t_env *e,
					       fd_set *read,
					       fd_set *write)
{
  int				fd_max;
  t_env				*tmp;

  FD_ZERO(read);
  FD_ZERO(write);
  tmp = e;
  fd_max = 1;
  while (tmp)
    {
      if (tmp->fd_type != FD_FREE)
	{
	  FD_SET(tmp->id, read);
	  FD_SET(tmp->id, write);
	  fd_max = tmp->id;
	}
      tmp = tmp->next;
    }
  return (fd_max);
}

void				my_fd_isset_write(t_env *e,
						  fd_set *write)
{
  t_env				*tmp;

  tmp = e;
  while (tmp)
    {
      if (FD_ISSET(tmp->id, write))
	{
	  if (tmp->fct_write != NULL)
	    tmp->fct_write(e, tmp->id);
	}
      tmp = tmp->next;
    }
}

void				my_fd_isset(t_env *e,
					    fd_set *read,
					    fd_set *write)
{
  t_env				*tmp;
  t_env				*opt;

  tmp = e;
  while (tmp)
    {
      opt = tmp->next;
      if (FD_ISSET(tmp->id, read))
	tmp->fct_read(e, tmp->id);
      my_fd_isset_write(e, write);
      tmp = opt;
    }
}
