/*
** map_object.c for map_object in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Tue Mar 31 14:16:27 2015 Jérémy MATHON
** Last update Tue Apr 28 16:19:42 2015 Pierre NOEL
*/

#include	"client.h"

t_map		*init_map(t_map *this)
{
  this = add_element(this, "server", connection_server);
  this = add_element(this, "nick", change_nickname);
  this = add_element(this, "join", join_channel);
  this = add_element(this, "msg", msg_user);
  this = add_element(this, "part", part_channel);
  this = add_element(this, "list", list_channel);
  this = add_element(this, "users", list_user);
  return (this);
}

t_map		*add_element(t_map *this, const char *s,
			     int (*ptr)(char **, t_client *))
{
  t_map		*tmp;
  t_map		*element;

  element = malloc(sizeof(t_map));
  if (!this)
    {
      element->name = strdup(s);
      element->ptr_fct = ptr;
      element->next = NULL;
      this = element;
      return (this);
    }
  tmp = this;
  while (tmp->next != NULL)
    tmp = tmp->next;
  element->name = strdup(s);
  element->ptr_fct = ptr;
  element->next = NULL;
  tmp->next = element;
  return (this);
}

t_map		*add_element2(t_map *this, const char *s,
			      int (*ptr)(char **, t_client *))
{
  t_map		*tmp;
  t_map		*element;

  element = malloc(sizeof(t_map));
  if (!this)
    {
      element->name = strdup(s);
      element->ptr_fct = ptr;
      element->next = NULL;
      this = element;
      return (this);
    }
  tmp = this;
  while (tmp->next != NULL)
    tmp = tmp->next;
  element->name = strdup(s);
  element->ptr_fct = ptr;
  element->next = NULL;
  tmp->next = element;
  return (this);
}
