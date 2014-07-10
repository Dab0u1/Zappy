/*
** serveur.c for serveur in /home/vallee_c/TECH2/SystemeUnix/my_irc/PSU_2013_myirc
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Apr 20 09:26:38 2014 david vallee
** Last update Thu Jul 10 14:23:08 2014 david vallee
*/

#include "serveur.h"

int		fdReset(t_serveur *s, fd_set* fd_read, struct timeval *tv)
{
  int		i;

  FD_ZERO(fd_read);
  tv->tv_sec = 3;
  tv->tv_usec = 0;
  FD_SET(s->fd, fd_read);
  s->fd_max = s->fd;
  i = 0;
  while (i < s->maxClient)
    {
      if (s->ctab[i].type != FREE)
	{
	  FD_SET(i, fd_read);
	  s->fd_max = i;
	}
      ++i;
    }
  return (0);
}

int			run(t_serveur *s)
{
  fd_set		fd_read;
  int			i;
  struct timeval	tv;

  while (s->isRuning)
    {
      fdReset(s, &fd_read, &tv);
      if (select(s->fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
	{
	  perror("Select Error\n");
	  return (0);
	}
      if (FD_ISSET(s->fd, &fd_read))
	add_client(s);
      i = 0;
      while (i < (s->maxClient))
      	{
      	  if (i != s->fd && FD_ISSET(i, &fd_read))
	    read_cmd(s, i);
	  ++i;
      	}
    }
  return (0);
}

int			serveur(t_option *option)
{
  t_serveur		s;

  init_serveur(&s, option);
  run(&s);
  return (0);
}
