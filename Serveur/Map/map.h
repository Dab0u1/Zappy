//
// Map.h for Map in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Map
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sun Jul  6 21:29:18 2014 david vallee
// Last update Sun Jul  6 23:44:38 2014 david vallee
//

#ifndef MAP_H_
# define MAP_H_

typedef struct		s_cell
{
  int			type;
  struct s_cell		*next;
}			t_cell;

typedef struct		s_map
{
  int			sizeX;
  int			sizeY;
  t_cell		***cell;
}			t_map;

t_map		*GenerateMap(int x, int y);
void		showCell(t_map *, int, int);
void		showMap(t_map *);
t_cell		*get_cell(t_map *map, int x, int y);
int		put_in_map(t_map *map, int x, int y, int type);
int		del_elem_in_map(t_map *, int x, int y,int type);

#endif /* !MAP_H_ */
