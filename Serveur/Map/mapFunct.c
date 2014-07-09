/*
** MapFunct.c for MapFunct in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Map
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Jul  6 22:09:47 2014 david vallee
** Last update Wed Jul  9 17:52:39 2014 david vallee
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

t_cell		*get_cell(t_map *map, int x, int y)
{
  return (*map->cell[y * map->sizeX + x]);
}

void		showCell(t_map *map, int x, int y)
{
  t_cell	*tmp;

  printf("X : %d - Y : %d -> ", x, y);
  tmp = *map->cell[y * map->sizeX + x];
  while (tmp)
    {
      printf("%d", tmp->type);
      tmp = tmp->next;
    }
  printf("\n");
}

void		showMap(t_map *map)
{
  int		x;
  int		y;

  x = 0;
  while(x < map->sizeX)
    {
      y = 0;
      while (y < map->sizeY)
	{
	  showCell(map, x, y);
	  ++y;
	}
      ++x;
    }
}

int		put_in_map(t_map *map, int x, int y, int type)
{
  t_cell	*elem;

  if ((elem = malloc(sizeof(t_cell))) == NULL)
    return (-1);
  elem->type = type;
  elem->next = *(map->cell[y * map->sizeX + x]);
  *(map->cell[y * map->sizeX + x]) = elem;
  return (0);
}
