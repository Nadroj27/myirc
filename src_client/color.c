/*
** color.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 23 10:56:48 2015 Pierre NOEL
** Last update Thu Apr 23 11:38:32 2015 Pierre NOEL
*/

#include			"client.h"

void				textcolor(int fg, char *text, int opt)
{
  char				command[4096];

  sprintf(command, "%c[%dm%s%c[0m", 27, fg + 30, text, 27);
  if (opt)
    printf("%s\n", command);
  else
    printf("%s", command);
}
