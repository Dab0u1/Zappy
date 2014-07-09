/*
** start.c for zappy in /home/vallee_c/Zappy/Client
** 
** Made by david vallee
** Login   <vallee_c@epitech.net>
** 
** Started on  Fri Jul  4 16:33:01 2014 david vallee
** Last update Wed Jul  9 12:29:41 2014 david vallee
*/

#include <unistd.h>
#include <fcntl.h>
#include "client.h"

int			fdReset(fd_set *fd_read, struct timeval *tv, int fd)
{
  FD_ZERO(fd_read);
  FD_SET(fd, fd_read);
  FD_SET(0, fd_read);
  tv->tv_sec = 0;
  tv->tv_usec = 3;
}

int			start(t_client *client)
{
  fd_set		fd_read;
  struct timeval	tv;
  int			run;
  int			fd;
  char			*msg;
  char			msg_to_send[255];
  int			mode;

  fd = client->fd;
  mode = fcntl(fd, F_GETFL, 0);
  mode |= O_NONBLOCK;
  fcntl(fd, F_SETFL, mode);
  run = 1;
  msg = NULL;
  while (run)
    {
      /* fdReset(&fd_read, &tv, fd); */
      /* if (select(fd + 1, &fd_read, NULL, NULL, &tv) == -1) */
      /* 	{ */
      /* 	  printf("Select Error\n"); */
      /* 	  return (-1); */
      /* 	} */
      /* // on lit l'entrer standard -> pour les commande de debug (exemple connaitre la position de son drone, sont inevntaire, ect ...) */
      /* if (FD_ISSET(0, &fd_read)) */
      /* 	if (exec_cmd(fd) == -1) */
      /* 	  return (-1); */
      /* // msg = message recuperer du serveur */
      /* if (FD_ISSET(fd, &fd_read)) */
      /* 	{ */
	  msg = get_msg(fd);      
	  // ici on va update le traintorien et l'ia
	  // pour l'instant j'affiche juste la commande que le serveur envoi
	  if (msg != NULL)
	    {
	      printf("%s\n", msg);
	      if (strcmp("BIENVENUE", msg) == 0)
		{
		  printf("->%s\n", client->nomEquipe);
		  sprintf(msg_to_send, "%s\n", client->nomEquipe);
		  send_msg(fd, msg_to_send);
		}
	      free(msg);
	      msg = NULL;
	    }
	/* } */
    }
  return (0);
}
