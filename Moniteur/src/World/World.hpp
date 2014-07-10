//
// World.hpp for World in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 20:11:52 2014 david vallee
// Last update Thu Jul 10 16:08:12 2014 david vallee
//

#ifndef WORLD_HPP_
# define WORLD_HPP_

# include "../network/network.h"
# include "../Map/Map.hpp"
# include "../Players/Players.hpp"

# define MAX_REQUETE_BY_UPDATE 100

class	World
{  
public:
  Map		map;
  Players	players;

private:
  int		fdServer;

public:
  World();
  ~World();
  void	setFdServer(int);
  int	getFdServer();
  int	load();
  int	update();

private:
  int		get_msz(std::string str, int *x, int *y);
  int		get_val(const char *str, int *i);
  int		push_bct(std::string bct);
  int		push_player(std::string pnw);
  int		execCmd(std::string cmd);
  t_player	*getPnw(std::string cmd);
  int	        parse_pnw(std::string cmd, int *a);
  std::string	parse_pnw_team(std::string cmd, int *a);
  int		getintarg(std::string str);
};



#endif /* !WORLD_HPP_ */
