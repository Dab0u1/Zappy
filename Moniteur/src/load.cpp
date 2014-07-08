//
// load.cpp for load in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 19:00:11 2014 david vallee
// Last update Tue Jul  8 15:27:38 2014 david vallee
//

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "World.hpp"
#include "../network/network.h"

int	get_msz(std::string str, int *x, int *y)
{
  int		pos;
  int		pos2;
  std::string	sizex;
  std::string	sizey;

  pos = str.find(" ", 4);
  sizex = str.substr(4, pos);
  pos2 = str.find("\n", pos);
  sizey = str.substr(pos, pos2);
  std::stringstream ss(sizex);
  std::stringstream ss2(sizey);
  ss >> *x;
  ss2 >> *y;
  return (0);
}

int	get_val(const char *str, int *i)
{
  char	buff[20];
  int	j;
  int	r;

  j = 0;
  while (str[*i] && str[*i] != ' ' && str[*i] != '\n')
    {
      buff[j] = str[*i];
      *i = *i + 1;
      ++j;
    }
  buff[j] = '\0';
  r = atoi(buff);
  return (r);
}

int		push_bct(std::string bct, Map &map)
{
  const char	*str;
  int		i;
  int		x;
  int		y;
  int		type;

  std::cout << bct << std::endl;
  str = bct.c_str();
  i = 0;
  while (str[i])
    {
      i += 4;
      x = get_val(str, &i);
      ++i;
      y = get_val(str, &i);
      while (str[i] != '\n' && str[i] == ' ')
	{
	  ++i;
	  type = get_val(str, &i);
	  map.pushElem(x, y, type);
	}
      ++i;
    }
  std::cout << map.getSizeX() << " " << x << std::endl;
  if (map.getSizeX() == (x + 1) && map.getSizeY() == (y + 1))
    return (0);
  return (1);
}

int	execLoadingCmd(std::string cmd, Map &map)
{
  if (cmd.compare(0, 4, "msz ") == 0)
    {
      int a = 0;
      int b = 0;
      get_msz(cmd, &a, &b);
      map.init(a, b);
      return (1);
    }
  if (cmd.compare(0, 4, "bct ") == 0)
    {
      if (push_bct(cmd, map) == 0)
	return (0);
    }
  return (1);
}

int		load(World &world)
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
	  if (execLoadingCmd(cmd, world.map) == 0)
	    {
	      world.map.showMap();
	      loading = 0;
	    }
	}
    }
  return (1);
}
