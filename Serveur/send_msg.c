/*
** send_msg.c for send_msg in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 15:25:38 2014 david vallee
** Last update Wed Jul  9 21:01:19 2014 david vallee
*/

#include "serveur.h"

int	send_msg(int fd, char *msg)
{
  printf("%d : %s\n", fd, msg);
  if (write(fd, msg, (strlen(msg))) == -1)
    return (-1);
  return (0);
}

int	send_msgToAll_Client(t_serveur *s, char *msg)
{
  int	i;

  i = 0;
  while (i < s->maxClient)
    {
      if (s->ctab[i].type == CLIENT)
	if (send_msg(i, msg) == -1)
	  return (-1);
      ++i;
    }
  return (0);
}

int	send_msgToAll_Monitor(t_serveur *s, char *msg)
{
  int	i;

  i = 0;
  while (i < s->maxClient)
    {
      if (s->ctab[i].type == MONITEUR)
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
  while (i < s->maxClient)
    {
      if (s->ctab[i].type == CLIENT && i != fd)
	if (send_msg(i, msg) == -1)
	  return (-1);
      ++i;
    }
  return (0);
}
