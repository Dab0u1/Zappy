/*
** init.c for init in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:22:42 2014 david vallee
** Last update Sun Jul  6 21:59:28 2014 david vallee
*/

#include "serveur.h"

int		init_serveur(t_serveur *s, t_option *option)
{
  int		i;

  s->idmax = 0;
  s->isRuning = 1;
  if ((s->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (1);
  s->sin.sin_family = AF_INET;
  s->sin.sin_port = htons(option->port);
  s->sin.sin_addr.s_addr = INADDR_ANY;
  s->fd_max = s->fd;
  bind(s->fd, (struct sockaddr*)&s->sin, sizeof(s->sin));
  listen(s->fd, 42);
  i = 0;
  // changer max client par option->maxclient
  while (i < MAX_CLIENT)
    {
      s->ctab[i].free = FREE;
      ++i;
    }
  return(0);
}

int	init_world(t_world *world, t_option *option)
{
  world->map = GenerateMap(option->worldX, option->worldY); 
  world->team = option->team;
  world->t = option->t; 
}
