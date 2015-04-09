/*
** xstrcat.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr  9 15:08:41 2015 Pierre NOEL
** Last update Thu Apr  9 15:09:31 2015 Pierre NOEL
*/

#include			"server.h"

char				*xstrcat(char *dest, char *src)
{
  dest = strcat(dest, src);
  if (dest == NULL)
    my_error("Strcat failed", 0);
  return (dest);
}
