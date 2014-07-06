/*
** send_msg.c for send_msg in /home/vallee_c/Zappy/Client/network
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:33:21 2014 david vallee
// Last update Sat Jul  5 22:12:51 2014 david vallee
*/

#include "network.h"

int	send_msg(int fd, const char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    return (-1);
  return (0);
}
