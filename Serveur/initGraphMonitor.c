/*
** initGraphMonitor.c for initGraphMonitor in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sat Jul  5 18:32:34 2014 david vallee
** Last update Mon Jul  7 08:14:57 2014 david vallee
*/

#include "serveur.h"

int	initGraphMonitor(t_world *world, int fd)
{
  msz(fd, world->map->sizeX, world->map->sizeY);
  bct_all_map(fd, world->map);
}
