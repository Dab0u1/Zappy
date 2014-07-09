#ifndef CMD_H_
# define CMD_H_

#include "serveur.h"

# define FRONT 0
# define RIGHT 1
# define LEFT 2
# define SEE 3
# define INV 4
# define TAKE 5
# define LET 6
# define KICK 7
# define BROAD 8
# define INC 9
# define FORK 10
# define SLOT 11
# define DEAD 12

t_serveur	*(*ptrfunc[13])(t_serveur *, int);

t_serveur	*cmdfront(t_serveur *, int);
t_serveur	*cmdright(t_serveur *, int);
t_serveur	*cmdleft(t_serveur *, int);
t_serveur	*cmdsee(t_serveur *, int);
t_serveur	*cmdtake(t_serveur *, int);
t_serveur	*cmdinv(t_serveur *, int);
t_serveur	*cmdlet(t_serveur *, int);
t_serveur	*cmdkick(t_serveur *, int);
t_serveur	*cmdbroad(t_serveur *, int);
t_serveur	*cmdinc(t_serveur *, int);
t_serveur	*cmdfork(t_serveur *, int);
t_serveur	*cmdslot(t_serveur *, int);
t_serveur	*cmddie(t_serveur *, int);

#endif /* !CMD_H_ */
