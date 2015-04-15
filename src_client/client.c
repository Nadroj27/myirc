/*
** client.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sun Mar 29 22:34:24 2015 Pierre NOEL
** Last update Tue Apr 14 17:07:40 2015 Pierre NOEL
*/

#include		"client.h"

void			command_in_the_map(t_map *this, char **arg, int sfd)
{
  t_map			*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      printf("COMMAND : %s\n", tmp->name);
      printf("ARG : %s\n", arg[0]);
      if (strcmp(tmp->name, arg[0]) == 0)
	tmp->ptr_fct(arg, sfd);
      tmp = tmp->next;
    }
}

void			check_command(char *buff, int sfd, int length, t_map *map)
{
  char			**arg;

  printf("BUFFER => %s\n", buff);
  if (buff[0] != '/')
    {
      write(sfd, buff, length);
      close(sfd);
      return ;
    }
  if (buff[0] == '/')
    buff++;
  arg = my_str_to_wordtab(buff, ' ');
  printf("ARG : %s , %s , %s\n", arg[0], arg[1], arg[2]);
  command_in_the_map(map, arg, sfd);
}

void			check_input(int sfd, t_map *map)
{
  char			buff[4096];
  int			length;

  length = read(0, buff, 4095);
  buff[length - 1] = 0;
  check_command(buff, sfd, length, map);
}

void			mloop(int sfd)
{
  int			ret;
  char			buffer[4096];
  t_map			*map;

  map = NULL;
  map = init_map(map);
  while (1)
    {
      printf("début read\n");
      ret = read(sfd, buffer, 4096);
      buffer[ret] = 0;
      printf("Connexion established : %s\n", buffer);
      check_input(sfd, map);
      printf("-----------\n");
    }
}

int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			sfd;
  struct sockaddr_in	my_addr;

  if (ac != 3)
    my_error("Usage : ./client [adress] [port]\n", 0);
  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  sfd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (sfd == - 1)
    my_error("Failed to create socket", 1);
  memset(&my_addr, '\0', sizeof(my_addr));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(atoi(av[2]));
  my_addr.sin_addr.s_addr = inet_addr(av[1]);
  if (connect(sfd, (struct sockaddr *) &my_addr,
	      sizeof(my_addr)) ==  - 1)
    my_error("Failed to connect", 1);
  mloop(sfd);
  return (0);
}
