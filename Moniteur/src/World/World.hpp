//
// World.hpp for World in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 20:11:52 2014 david vallee
// Last update Wed Jul  9 21:50:43 2014 david vallee
//

#ifndef WORLD_HPP_
# define WORLD_HPP_

# include "../network/network.h"
# include "../Map/Map.hpp"

# define MAX_REQUETE_BY_UPDATE 100

class	World
{  
public:
  Map		map;
  // Players	players;

private:
  int	fdServer;

public:
  World();
  ~World();
  void	setFdServer(int);
  int	getFdServer();
  int	load();
  int	update();

private:
  int	get_msz(std::string str, int *x, int *y);
  int	get_val(const char *str, int *i);
  int	push_bct(std::string bct);
  int	push_player(std::string pnw);
  int	execCmd(std::string cmd);
};



#endif /* !WORLD_HPP_ */
