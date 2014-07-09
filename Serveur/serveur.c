/*
** serveur.c for serveur in /home/vallee_c/TECH2/SystemeUnix/my_irc/PSU_2013_myirc
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Apr 20 09:26:38 2014 david vallee
** Last update Wed Jul  9 22:22:32 2014 david vallee
*/

#include "serveur.h"

int	get_cmd(t_serveur *s, int fd, char *cmd)
{
  int	r;

  if ((r = read(fd, cmd, 4096)) == -1)
    {
      printf("Read prb\n");
      /* if (fd == s->fdMonitor) */
      /* 	{ */
      /* 	  //del_monitor(&s->fdMonitor, fd); */
      /* 	  s->ctab[fd].type = FREE; */
      /* 	} */
      return (-1);
    }      
  else if (r == 0)
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      s->ctab[fd].type = FREE;
      /* if (fd == s->fdMonitor) */
      /* 	{ */
      /* 	  //del_monitor(&s->fdMonitor, fd); */
      /* 	  s->ctab[fd].type = FREE; */
      /* 	} */
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
  if (strncmp(cmd, "GRAPHICS", 8) == 0)
    {
      // Si GRAPHICS est Reçu on init un nouveaux client graphique
      new_monitor(&s->fdMonitor, fd);
      show_Monitor(s->fdMonitor);
      s->ctab[fd].type = MONITEUR;
      initGraphMonitor(s, fd);
    }
  /* else if (strncmp(cmd, "avance", 6) == 0) */
  /*   { */
  /*     // envoye poo #n X Y O\n au moniteur */
  /*     // repond ok au client */
  /*   } */
  /* else if (strncmp(cmd, "droite", 6) == 0) */
  /*   { */
  /*     // envoye poo #n X Y O\n au moniteur */
  /*     // et repondre ok au client */
  /*   } */
  /* else if (strncmp(cmd, "gauche", 6) == 0) */
  /*   { */
  /*     // envoye poo #n X Y O\n au moniteur */
  /*     // repond au client */
  /*   } */
  /* else if (strncmp(cmd, "voir", 4)) */
  /*   { */
  /*     // n'envoye rien au moniteur graphique */
  /*     // repond case1, case2, case3... au client */
  /*   } */
  /* else if (strncmp(cmd, "iventaire", 4)) */
  /*   { */
  /*     // n'envoye rien au moniteur graphique */
  /*     // repond linemate n, sibur n... au client */
  /*   } */
  /* else if (strncmp(cmd, "prend object", 12)) */
  /*   { */
  /*     // envoye pgt #n i\n */
  /*     //        pin #n X Y q q q q q\n */
  /*     //        bct X Y q q q q q q q  */
  /*     // repond ok/ko au client */
  /*   } */
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

  FD_ZERO(fd_read);
  tv->tv_sec = 3;
  tv->tv_usec = 0;
  FD_SET(0, fd_read);
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

int		read_0(t_serveur *s)
{
  char		cmd[255];
  int		r;

  if ((r = read(0, cmd, 255)) == -1)
    {
      printf("Read prb\n");
      return (-1);
    }      
  else if (r == 0)
    {
      printf("ctrl-d\n");
      return (0);
    }
  cmd[r] = '\0';
  /* send_msg(s->fdMonitor, cmd); */
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
      if (FD_ISSET(0, &fd_read))
	read_0(s);
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
}

int			serveur(t_option *option)
{
  t_serveur		s;

  init_serveur(&s, option);
  run(&s);
  return (0);
}
