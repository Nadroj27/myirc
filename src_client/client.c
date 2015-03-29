/*
** client.c for myirc in /home/noel_h/rendu/PSU_2014_myirc
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Sun Mar 29 22:34:24 2015 Pierre NOEL
** Last update Sun Mar 29 22:44:52 2015 Pierre NOEL
*/

#include		"client.h"

int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			sfd;
  struct sockaddr_in	my_addr;
  int			ret;
  char			buffer[4096];

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

  ret = read(sfd, buffer, 4096);
  buffer[ret] = 0;
  printf("Connexion established : %s\n", buffer);
  write(sfd, "CMD QQCHOE\n", 11);
  close(sfd);
  return (0);
}
