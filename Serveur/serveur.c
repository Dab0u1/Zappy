/*
** serveur.c for serveur in /home/vallee_c/TECH2/SystemeUnix/my_irc/PSU_2013_myirc
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Apr 20 09:26:38 2014 david vallee
** Last update Fri Jul  4 15:52:15 2014 david vallee
*/

#include "serveur.h"

int	read_cmd(t_serveur *s, int fd)
{
  int	r;
  char	cmd[4096];

  if ((r = read(fd, cmd, 4096)) == -1)
    {
      printf("Read prb\n");
      return (-1);
    }      
  else if (r == 0)
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      s->ctab[fd].free = FREE;
      return (0);
    }
  cmd[r] = '\0';

  // Ici parsser Commande Update world et repondre au client 

  send_msgToAll_exeptOne(s, cmd, fd);
  return (0);
}

int			fdReset(t_serveur *s, fd_set* fd_read, struct timeval *tv)
{
  int	i;

  FD_ZERO(fd_read);
  tv->tv_sec = 3;
  tv->tv_usec = 0;
  FD_SET(s->fd, fd_read);
  s->fd_max = s->fd;
  i = 0;
  while (i < MAX_CLIENT)
    {
      if (s->ctab[i].free == NOFREE)
	{
	  FD_SET(i, fd_read);
	  s->fd_max = i;
	}
      ++i;
    }
  return (0);
}

int			serveur(t_option *option)
{
  //t_World		world;
  t_serveur		s;
  fd_set		fd_read;
  int			i;
  struct timeval	tv;

  init_serveur(&s, option);
  //init_world(&world, &s, option);
  while (s.isRuning)
    {
      fdReset(&s, &fd_read, &tv);
      if (select(s.fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
	{
	  perror("Select Error\n");
	  return (0);
	}

      // Si le Fd du serveur est set un nouveaux client se connecte
      if (FD_ISSET(s.fd, &fd_read))
	add_client(&s);

      // On check tous les fd de client pour recevoir leur message update les trantorien

      i = 0;
      while (i < MAX_CLIENT)
      	{
      	  if (i != s.fd && FD_ISSET(i, &fd_read))
	    read_cmd(&s, i);
	  ++i;
      	}

      //On Update le monde (action des joueur, position, elevation ect ...)
      //on envoi les données au client graphic
      //update_world();
    }
  return (0);
}
