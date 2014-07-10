/*
** start.c for zappy in /home/vallee_c/Zappy/Client
** 
** Made by david vallee
** Login   <vallee_c@epitech.net>
** 
** Started on  Fri Jul  4 16:33:01 2014 david vallee
** Last update Thu Jul 10 02:42:17 2014 gonon_c
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

int			step_1(t_client *client, char *msg, int fd, int *count)
{
  char			msg_to_send[255];

  if (strcmp("BIENVENUE", msg) == 0)
    {
      printf("->%s\n", client->nomEquipe);
      sprintf(msg_to_send, "%s\n", client->nomEquipe);
      send_msg(fd, msg_to_send);
    }
  printf("OK_1\n");
  *count = 1;
  return (0);
}

int			step_2(t_client *client, char *msg, int *count)
{
  if (atoi(msg) >= 1)
    *count = 2;
  return (0);
}

int			step_3(t_client *client, char *msg, int *count)
{
  char			*y;
  int			i;
  
  i = 0;
  printf("%d\n", atoi(msg));
  while (msg[i] != ' ')
    i++;
  i++;
  y = &msg[i];
  client->x = atoi(msg);
  printf("%d\n", atoi(y));
  client->y = atoi(y);
  *count = 3;
  return (0);
}

int			start(t_client *client)
{
  fd_set		fd_read;
  struct timeval	tv;
  int			run;
  int			fd;
  char			*msg;
  int			mode;
  int			count;

  count = 0;
  fd = client->fd;
  /* mode = fcntl(fd, F_GETFL, 0); */
  /* mode |= O_NONBLOCK; */
  /* fcntl(fd, F_SETFL, mode); */
  run = 1;
  msg = NULL;
  while (run)
    {
      msg = get_msg(fd);
      if (msg != NULL)
	{
	  printf("%s\n", msg);
	  if (count == 3)
	    if (read_cmd(fd) == -1)
	      return (-1);
	  if (count == 2)
	    step_3(client, msg, &count);
	  if (count == 1)
	    step_2(client, msg, &count);
	  if (count == 0)
	    step_1(client, msg, fd, &count);
	  free(msg);
	  msg = NULL;
	}
    }
  return (0);
}
