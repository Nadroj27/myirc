/*
** user.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 17:26:40 2015 Pierre NOEL
** Last update Wed Apr  8 17:27:18 2015 Pierre NOEL
*/

#include			"server.h"

void				my_user(t_env *e, t_cmd *cmd, t_env *client)
{
  client->return_code = strdup("300\r\n");
}
