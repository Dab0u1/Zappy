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
<<<<<<< HEAD
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

  get_cmd(s, fd, cmd);
  parsecmd(cmd, s, fd);
  // Ici Faire Tableau de Pointeur sur Fonction des Commande reçu par le serveur
  // utiliser char cmd[4096], t_serveur *s, int fd
  if (get_cmd(s, fd, cmd) != 1)
    return (0);
  if (strncmp(cmd, "GRAPHICS", 8) == 0)
    {
      new_monitor(&s->fdMonitor, fd);
      show_Monitor(s->fdMonitor);
      s->ctab[fd].type = MONITEUR;
      initGraphMonitor(s, fd);
    }
  else
    {
      t_team *tmp = s->team;
      // Si un nom de team est reçu, on init le client
      while (tmp)
  	{
  	  if (strncmp(cmd, tmp->data, strlen(cmd) - 1) == 0)
  	    initClient(s, fd, tmp->data);
  	  tmp = tmp->next;
  	}
    }

  return (0);
}

int			fdReset(t_serveur *s, fd_set* fd_read, struct timeval *tv)
{
  int	i;
=======
  int		i;
>>>>>>> 2920d620c11d80c8b27d47134b802118916f3307

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
