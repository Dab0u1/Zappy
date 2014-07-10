/*
** pex.c for ZAP in /home/gonon_c/rendu/PSU_2013_zappy
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Thu Jul 10 15:53:27 2014 gonon_c
** Last update Thu Jul 10 16:02:54 2014 gonon_c
*/

#include "../serveur.h"

int             pex(t_serveur *s, int fd)
{
  char          msg[255];

  sprintf(msg, "pex #%d\n", s->ctab[fd].id);
  send_msgToAll_Monitor(s, msg);
  send_msg(fd, msg);
  send_msg(fd, "ok\n");
  return (0);
}
