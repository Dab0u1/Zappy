//
// load.cpp for load in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 19:00:11 2014 david vallee
// Last update Sun Jul  6 19:19:54 2014 david vallee
//

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "World.hpp"
#include "../network/network.h"

int	get_msz(std::string str, int *x, int *y)
{
  int		pos;
  std::string	sizex;
  std::string	sizey;

  pos = str.find(" ", 4);
  sizex = str.substr(4, pos);
  sizey = str.substr(pos);
  std::stringstream ss(sizex);
  std::stringstream ss2(sizey);
  ss >> *x;
  ss2 >> *y;
  return (0);
}

int	execLoadingCmd(std::string cmd, World &world)
{
  int a;
  int b;

  if (cmd.compare(0, 3, "msz "))
    {
      a = 0;
      b = 0;
      get_msz(cmd, &a, &b);
      world.setSizeX(a);
      world.setSizeY(b);
      std::cout << "Mapsize X: " << a << ", Y: " << b << std::endl;
      return (0);
    }
  return (1);
}

int	load(World &world)
{
  fd_set	fd_read;
  int		loading;
  int		fd;
  std::string   cmd;


  fd = world.getFdServer();
  loading = 1;
  std::cout << "Get Data from server\n" << std::endl;
  send_msg(fd, "GRAPHICS\n");
  while(loading)
    {
      FD_ZERO(&fd_read);
      FD_SET(fd, &fd_read);
      if (select(fd + 1, &fd_read, NULL, NULL, NULL) == -1)
	{
	  std::cout << "Select Error" << std::endl;
	  return (1);
	}
      if (FD_ISSET(fd, &fd_read))
	{
	  cmd = get_msg(fd);
	  if (execLoadingCmd(cmd, world) == 0)
	    loading = 0;
	}
    }
  return (1);
}
