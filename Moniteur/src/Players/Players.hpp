//
// Players.hpp for Players in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src/Players
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Wed Jul  9 09:40:12 2014 david vallee
// Last update Thu Jul 10 16:06:56 2014 david vallee
//

#ifndef PLAYERS_HPP_
# define PLAYERS_HPP_

# include <string>

typedef struct		s_player
{
  int			id;
  int			x;
  int			y;
  int			o;
  int			l;
  std::string		team;
  int			anime;
  float			time;
  struct s_player	*next;
}			t_player;

class			Players
{
private:
  t_player		**players;

public:
  Players();
  ~Players();

  int			newPlayer(t_player *player);
  int			delPlayer(int id);
  t_player		*getPlayer();
  int			del_mid(t_player *tmp);
  int			del_end(t_player *tmp);
};

#endif /* !PLAYERS_HPP_ */
