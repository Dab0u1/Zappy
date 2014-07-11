#include "cmd.h"

t_serveur	*cmdtake(t_serveur *s, int fd, char *buff)
{
  printf("pgt #n i\n");
  printf("pin #n X Y q q q q q q q\n");
  //printf("bct X Y q q q q q q q\n");
  bct(fd, s->map, s->ctab->x, s->ctab->y);
}

t_serveur	*cmdlet(t_serveur *s, int fd, char *buff)
{
  printf("pdr #n i\n");
  printf("pin #n X Y q q q q q q q\n");
  //printf("bct X Y q q q q q q q\n");
  bct(fd, s->map, s->ctab->x, s->ctab->y);
}

t_serveur	*cmdkick(t_serveur *s, int fd, char *buff)
{
  printf("pex #n\n");
  //pex(s->);
  ppo(s, fd);
}

t_serveur	*cmdbroad(t_serveur *s, int fd, char *buff)
{
  send_msgToAll_Client(s, buff);
  printf("pbc #n M\n");
}

t_serveur	*cmdinc(t_serveur *s, int fd, char *buff)
{
  printf("pic X Y L #n #n ...\n");
}
