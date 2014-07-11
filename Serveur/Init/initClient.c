/*
** initClient.c for initClient in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed Jul  9 12:52:39 2014 david vallee
** Last update Thu Jul 10 17:22:41 2014 david vallee
*/

#include "../serveur.h"

int	team_to_int(t_team *tmp, char *team)
{
  int	i;

  i = 0;
  while (tmp && strcmp(tmp->data, team) != 0)
    {
      ++i;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return (-1);
  return (i);
}

int	count_client_in_team(int team, t_serveur *s)
{
  int	t;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < (s->maxClient))
    {
      if (s->ctab[i].type == CLIENT && s->ctab[i].team == t)
	j++;
      ++i;
    }
  return (s->maxClientbyTeam - j);
}

int	initClient(t_serveur *s, int fd, char *team)
{
  int	t;
  int	num_client;
  char	msg[255];

  t = team_to_int(s->team, team);
  num_client = count_client_in_team(t, s);
  if (num_client == 0)
    send_msg(fd, "0\n");
  else
    {
      s->ctab[fd].id = s->idmax;
      s->idmax++;
      s->ctab[fd].type = CLIENT;
      sprintf(msg, "%d\n", num_client);
      send_msg(fd, msg);
      sprintf(msg, "%d %d\n", s->map->sizeX, s->map->sizeY);
      printf("%s\n", msg);
      send_msg(fd, msg);
      s->ctab[fd].x = rand() % s->map->sizeX;
      s->ctab[fd].y = rand() % s->map->sizeX;
      s->ctab[fd].o = rand() % 4 + 1;
      s->ctab[fd].lvl = 1;
      s->ctab[fd].team = t;
      s->ctab[fd].inv = init_inv(s, fd);
      pnw_to_all_monitor(s, fd);
    }
  return (0);
}
