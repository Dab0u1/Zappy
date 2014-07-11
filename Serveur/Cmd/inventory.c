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

t_serveur	*add_inv(t_serveur *s, int fd, char *buff)
{
  t_cell	*cell;
  int		type;

  cell = get_cell(s->map, s->ctab[fd].x, s->ctab[fd].y);
  type = atoi(buff);
  // Rajouter message moniteur
  // printf("pgt #%d %d\n", s->ctab[fd].id, type);
  while (cell)
    {
      if (cell->type == type)
	s->ctab[fd].inv[cell->type] += 1;
      cell = cell->next;
    }
  del_elem_in_map(s->map, s->ctab[fd].x, s->ctab[fd].x, cell->type);
  return (s);
}

t_serveur	*rm_inv(t_serveur *s, int fd, char *buff)
{
  int		type;

  type = atoi(buff);
  // Rajouter message moniteur
  // printf("pdr #%d %d\n", s->ctab[fd].id, type);
  while (s->ctab[fd].inv[type] != 0)
    {
      s->ctab[fd].inv[type] -= 1;
      put_in_map(s->map, s->ctab[fd].x, s->ctab[fd].x, type);
    }
  return (s);
}
