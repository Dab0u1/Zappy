/*
** read_cmd.c for read_cmd in /home/vallee_c/rendu/MergeZappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Thu Jul 10 14:20:36 2014 david vallee
** Last update Thu Jul 10 15:52:12 2014 david vallee
*/

#include "serveur.h"

int	get_cmd(t_serveur *s, int fd, char *cmd)
{
  int	r;

  if ((r = read(fd, cmd, 4096)) == -1)
    {
      printf("Read prb\n");
      return (-1);
    }      
  else if (r == 0)
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      if (s->ctab[fd].type == CLIENT)
	cmddie(s, fd);
      s->ctab[fd].type = FREE;
      return (0);
    }
  cmd[r] = '\0';
  return (1);
}

int	read_cmd(t_serveur *s, int fd)
{
  int	r;
  char	cmd[4096];

  if (get_cmd(s, fd, cmd) != 1)
    return (0);
  exec_cmd(s, fd, cmd);
  return (0);
}
