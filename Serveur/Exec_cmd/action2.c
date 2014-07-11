#include "cmd.h"

t_serveur	*cmdtake(t_serveur *s, int fd, char *buff)
{
  add_inv(s, fd, buff);
  //pgt(s, fd, buff);
  pin(s, fd);
  bct(fd, s->map, s->ctab->x, s->ctab->y);
}

t_serveur	*cmdlet(t_serveur *s, int fd, char *buff)
{
  rm_inv(s, fd, buff);
  //pdr(s, fd, buff);
  pin(s, fd);
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
  //printf("pbc #n M\n");
  //pbc(s, fd, buff);
  //send_msgToAll_Client(s, buff);
}

t_serveur	*cmdinc(t_serveur *s, int fd, char *buff)
{
  //printf("pic X Y L #n #n ...\n");
}
