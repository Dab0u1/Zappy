/*
** option.c<2> for Zap in /home/gonon_c/rendu/Zappy/Client
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 16:58:00 2014 gonon_c
** Last update Sun Jul  6 18:05:20 2014 gonon_c
*/

#include <stdlib.h>
#include "client.h"

int		opt_p(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide Port number, 4242 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
	{
	  printf("Invalide Port number, 4242 set as default\n");
	  return (0);
	}
      ++i;
    }
  option->port = atoi(av[*j]);
  return (0);
}

int		opt_h(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide IP number, 127.0.0.1 set as default\n");
      return (0);
    }
  option->ip = av[*j];
  return (0);
}

int		opt_n(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide Group name, set as default\n");
      return (0);
    }
  option->nomEquipe = av[*j];
}
