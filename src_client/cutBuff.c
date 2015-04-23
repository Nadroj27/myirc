/*
** cutBuff.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Thu Apr 23 11:36:00 2015 Pierre NOEL
** Last update Thu Apr 23 11:38:55 2015 Pierre NOEL
*/

#include			"client.h"

void				cutbuff(char *buff, unsigned int size)
{
  if (strlen(buff) > size)
    buff[size - 1] = 0;
}
