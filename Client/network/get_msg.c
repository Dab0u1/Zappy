/*
** get_msg.c for get_msg in /home/vallee_c/Zappy/Client/network
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:34:50 2014 david vallee
** Last update Wed Jul  9 11:57:12 2014 david vallee
*/

#include "network.h"

char		*get_msg(int fd)
{
  return (get_next_line(fd));
}
