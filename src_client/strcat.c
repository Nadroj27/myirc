/*
** strcat.c for irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sat Apr 25 16:09:13 2015 Pierre NOEL
** Last update Sat Apr 25 16:43:55 2015 Pierre NOEL
*/

#include			"client.h"

char				*xstrcat(char *s, char *d)
{
  char				*r;

  r = malloc(strlen(s) + strlen(d) + 5);
  if (r == NULL)
    return (NULL);
  strcpy(r, s);
  strcat(r, d);
  return (r);
}
