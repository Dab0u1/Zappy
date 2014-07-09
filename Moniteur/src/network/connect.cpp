/*
** connect.c for connect in /home/vallee_c/TECH2/SystemeUnix/my_irc/irc0.1/Client
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Thu Jul  3 16:53:38 2014 david vallee
// Last update Wed Jul  9 18:40:54 2014 david vallee
*/

#include <unistd.h>
#include <fcntl.h>
#include "network.h"

int	connect_to_server(char *ip, int port)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			mode;
  
  if (!(pe = getprotobyname("TCP")))
    {
      printf("connect_to_server : getprotobyname fail\n");
      return (-1);
    }
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      printf("connect_to_server : fail to create socket\n");
      return (-1);
    }
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("connect_to_server : fail to connect to server\n");
      if (close(fd) == -1)
	printf("connect_to_server : close(fd) fail\n");
      return (-1);
    }
  mode = fcntl(fd, F_GETFL, 0);
  mode |= O_NONBLOCK;
  fcntl(fd, F_SETFL, mode);
  return (fd);
}

int	close_connect(int fd)
{
  if (close(fd) == -1)
    {
      printf("close_connect : close(fd) fail\n");
      return (-1);
    }
  return (0);
}
