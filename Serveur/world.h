//
// world.h for world in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 17:53:13 2014 david vallee
// Last update Sat Jul  5 19:56:14 2014 david vallee
//

#ifndef WORLD_H_
# define WORLD_H_

typedef struct		s_cell
{
  int			type;
  struct s_cell		*next;
}			t_cell;

typedef struct		s_World
{
  int			sizeX;
  int			sizeY;
  int			team;
  int			t;
  t_cell		**map;
}			t_world;

#endif /* !WORLD_H_ */
