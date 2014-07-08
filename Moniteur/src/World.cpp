//
// World.cpp for World in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 20:07:10 2014 david vallee
// Last update Tue Jul  8 14:47:24 2014 david vallee
//

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
