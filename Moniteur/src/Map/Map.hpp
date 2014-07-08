//
// Map.hpp for Map in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Tue Jul  8 14:19:43 2014 david vallee
// Last update Tue Jul  8 15:48:32 2014 david vallee
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <iostream>

typedef struct	s_cell
{
  int		type;
  struct s_cell	*next;
}		t_cell;

typedef struct	s_map
{
  int		sizeX;
  int		sizeY;
  t_cell	***cell;
}			t_map;

class		Map
{
private:
  int		sizeX;
  int		sizeY;
  t_map		*map;

public:
  Map();
  ~Map();
  int		init(int x, int y);
  int		pushElem(int x, int y, int t);
  int		getSizeX() const;
  int		getSizeY() const;
  void		showCell(t_map *, int, int);
  void		showMap();
  t_cell	*get_cell(int x, int y);
  int		delElem(t_map *, int x, int y,int type);
  void		draw();

private:
  int		del_mid(t_cell *);
  int		del_end(t_cell *);
};

#endif /* !MAP_HPP_ */
