//
// world.h for world in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 17:53:13 2014 david vallee
// Last update Sun Jul  6 21:31:59 2014 david vallee
//

#ifndef WORLD_H_
# define WORLD_H_

# include "Map/Map.h"
# include "team.h"


typedef struct		s_World
{
  t_map			*map;
  t_team		*team;
  int			t;
}			t_world;

#endif /* !WORLD_H_ */
