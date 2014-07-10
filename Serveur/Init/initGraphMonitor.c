/*
** initGraphMonitor.c for initGraphMonitor in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sat Jul  5 18:32:34 2014 david vallee
** Last update Thu Jul 10 18:00:20 2014 gonon_c
*/

#include "../serveur.h"

int	initGraphMonitor(t_serveur *s, int fd)
{
  msz(fd, s->map->sizeX, s->map->sizeY);
  /* sgt(s, fd); */
  bct_all_map(fd, s->map);
  pnw_all_to_one_monitor(s, fd);
}
