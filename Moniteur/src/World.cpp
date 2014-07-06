//
// World.cpp for World in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 20:07:10 2014 david vallee
// Last update Sun Jul  6 05:30:21 2014 david vallee
//

#include "World.hpp"

World::World()
{

}

World::~World()
{

}

void	World::setSizeX(int x)
{
  sizeX = x;
}

void	World::setSizeY(int y)
{
  sizeY = y;
}

int	World::getSizeX()
{
  return (sizeX);
}

int	World::getSizeY()
{
  return (sizeY);
}

void	World::setFdServer(int fd)
{
  fdServer = fd;
}

int	World::getFdServer()
{
  return (fdServer);
}
