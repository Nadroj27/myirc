/*
** map_object.c for map_object in /home/mathon_j/rendu/PSU_2014_myirc/src_client
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Tue Mar 31 14:16:27 2015 Jérémy MATHON
** Last update Tue Mar 31 14:46:10 2015 Jérémy MATHON
*/

#include	"client.h"

t_map		*init_map(t_map *this)
{
  this = add_element(this, "server", &connection_server);
  this = add_element(this, "nick", &change_nickname);
  this = add_element(this, "list", &list_channel);
  this = add_element(this, "join", &join_channel);
  this = add_element(this, "part", &part_channel);
  this = add_element(this, "user", &list_user);
  this = add_element(this, "msg", &msg_user);
  this = add_element(this, "send", &send_file);
  this = add_element(this, "accept", &accept_file);
  return (this);
}

t_map		*add_element(t_map *this, char *s, void *ptr)
{
  t_map		*tmp;
  t_map		*element;

  element = malloc(sizeof(t_map));
  tmp = this;
  if (!this)
    {
      tmp->name = s;
      tmp->ptr_fct = ptr;
      tmp->next = NULL;
      return (tmp);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  element->name = s;
  element->ptr_fct = ptr;
  element->next = NULL;
  tmp->next = element;
  return (tmp);
}
