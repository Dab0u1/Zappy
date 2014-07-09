#include "cmd.h"

t_serveur	*cmdtake(t_serveur *s, int fd)
{
  printf("pgt #n i\n");
  printf("pin #n X Y q q q q q q q\n");
  printf("bct X Y q q q q q q q\n");
}

t_serveur	*cmdlet(t_serveur *s, int fd)
{
  printf("pdr #n i\n");
  printf("pin #n X Y q q q q q q q\n");
  printf("bct X Y q q q q q q q\n");
}

t_serveur	*cmdkick(t_serveur *s, int fd)
{
  printf("pex #n\n");
  printf("ppo #n X Y O\n");
  //......
  printf("ppo #n X Y O\n");
}

t_serveur	*cmdbroad(t_serveur *s, int fd)
{
  printf("pbc #n M\n");
}

t_serveur	*cmdinc(t_serveur *s, int fd)
{
  printf("pic X Y L #n #n ...\n");
}
