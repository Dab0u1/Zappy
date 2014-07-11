#include "cmd.h"

t_serveur	*cmdfront(t_serveur *s, int fd, char *buff)
{
  if (s->ctab[fd].o == 1)
    ++s->ctab[fd].x;
  else if (s->ctab[fd].o == 2)
    ++s->ctab[fd].y;
  else if (s->ctab[fd].o == 3)
    --s->ctab[fd].x;
  else if (s->ctab[fd].o == 4)
    --s->ctab[fd].y;
  ppo(s, fd);
}

t_serveur	*cmdright(t_serveur *s, int fd, char *buff)
{
  if (s->ctab[fd].o < 4)
    ++s->ctab[fd].o;
  else if (s->ctab[fd].o == 4)
    s->ctab[fd].o = 1;
  ppo(s, fd);
}

t_serveur	*cmdleft(t_serveur *s, int fd, char *buff)
{
  if (s->ctab[fd].o > 0)
    --s->ctab[fd].o;
  if (s->ctab[fd].o == 0)
    s->ctab[fd].o = 4;
  ppo(s, fd);
}

t_serveur	*cmdsee(t_serveur *s, int fd, char *buff)
{
  printf("tu vois gros!\n");
}

t_serveur	*cmdinv(t_serveur *s, int fd, char *buff)
{
  // Rajouter commandes affichage
  show_inv(s->ctab[fd].inv);
}
