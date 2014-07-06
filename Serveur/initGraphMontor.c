/*
** initGraphMontor.c for initGraphMontor in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sat Jul  5 18:32:34 2014 david vallee
** Last update Sun Jul  6 06:02:17 2014 david vallee
*/

#include "serveur.h"

int	initGraphMonitor(t_world *world, int fd)
{
  msz(fd, world->sizeX, world->sizeY);
}
