/*
** get_msg.c for get_msg in /home/vallee_c/Zappy/Client/network
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:34:50 2014 david vallee
// Last update Sun Jul  6 05:38:14 2014 david vallee
*/

#include "network.h"

std::string get_msg(int fd)
{
  char		msg[4096];
  int		r;

  if ((r = read(fd, msg, 4096)) <= 0)
    return (NULL);
  msg[r] = '\0';
  return (std::string(msg));
}
