/*
** add_client.c for add_client in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:25:16 2014 david vallee
** Last update Sat Jul  5 18:24:54 2014 david vallee
*/

#include "serveur.h"

void			add_client(t_serveur *s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  int			client_sin_len;

  printf("New client\n");
  client_sin_len = sizeof(client_sin);
  cs = accept(s->fd, (struct sockaddr *)&client_sin, &client_sin_len);
  s->ctab[cs].free = NOFREE;
  s->idmax += 1;
  s->ctab[cs].id = s->idmax;
  s->ctab[cs].init = NOINIT;
}
