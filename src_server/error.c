/*
** error.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:50:20 2015 Pierre NOEL
** Last update Mon Apr  6 19:24:46 2015 Pierre NOEL
*/

#include				"server.h"

void					my_error(char *x, int opt)
{
  printf("[Error] %s", x);
  if (opt)
    printf(" : %s", strerror(errno));
  printf("\n");
  exit(1);
}
