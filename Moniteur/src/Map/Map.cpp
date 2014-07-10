//
// Map.cpp for Map in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Tue Jul  8 14:21:47 2014 david vallee
// Last update Thu Jul 10 02:20:15 2014 david vallee
//

#include "Map.hpp"

Map::Map()
{

}

Map::~Map()
{

}

int	Map::init(int x, int y)
{  
  int		i;

  if ((this->map = new t_map()) == NULL ||
      (this->map->cell = new t_cell **[x * y]) == NULL)
    return (-1);
  this->map->sizeX = x;
  this->map->sizeY = y;
  i = 0;
  while (i < (x * y))
    {
      if ((this->map->cell[i] = new t_cell *) == NULL)
	return (-1);
      *(this->map->cell[i]) = NULL;
      ++i;
    }
  return (0);
}

int	Map::pushElem(int x, int y, int t)
{
  t_cell	*elem;
  
  elem = new t_cell;
  elem->type = t;
  elem->next = *(map->cell[y * map->sizeX + x]);
  *(map->cell[y * map->sizeX + x]) = elem;
  return (0);
}

int	Map::getSizeX() const
{
  return (map->sizeX);
}

int	Map::getSizeY() const
{
  return (map->sizeY);
}

t_cell		*Map::get_cell(int x, int y)
{
  return (*map->cell[y * map->sizeX + x]);
}

void		Map::showCell(t_map *map, int x, int y)
{
  t_cell	*tmp;

  std::cout << "X : " << x << " - Y : " << y << " ->";
  tmp = *map->cell[y * map->sizeX + x];
  while (tmp)
    {
      std::cout << " " << tmp->type;
      tmp = tmp->next;
    }
  std::cout << std::endl;
}

void		Map::showMap()
{
  int		x;
  int		y;

  x = 0;
  while(x < map->sizeX)
    {
      y = 0;
      while (y < map->sizeY)
	{
	  showCell(map, x, y);
	  ++y;
	}
      ++x;
    }
}

int		Map::del_end(t_cell *tmp)
{
  t_cell	*tmpfree;

  tmpfree = tmp->next;
  tmp->next = NULL;
  delete tmpfree;
  return (0);
}

int		Map::del_mid(t_cell *tmp)
{
  t_cell	*tmpfree;

  tmpfree = tmp->next;
  tmp->next = tmp->next->next;
  delete tmpfree;
  return (0);
}

int		Map::delElem(t_map *map, int x, int y, int type)
{
  t_cell	*tmp;

  if ((tmp = *map->cell[y * map->sizeX + x]) == NULL)
    return (-1);
  if (tmp->type == type)
    {
      *map->cell[y * map->sizeX + x] = tmp->next;
      delete (tmp);
      return (0);
    }
  while (tmp->next != NULL && tmp->next->type != type)
    tmp = tmp->next;
  if (tmp->next == NULL)
    {
      if (tmp->next->type != type)
	return (-1);
      return (del_end(tmp));
    }
  return (del_mid(tmp));
}
