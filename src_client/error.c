/*
** error.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:50:20 2015 Pierre NOEL
** Last update Sun Mar 29 22:35:32 2015 Pierre NOEL
*/

#include				"client.h"

void					my_error(char *x, int opt)
{
  printf("Error Client : %s", x);
  if (opt)
    printf(" : %s", strerror(errno));
  printf("\n");
  exit(1);
}
