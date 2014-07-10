/*
** sgt.c for ZAP in /home/gonon_c/rendu/PSU_2013_zappy
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Thu Jul 10 16:55:10 2014 gonon_c
** Last update Thu Jul 10 18:03:04 2014 gonon_c
*/

#include "../serveur.h"

int		sgt(t_serveur *s, int fd)
{
  char		msg[255];

  sprintf(msg, "sgt %d\n", s->t);
  send_msg(fd, msg);
  return (0);
}
