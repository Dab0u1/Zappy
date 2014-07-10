/*
** ppo.c for ZAP in /home/gonon_c/rendu/PSU_2013_zappy
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Thu Jul 10 15:39:27 2014 gonon_c
** Last update Thu Jul 10 18:12:44 2014 gonon_c
*/

#include "../serveur.h"

int		ppo(t_serveur *s, int fd)
{
  char		msg[255];

  sprintf(msg, "ppo #%d %d %d %d\n",
          s->ctab[fd].id, s->ctab[fd].x,
          s->ctab[fd].y, s->ctab[fd].o);
  send_msgToAll_Monitor(s, msg);
  send_msg(fd, "ok\n");
  return (0);
}
