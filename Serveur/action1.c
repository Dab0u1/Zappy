#include "cmd.h"

t_serveur	*cmdfront(t_serveur *s, int fd)
{
  printf("ppo #n=%d X=%d Y=%d O=?\n", s->ctab->id, s->ctab->x, s->ctab->y /*, s->ctab->id*/);
}

t_serveur	*cmdright(t_serveur *s, int fd)
{
  printf("ppo #n=%d X=%d Y=%d O=?\n", s->ctab->id, s->ctab->x, s->ctab->y /*, s->ctab->id*/);
}

t_serveur	*cmdleft(t_serveur *s, int fd)
{
  printf("ppo #n=%d X=%d Y=%d O=?\n", s->ctab->id, s->ctab->x, s->ctab->y /*, s->ctab->id*/);
}

t_serveur	*cmdsee(t_serveur *s, int fd)
{
  printf("tu vois gros!\n");
}

t_serveur	*cmdinv(t_serveur *s, int fd)
{
}
