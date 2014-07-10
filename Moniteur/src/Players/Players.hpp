//
// Players.hpp for Players in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src/Players
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Wed Jul  9 09:40:12 2014 david vallee
// Last update Thu Jul 10 01:33:28 2014 david vallee
//

#ifndef PLAYERS_HPP_
# define PLAYERS_HPP_

#include <vector>

class		player
{
private:
  int		x;
  int		y;
  int		o;
  int		l;
  std::string	team;

public:
  player(int, int ,int ,int, std::string);
  ~player();

  int		getX() const;
  int		getY() const;
  int		getO() const;
  int		getL() const;
  int		getTeam() const;
  int		setall(int, int ,int ,int, std::string);
};

class	Players
{
private:
  std::vector<t_player> players;

public:
  Players();
  ~Players();

  int	newPlayers(int id, );
  int	delPlayers(int id);
};

#endif /* !PLAYERS_HPP_ */
