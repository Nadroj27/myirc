/*
** command_make.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Mon Apr  6 15:57:25 2015 Pierre NOEL
** Last update Thu Apr  9 15:29:40 2015 Pierre NOEL
*/

#include			"server.h"

void				add_list_function(t_list_cmd **a,
						  const char *name,
						  void (*fct)(t_env *, t_cmd *, t_env *))
{
  t_list_cmd			*result;
  t_list_cmd			*tmp;

  if (a != NULL && *a != NULL)
    {
      tmp = *a;
      while (tmp->next)
	tmp = tmp->next;
    }
  result = malloc(sizeof(t_list_cmd));
  if (result == NULL)
    my_error("Failed to malloc", 0);
  result->name = strdup(name);
  result->fct = fct;
  result->next = NULL;
  if (a != NULL && *a != NULL)
    tmp->next = result;
  else
    *a = result;
}

void			fill_list_function(t_list_cmd **a)
{
  add_list_function(a, "NICK", my_nickname); //nick
  add_list_function(a, "LIST", NULL); //list
  add_list_function(a, "JOIN", my_join); // join
  add_list_function(a, "PART", NULL); //part
  add_list_function(a, "NAMES", NULL); //user
  //add_list_function(a, "", NULL); //message
  add_list_function(a, "PRIVMSG", NULL); //msg
  //add_list_function(a, "?", NULL); //snd file
  //add_list_function(a, "?", NULL); // accept_file
  add_list_function(a, "USER", my_user);
}

t_list_cmd			*get_list_function(int opt)
{
  static t_list_cmd		*n = NULL;
  t_list_cmd			*tmp;
  t_list_cmd			*to_free;

  if (n == NULL)
    fill_list_function(&n);
  if (opt && n != NULL)
    {
      tmp = n;
      while (tmp)
	{
	  to_free = tmp;
	  tmp = tmp->next;
	  free(to_free);
	}
      n = NULL;
      return (NULL);
    }
  return (n);
}

int				choose_cmd(t_env *e, t_cmd *cmd, t_env *client)
{
  t_list_cmd			*list;
  t_list_cmd			*tmp;

  list = get_list_function(0);
  tmp = list;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, cmd->cmd) == 0)
	{
	  if (tmp->fct != NULL)
	    {
	      tmp->fct(e, cmd, client);
	      return (0);
	    }
	  else
	    printf("Fonction non implémentée\n");
	}
      tmp = tmp->next;
    }
  my_msg(e, cmd, client);
  return (0);
}
