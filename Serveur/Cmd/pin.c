#include "../serveur.h"

void	pin(t_serveur *s, int fd)
{
  int	n;

  n = 0;
  printf("pin #%d %d %d", s->ctab[fd].id, s->ctab[fd].x, s->ctab[fd].y);
  while (n <= NBR_RES)
    {
      printf(" %d", s->ctab[fd].inv[n]);
      n++;
    }
  printf("\n");
}
