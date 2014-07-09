/*
** send_msg.c for send_msg in /home/vallee_c/Zappy/Client/network
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:33:21 2014 david vallee
// Last update Tue Jul  8 20:00:39 2014 david vallee
*/

#include "network.h"

int	count(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int	send_msg(int fd, const char *str)
{
  if (write(fd, str, count(str)) == -1)
    return (-1);
  return (0);
}
