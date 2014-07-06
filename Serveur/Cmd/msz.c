/*
** msz.c for msz in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Cmd
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sat Jul  5 18:34:05 2014 david vallee
** Last update Sun Jul  6 06:09:52 2014 david vallee
*/

#include <stdlib.h>
#include "../serveur.h"

void	msz(int fd, int x, int y)
{
  char msg[30];

  sprintf(msg, "msz %d %d\n", x, y);
  send_msg(fd, msg);
}
