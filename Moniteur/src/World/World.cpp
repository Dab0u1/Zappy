//
// World.cpp for World in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 20:07:10 2014 david vallee
// Last update Thu Jul 10 01:29:53 2014 david vallee
//

#include <sstream>
#include <cstdio>
#include "World.hpp"

World::World()
{

}

World::~World()
{

}

void	World::setFdServer(int fd)
{
  fdServer = fd;
}

int	World::getFdServer()
{
  return (fdServer);
}

int		World::get_msz(std::string str, int *x, int *y)
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

int	World::get_val(const char *str, int *i)
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
  std::stringstream ss(buff);
  ss >> r;
  return (r);
}

int		World::push_bct(std::string bct)
{
  const char	*str;
  int		i;
  int		x;
  int		y;
  int		type;

  if ((str = bct.c_str()) == NULL)
    return (0);  
  i = 4;
  x = get_val(str, &i);
  ++i;
  y = get_val(str, &i);
  while (str[i] && str[i] != '\n' && str[i] == ' ')
    {
      ++i;
      type = get_val(str, &i);
      map.pushElem(x, y, type);
    }
  return (0);
}

int		World::push_player(std::string pnw)
{
  return (0);
}

int	World::execCmd(std::string cmd)
{
  if (cmd.compare(0, 4, "bct ") == 0)
    push_bct(cmd);
  else if (cmd.compare(0, 4, "pnw ") == 0)
    std::cout << cmd << std::endl;
  return (1);
}

int		World::load()
{
  std::string   cmd;
  int		r;

  r = get_msg(fdServer, cmd);
  if (r <= 0)
    return (0);
  if (cmd.compare(0, 4, "msz ") == 0)
    {
      int a = 0;
      int b = 0;
      get_msz(cmd, &a, &b);
      map.init(a, b);
      return (1);
    }
  if (cmd.compare(0, 4, "pnw ") == 0)
    {
      std::cout << cmd << std::endl;
    }
  return (0);
}

int		World::update()
{
  std::string		cmd;
  int			r;

  if ((r = get_msg(fdServer, cmd)) == 0)
    return (0);
  else if (r == -1)
    return (-1);
  execCmd(cmd);
  return (1);
}
