/*
** list.c for my_irc in /home/noel_h/rendu/PSU_2014_myirc/src_server
**
** Made by Pierre NOEL
** Login   <noel_h@epitech.net>
**
** Started on  Wed Apr  8 14:51:24 2015 Pierre NOEL
** Last update Tue Apr 14 16:14:04 2015 Pierre NOEL
*/

#include			"server.h"

char				**getKey(t_cmd *cmd, int i, int j, int k)
{
  char				**result;

  if ((result = malloc(512 * sizeof(char *))) == NULL)
    my_error("Malloc failed", 0);
  result[0] = NULL;
  while (cmd->opt[0][i] != 0)
    {
      if (cmd->opt[0][i] == ',' && result[0] != NULL)
	{
	  result[j][k] = 0;
	  k = 0;
	  result[j + 1] = NULL;
	  j++;
	}
      else
	{
	  if (result[j] == NULL)
	    if ((result[j] = malloc(512)) == NULL)
	      my_error("Malloc failed", 0);
	  result[j][k] = cmd->opt[0][i];
	  k++;
	}
      i++;
    }
  result[j][k] = 0;
  result[j + 1] = NULL;
  return (result);
}

char				**getResult(t_env *e, t_cmd *cmd)
{
  int				i;
  char				**key;
  char				**result;
  char				**tmp;

  i = 0;
  if ((result = malloc(512 * sizeof(char *))) == NULL)
    my_error("Malloc failed", 0);
  result[0] = NULL;
  key = getKey(cmd, 0, 0, 0);
  while (key[i] != NULL)
    {
      tmp = list_canal(e, key[i]);
      int j = 0;
      while (tmp[j] != NULL)
	{
	  printf("tmp[j] = %s\n", tmp[j]);
	  j++;
	}
      result = concatDoubleChar(tmp, result);
      free_my_double_char(tmp);
      i++;
    }
  free_my_double_char(key);
  return (result);
}

char				*getRPL_list(char **result,
					     char *host,
					     char *nickname)
{
  int				i;
  char				*info;

  if ((info = malloc(512)) == NULL)
    my_error("Malloc failed", 0);
  info[0] = 0;
  i = 0;
  while (result[i] != NULL)
    {
      info = xstrcat(info, ":");
      info = xstrcat(info, host);
      info = xstrcat(info, " 322 ");
      info = xstrcat(info, nickname);
      info = xstrcat(info, " ");
      info = xstrcat(info, result[i]);
      info = xstrcat(info, " 1 :No subject\r\n");
      i++;
    }
  return (info);
}

void				my_list(t_env *e, t_cmd *cmd, t_env *client)
{
  char				*info;
  char				**result;

  if (cmd->opt[0] != NULL)
    {
      if ((info = malloc(512)) == NULL)
	my_error("Malloc failed", 0);
      info[0] = 0;
      result = getResult(e, cmd);
      if (0 > sprintf(info, ":%s %s%s:%s 323 %s :End of /LIST\r\n",
		      client->nickname,
		      "321 Channel:Users Name\r\n",
		      getRPL_list(result, client->host, client->nickname),
		      client->nickname,
		      client->nickname))
	my_error_c("Unable to return response", 0);
      client->return_code = strdup(info);
      free_my_double_char(result);
      free(info);
    }
}
