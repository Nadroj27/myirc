/*
** channel.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Tue Apr 14 13:29:49 2015 Pierre NOEL
** Last update Tue Apr 14 14:19:03 2015 Pierre NOEL
*/

#include			"server.h"

void				add_channel(t_env *client, char *channel)
{
  t_channel			*tmp;
  t_channel			*new;

  tmp = client->channels;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if ((new = malloc(sizeof(t_channel))) == NULL)
    my_error("Malloc failed", 0);
  new->name = strdup(channel);
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    client->channels = new;
}

int				have_channel(t_env *client, char  *channel)
{
  t_channel			*tmp;

  tmp = client->channels;
  while (tmp)
    {
      if (strcmp(tmp->name, channel) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int				del_channel(t_env *client, char *channel)
{
  t_channel			*tmp;
  t_channel			*old;

  tmp = client->channels;
  old = NULL;
  while (tmp)
    {
      if (strcmp(tmp->name, channel) == 0)
	{
	  free(tmp->name);
	  if (old)
	    old->next = tmp->next;
	  else
	    client->channels = tmp->next;
	  free(tmp);
	  return (0);
	}
      old = tmp;
      tmp = tmp->next;
    }
  return (1);
}
