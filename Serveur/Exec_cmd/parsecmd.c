#include "cmd.h"

static t_serveur	*(*ptrfunc[NB_CMD])(t_serveur *, int);

static char          opt_tab[12][16] =
  {
    "avance\n",
    "droite\n",
    "gauche\n",
    "voir\n",
    "inventaire\n",
    "prend objet\n",
    "pose objet\n",
    "expulse\n",
    "broadcast texte\n",
    "incantation\n",
    "fork\n",
    "connect_nbr\n"
  };

void	initcmd(void)
{
  ptrfunc[FRONT] = &cmdfront;
  ptrfunc[RIGHT] = &cmdright;
  ptrfunc[LEFT] = &cmdleft;
  ptrfunc[SEE] = &cmdsee;
  ptrfunc[INV] = &cmdinv;
  ptrfunc[TAKE] = &cmdtake;
  ptrfunc[LET] = &cmdlet;
  ptrfunc[KICK] = &cmdkick;
  ptrfunc[BROAD] = &cmdbroad;
  ptrfunc[INC] = &cmdinc;
  ptrfunc[FORK] = &cmdfork;
  ptrfunc[SLOT] = &cmdslot;
  ptrfunc[DEAD] = &cmddie;
}

int	findcmd(char *buff)
{
  int	i;

  i = 0;
  while (i < (NB_CMD + 1) && (strcmp(buff, opt_tab[i]) != 0))
    i++;
  return (i);
}

void	parsecmd(char *buff, t_serveur *s, int fd)
{
  int	action;

  action = findcmd(buff);
  printf("commande numero %d\n", action);
  if (action < NB_CMD)
      (*(ptrfunc[action]))(s, fd);
}
