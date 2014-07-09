/*
** GenarateMap.c for GenarateMap in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Map
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Jul  6 21:27:18 2014 david vallee
** Last update Wed Jul  9 19:44:33 2014 david vallee
*/

#include <stdlib.h>
#include "map.h"

#define MODRAND 20
#define NB_OBJ_MAX_BY_CELL 3

int		RandomGeneration(t_map *map)
{
  int		type;
  int		x;
  int		y;
  int		n;
  int		l;

  x = 0;
  while (x < map->sizeX)
    {
      y = 0;
      while (y < map->sizeY)
	{
	  n = 0;
	  l = rand() % NB_OBJ_MAX_BY_CELL;
	  while (n < l)
	    {
	      type = rand() % MODRAND;
	      if (type < 7)
		put_in_map(map, x, y, type);
	      ++n;
	    }
	  ++y;
	}
      ++x;
    }
  return (0);
}

t_map		*GenerateMap(int x, int y)
{
  t_map		*map;
  int		i;

  srand(time(NULL));
  if ((map = malloc(sizeof(t_map))) == NULL ||
      (map->cell = malloc(sizeof(t_cell **) * x * y)) == NULL)
    return (NULL);
  map->sizeX = x;
  map->sizeY = y;
  i = 0;
  while (i < (x * y))
    {
      if ((map->cell[i] =  malloc(sizeof(t_cell *))) == NULL)
	return (NULL);
      *map->cell[i] = NULL;
      ++i;
    }
  RandomGeneration(map);
  //showMap(map);
  return (map);
}
