/*
** initGraphMonitor.c for initGraphMonitor in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sat Jul  5 18:32:34 2014 david vallee
** Last update Wed Jul  9 21:33:51 2014 david vallee
*/

#include "../serveur.h"

int	initGraphMonitor(t_serveur *s, int fd)
{
  msz(fd, s->map->sizeX, s->map->sizeY);
  bct_all_map(fd, s->map);
  pnw_all_to_one_monitor(s, fd);
}
