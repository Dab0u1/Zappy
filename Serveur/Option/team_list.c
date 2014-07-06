/*
** team_list.c for ZAP in /home/gonon_c/rendu/Zappy/Serveur
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 12:33:21 2014 gonon_c
** Last update Sun Jul  6 14:27:37 2014 gonon_c
*/


#include <stdlib.h>
#include "../serveur.h"

int		push_team(t_team **list, char *data)
{
  t_team        *elem;

  if ((elem = malloc(sizeof(t_team *))) == NULL)
    return (-1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

int		show_team(t_option *option)
{
  t_team	*coco;

  coco = option->team;
  while (coco)
    {
      printf("%s\n", coco->data);
      coco = coco->next;
    }
  return (0);
}

int		opt_n(t_option *option, char **av, int *j)
{
  int		i;

  i = 0;
  (*j)++;
    if (av[*j] == NULL || av[*j][i] == '-')
    {
      printf("No team have been set\n");
      return (0);
    }
  while (av[(*j)] && av[*j][i] != '-')
    {
      push_team(&(option->team), av[(*j)]);
      (*j)++;
    }
  show_team(option);
  return (0);
}
