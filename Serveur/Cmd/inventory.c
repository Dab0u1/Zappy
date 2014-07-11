#include "../serveur.h"

int		*init_inv(t_serveur *s, int fd)
{
  int		n;

  s->ctab[fd].inv = malloc(sizeof(int *));
  n = 0;
  while (n <= NBR_RES)
    {
      s->ctab[fd].inv[n] = 0;
      n++;
    }
  return (s->ctab[fd].inv);
}

void		show_inv(int *inv)
{
  int		n;
  int		*res;

  n = 0;
  while (n <= NBR_RES)
    {
      printf("%d\n", inv[n]);
      n++;
    }
}

t_serveur	*add_inventory(t_serveur *s, int fd)
{
  t_cell	*cell;

  cell = get_cell(s->map, s->ctab[fd].x, s->ctab[fd].y);
  while (cell)
    {
      s->ctab[fd].inv[cell->type] += 1;
      del_elem_in_map(s->map, s->ctab[fd].x, s->ctab[fd].x, cell->type);
      cell = cell->next;
    }
  return (s);
}

t_serveur	*rm_inventory(t_serveur *s, int fd, char *buff)
{
  int		n;

  n = atoi(buff);
  while (s->ctab[fd].inv[n] != 0)
    {
      put_in_map(s->map, s->ctab[fd].x, s->ctab[fd].x, n);
      s->ctab[fd].inv[n] -= 1;
    }
  return (s);
}
