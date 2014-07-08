//
// World.hpp for World in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 20:11:52 2014 david vallee
// Last update Tue Jul  8 15:03:08 2014 david vallee
//

#ifndef WORLD_HPP_
# define WORLD_HPP_

# include "Map/Map.hpp"

class	World
{  
public:
  Map	map;

private:
  int	fdServer;

public:
  World();
  ~World();
  int	init(int x, int y);
  int	pushElemMap(int x, int y, int t);
  void	setSizeX(int);
  void	setSizeY(int);
  int	getSizeX();
  int	getSizeY();
  void	setFdServer(int);
  int	getFdServer();
};

int	load(World &world);

#endif /* !WORLD_HPP_ */
