/*
** main.c for myirc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Mar 25 11:15:56 2015 Pierre NOEL
** Last update Wed Mar 25 12:11:54 2015 Pierre NOEL
*/

#include				"server.h"

int					read_remote(int s)
{
  fd_set				readf;
  struct timeval			tv;
  int					cs;
  struct sockaddr_in			client_sin;
  socklen_t				client_sin_len;
  char					buffer[4096];

  client_sin_len = sizeof(client_sin);
  while (1)
    {
      tv.tv_sec = 5;
      tv.tv_usec = 0;
      FD_ZERO(&readf);
      FD_SET(s, &readf);
      if (select(s + 1, &readf, NULL, NULL, &tv) == -1)
	my_error("Select failed", 1);
      if (FD_ISSET(s, &readf))
	{
	  printf("New client\n");
	  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
	  sprintf(buffer, "Connexion from %s : %u \n",
		 inet_ntoa(client_sin.sin_addr), client_sin.sin_port);
	  color("34", buffer);
	  color("33", "OK\n");
	  write(cs, "Connexion établie\n", 19);
	  sleep(5);
	  close(cs);
	}
      else
	printf("Waiting...\n");
    }
}

void					init_sockaddr(struct sockaddr_in *a, int port)
{
  a->sin_family = AF_INET;
  a->sin_port = htons(port);
  a->sin_addr.s_addr = INADDR_ANY;
}

int					main(int ac, char **av)
{
  int					s;
  struct sockaddr_in			sin;
  struct protoent			*pe;

  if (ac != 2)
    my_error("Usage : ./server [port]", 0);
  if (!(pe = getprotobyname("TCP")))
    my_error("Fail getprotobyname", 1);
  if ((s = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    my_error("Failed to create the socket", 1);
  init_sockaddr(&sin, atoi(av[1]));
  bind(s, (struct sockaddr*)&sin, sizeof(sin));
  listen(s, 42);
  read_remote(s);
  close(s);
  return (0);
}
