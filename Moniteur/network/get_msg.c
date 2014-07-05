/*
** get_msg.c for get_msg in /home/vallee_c/Zappy/Client/network
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:34:50 2014 david vallee
** Last update Fri Jul  4 17:04:38 2014 david vallee
*/

#include "network.h"

char		*get_msg(int fd)
{
  char		msg[4096];
  int		r;

  if ((r = read(fd, msg, 4096)) <= 0)
    return (NULL);
  msg[r] = '\0';
  return (strdup(msg));
}
