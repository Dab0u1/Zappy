/*
** client.c for client in /home/vallee_c/TECH2/SystemeUnix/my_irc/PSU_2013_myirc
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Sun Apr 20 09:26:49 2014 david vallee
** Last update Fri Jul  4 15:43:07 2014 david vallee
*/

#include "network.h"

int	        client(int fd)
{
  fd_set		fd_read;
  struct timeval	tv;
  char			buf_s[4096];
  char			buf_r[4096];
  int			r;
  int			r2;
  int			run;

  run = 1;
  while (run)
    {
      FD_ZERO(&fd_read);
      FD_SET(fd, &fd_read);
      FD_SET(0, &fd_read);
      if (select(fd + 1, &fd_read, NULL, NULL, NULL) == -1)
	{
	  perror("select\n");
	  return (1);
	}
      if (FD_ISSET(0, &fd_read))
	{
	  if ((r = read(0, buf_s, 4096)) == -1 || r == 0)
	    run = 0;
	  else if (r > 0)
	    {
	      buf_s[r] = '\0';
	      write(fd, buf_s, strlen(buf_s));
	    }
	}
      if (FD_ISSET(fd, &fd_read))
	{
	  r2 = read(fd, buf_r, 4096);
	  buf_r[r2] = '\0';
	  printf("%s", buf_r);
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	fd;

  if (ac != 3)
    {
      printf("Usage : ./client <ip> <port>\n");
      return (0);
    }
  fd = connect_to_server(av[1], atoi(av[2]));
  client(fd);
  close_connect(fd);
  return (0);
}
