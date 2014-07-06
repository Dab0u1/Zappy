/*
** send_msg.c for send_msg in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 15:25:38 2014 david vallee
** Last update Fri Jul  4 15:51:29 2014 david vallee
*/

#include "serveur.h"

int	send_msg(int fd, char *msg)
{
  if (write(fd, msg, strlen(msg)) == -1)
    return (-1);
  return (0);
}

int	send_msgToAll(t_serveur *s, char *msg)
{
  int	i;

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (s->ctab[i].free == NOFREE)
	if (send_msg(i, msg) == -1)
	  return (-1);
      ++i;
    }
  return (0);
}

int	send_msgToAll_exeptOne(t_serveur *s, char *msg, int fd)
{
  int	i;

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (s->ctab[i].free == NOFREE && i != fd)
	if (send_msg(i, msg) == -1)
	  return (-1);
      ++i;
    }
  return (0);
}
