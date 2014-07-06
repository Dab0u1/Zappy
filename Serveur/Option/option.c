/*
** option.c for ZAP in /home/gonon_c/rendu/Zappy/Serveur
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 12:32:12 2014 gonon_c
** Last update Sun Jul  6 14:27:39 2014 gonon_c
*/

#include <stdlib.h>
#include "../serveur.h"

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

int		opt_x(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide weight, 20 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
	{
	  printf("Invalide weight, 20 set as default\n");
	  return (0);
	}
      ++i;
    }
  option->worldX = atoi(av[*j]);
  return (0);
}

int		opt_y(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide height, 20 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
	{
	  printf("Invalide height, 20 set as default\n");
	  return (0);
	}
      ++i;
    }
  option->worldY = atoi(av[*j]);
  return (0);
}

int		opt_c(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide capacity group, 5 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
      {
	printf("Invalide capacity group, 5 set as default\n");
	return (0);
      }
      ++i;
    }
  option->maxClientbyTeam = atoi(av[*j]);
  return (0);
}

int		opt_t(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
  if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("Invalide temporal delay, 100 set as default\n");
      return (0);
    }
  while (av[*j][i])
    {
      if (av[*j] && (av[*j][i] < '0' || av[*j][i] > '9'))
      {
	printf("Invalide temporal delay, 100 set as default\n");
	return (0);
      }
      ++i;
    }
  option->t = atoi(av[*j]);
  return (0);
}
