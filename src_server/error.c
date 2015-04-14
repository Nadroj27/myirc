/*
** error.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:50:20 2015 Pierre NOEL
** Last update Tue Apr 14 14:35:08 2015 Pierre NOEL
*/

#include				"server.h"

void					my_error(char *x, int opt)
{
  fprintf(stderr, "[Error] %s", x);
  if (opt)
    fprintf(stderr, " : %s", strerror(errno));
  fprintf(stderr, "\n");
  exit(1);
}

void					my_error_c(char *x, int opt)
{
  fprintf(stderr, "[Error] %s", x);
  if (opt)
    fprintf(stderr, " : %s", strerror(errno));
  fprintf(stderr, "\n");
}

void					response_fail(char **to_free, int fd)
{
  fprintf(stderr, "[Error] Fail to return response at Client %d\n", fd);
  free(*to_free);
  *to_free = NULL;
}
