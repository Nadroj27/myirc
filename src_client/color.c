/*
** color.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 23 10:56:48 2015 Pierre NOEL
** Last update Sat Apr 25 15:04:22 2015 Pierre NOEL
*/

#include			"client.h"

char				*textcolor(int fg, char *text, int opt)
{
  char				*command;

  command = malloc(4096);
  if (opt)
    sprintf(command, "%c[%dm%s%c[0m\n", 27, fg + 30, text, 27);
  else
    sprintf(command, "%c[%dm%s%c[0m", 27, fg + 30, text, 27);
  return (command);
}
