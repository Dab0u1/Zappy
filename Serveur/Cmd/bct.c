/*
** bct.c for bct in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Cmd
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Mon Jul  7 07:49:06 2014 david vallee
** Last update Wed Jul  9 21:44:11 2014 david vallee
*/

#include "../serveur.h"

int		map_len(t_map *map, int x, int y)
{
  int		i;
  t_cell	*tmp;

  i = 0;
  tmp = *map->cell[y * map->sizeX + x];
  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}

int		int_len(int n)
{
  int		l;

  l = 0;
  while (n > 0)
    {
      n /= 10;
      ++l;
    }
  return (l);
}

int		bct(int fd, t_map *map, int x, int y)
{
  char		*msg;
  int		len;
  t_cell	*tmp;
  int		r;
  char		buff[3];

  len = 4 + int_len(x) + 1 + int_len(y) + 1 + map_len(map, x, y) + 2;
  if ((msg = malloc(sizeof(char) * len)) == NULL)
    return (-1);
  sprintf(msg, "bct %d %d", x, y);
  tmp = *(map->cell[y * map->sizeX + x]);
  while (tmp)
    {
      buff[0] = ' ';
      buff[1] = tmp->type + '0';
      buff[2] = '\0';
      strcat(msg, buff);
      tmp = tmp->next;
    }
  buff[0] = '\n';
  buff[1] = '\0';
  strcat(msg, buff);
  r = send_msg(fd, msg);
  free(msg);
  return (r);
}

int		bct_all_map(int fd, t_map *map)
{
  int		x;
  int		y;

  x = 0;
  while (x < map->sizeX)
    {
      y = 0;
      while (y < map->sizeY)
	{
	  bct(fd, map, x, y);
	  y++;
	}
      x++;
    }
  return (0);
}

