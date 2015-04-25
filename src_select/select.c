/*
** select.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sat Apr 25 14:46:38 2015 Pierre NOEL
** Last update Sat Apr 25 14:51:53 2015 Pierre NOEL
*/

#include	<sys/select.h>
#include	<stdio.h>

int		my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
  struct timeval	tv;
  tv.tv_sec = 20;
  tv.tv_usec = 0;
  if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
    {
      fprintf(stderr, "[Error] Select failed");
      return (1);
    }
  return (0);
}
