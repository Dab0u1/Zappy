#include "../serveur.h"

void	pbc(t_serveur *s, int fd, char *buff)
{
  // Trop Naze
  printf("pbc #");
  send_msgToAll_Client(s, buff);
}
