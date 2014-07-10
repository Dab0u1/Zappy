/*
** plv.c for ZAP in /home/gonon_c/rendu/PSU_2013_zappy
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Thu Jul 10 15:55:34 2014 gonon_c
** Last update Thu Jul 10 16:04:50 2014 gonon_c
*/

#include "../serveur.h"

int             plv(t_serveur *s, int fd)
{
  char          msg[255];

  sprintf(msg, "plv #%d %d\n", s->ctab[fd].id, s->ctab[fd].lvl);
  send_msgToAll_Monitor(s, msg);
  send_msg(fd, msg);
  send_msg(fd, "ok\n");
  return (0);
}
