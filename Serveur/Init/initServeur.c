/*
** init.c for init in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:22:42 2014 david vallee
** Last update Thu Jul 10 15:10:53 2014 david vallee
*/

#include "../serveur.h"

int		getnbTeam(t_team *tmp)
{
  int	i;
  i = 0;

  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}

int		init_serveur(t_serveur *s, t_option *option)
{
  struct sockaddr_in	sin;
  int		i;

  s->idmax = 0;
  s->isRuning = 1;
  if ((s->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(option->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  s->fd_max = s->fd;
  s->fdMonitor = NULL;
  bind(s->fd, (struct sockaddr*)&sin, sizeof(sin));
  listen(s->fd, 42);
  s->maxClientbyTeam = option->maxClientbyTeam;
  s->maxClient = getnbTeam(option->team) * option->maxClientbyTeam + MAXMONITOR;
  if ((s->ctab = malloc(sizeof(t_client) * s->maxClient)) == NULL)
    return (1);
  i = 0;
  while (i < s->maxClient)
    {
      s->ctab[i].type = FREE;
      ++i;
    }
  s->map = GenerateMap(option->worldX, option->worldY);
  s->team = option->team;
  s->t = option->t;
  initcmd();
  return(0);
}
