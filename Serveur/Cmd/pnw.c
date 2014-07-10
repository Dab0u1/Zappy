/*
** pnw.c for pnw in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Cmd
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed Jul  9 12:37:06 2014 david vallee
** Last update Thu Jul 10 16:19:08 2014 david vallee
*/

#include <stdio.h>
#include "../serveur.h"

int	getTeam(int t, t_serveur *s, char *buf)
{
  t_team	*tmp;
  int		i;

  i = 0;
  tmp = s->team;
  while (tmp && i < t)
    {
      ++i;
      tmp = tmp->next;
    }
  if (tmp && tmp->data != NULL)
    sprintf(buf, "%s\n", tmp->data);
  else
    sprintf(buf, "%s\n", "NULL");
  return (0);
}

int	pnw(int fdClient, t_serveur *s, int fdMonitor)
{
  char		buf[255];
  char		team[255];
  t_client	*c;

  c = &s->ctab[fdClient];
  getTeam(c->team, s, team);
  sprintf(buf, "pnw #%d %d %d %d %d %s\n", c->id, c->x, c->y, c->o, c->lvl, team);
  send_msg(fdMonitor, buf);
  return (0);
}

int	pnw_all_to_one_monitor(t_serveur *s, int fdMonitor)
{
  int	i;

  i = 0;
  while (i < s->maxClient)
    {
      if (s->ctab[i].type == CLIENT)
	pnw(i, s, fdMonitor);
      ++i;
    }
  return (0);
}

int	pnw_all_to_all_monitor(t_serveur *s)
{
  int	i;
  t_monitor *tmp;

  i = 0;
  while (i < s->maxClient)
    {
      if (s->ctab[i].type == CLIENT)
	{
	  tmp = s->fdMonitor;
	  while (tmp)
	    {
	      pnw(i, s, tmp->fd);
	      tmp = tmp->next;
	    }
	}
      ++i;
    }
  return (0);
}

int	pnw_to_all_monitor(t_serveur *s, int fd)
{
  t_monitor *tmp;
  
  tmp = s->fdMonitor;
  while (tmp)
    {
      pnw(fd, s, tmp->fd);
      tmp = tmp->next;
    }
  return (0);
}
