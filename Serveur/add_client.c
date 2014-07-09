/*
** add_client.c for add_client in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:25:16 2014 david vallee
** Last update Wed Jul  9 21:50:05 2014 david vallee
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
  s->ctab[cs].type = NOINIT;
  printf("%d\n", cs);
  send_msg(cs, "BIENVENUE\n");
  send_msg(cs, "\0");
}
