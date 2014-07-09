#include "cmd.h"

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
  int		i;
  char          opt_tab[12][15] =
    {
      "avance",
      "droite",
      "gauche",
      "voir\n",
      "inventaire",
      "prend objet",
      "pose objet",
      "expulse",
      "broadcast texte",
      "incantation",
      "fork",
      "connect_nbr"
    };
  i = 0;
  while (i < 13 && (strcmp(buff, opt_tab[i]) != 0))
    i++;
  return (i);
}

void	parsecmd(char *buff, t_serveur *s, int fd)
{
  int	action;

  action = findcmd(buff);
  printf("commande numero %d\n", action);
  initcmd();
  if (action < 13)
    (*(ptrfunc[action]))(s, fd);
}
