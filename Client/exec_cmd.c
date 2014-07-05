/*
** exec_cmd.c for exec_cmd in /home/vallee_c/Zappy/Client
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:56:44 2014 david vallee
** Last update Fri Jul  4 17:01:29 2014 david vallee
*/

#include "client.h"

int			exec_cmd(int fd)
{
  char			cmd[255];
  int			r;

  if ((r = read(0, cmd, 255)) == -1)
    {
      printf("exec_cmd: read fail !\n");
      return (-1);
    }
  else if (r == 0)
    {
      printf("Close client\n");
      return (-1);
    }
  cmd[r] = '\0';
  send_msg(fd, cmd);
  return (0);
}
