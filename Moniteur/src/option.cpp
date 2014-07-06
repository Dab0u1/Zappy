//
// option.cpp for ZAP in /home/gonon_c/rendu/Zappy/Moniteur/src
// 
// Made by gonon_c
// Login   <gonon_c@epitech.net>
// 
// Started on  Sun Jul  6 18:02:50 2014 gonon_c
// Last update Sun Jul  6 19:54:22 2014 david vallee
//

#include <stdlib.h>
#include <stdio.h>
#include "option.h"

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

int		opt_x(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide weightscreen, 800 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
	{
	  printf("Invalide weightscreen, 800 set as default\n");
	  return (0);
	}
      ++i;
    }
  if (atoi(av[*j]) >= 400 && atoi(av[*j]) <= 1920)
    option->x = atoi(av[*j]);
  else
    printf("Invalide weightscreen min:400 max:1920, 800 set as default\n");
  return (0);
}

int		opt_y(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide heightscreen, 600 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
	{
	  printf("Invalide heightscreen, 600 set as default\n");
	  return (0);
	}
      ++i;
    }
  if (atoi(av[*j]) >= 300 && atoi(av[*j]) <= 1080)
    option->y = atoi(av[*j]);
  else
    printf("Invalide heightscreen min:300 max:1080, 600 set as default\n");
  return (0);
}

int		opt_f(t_option *option, char **av, int *j)
{
  option->fullscreen = true;
  return (0);
}
