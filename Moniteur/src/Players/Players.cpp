//
// Players.cpp for Players in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src/Players
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Wed Jul  9 09:40:07 2014 david vallee
// Last update Thu Jul 10 16:09:01 2014 david vallee
//

#include <iostream>
#include "Players.hpp"

Players::Players()
{
  players = new t_player *;
  *players = NULL;
}

Players::~Players()
{
}

int	Players::newPlayer(t_player *p)
{
  p->next = *players;
  *players = p;
  return (0);
}

int		Players::del_end(t_player *tmp)
{
  t_player	*tmpfree;

  tmpfree = tmp->next;
  tmp->next = NULL;
  delete tmpfree;
  return (0);
}

int		Players::del_mid(t_player *tmp)
{
  t_player	*tmpfree;

  tmpfree = tmp->next;
  tmp->next = tmp->next->next;
  delete tmpfree;
  return (0);
}

int	Players::delPlayer(int id)
{  
  t_player	*tmp;

  if ((tmp = *players) == NULL)
    return (-1);
  if (tmp->id == id)
    {
      *players = tmp->next;
      delete tmp;
      return (0);
    }
  while (tmp->next != NULL && tmp->next->id != id)
    tmp = tmp->next;
  if (tmp->next == NULL)
    {
      if (tmp->next->id != id)
	return (-1);
      return (del_end(tmp));
    }
  return (del_mid(tmp));
}

t_player	*Players::getPlayer()
{
  return (*players);
}
