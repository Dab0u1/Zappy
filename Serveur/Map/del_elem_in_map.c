/*
** del_elem_in_map.c for del_elem_in_map in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Map
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Jul  6 23:20:56 2014 david vallee
** Last update Sun Jul  6 23:56:23 2014 david vallee
*/

#include <stdlib.h>
#include "Map.h"

int		del_end(t_cell *tmp)
{
  t_cell	*tmpfree;

  tmpfree = tmp->next;
  tmp->next = NULL;
  free(tmpfree);
  return (0);
}

int		del_mid(t_cell *tmp)
{
  t_cell	*tmpfree;

  tmpfree = tmp->next;
  tmp->next = tmp->next->next;
  free(tmpfree);
  return (0);
}

int		del_elem_in_map(t_map *map, int x, int y, int type)
{
  t_cell	*tmp;

  if ((tmp = *map->cell[y * map->sizeX + x]) == NULL)
    return (-1);
  if (tmp->type == type)
    {
      *map->cell[y * map->sizeX + x] = tmp->next;
      free(tmp);
      return (0);
    }
  while (tmp->next != NULL && tmp->next->type != type)
    tmp = tmp->next;
  if (tmp->next == NULL)
    {
      if (tmp->next->type != type)
	return (-1);
      return (del_end(tmp));
    }
  return (del_mid(tmp));
}
