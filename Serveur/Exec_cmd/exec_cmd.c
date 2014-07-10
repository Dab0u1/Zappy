/*
** exec_cmd.c for exec_cmd in /home/vallee_c/rendu/MergeZappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Thu Jul 10 14:20:11 2014 david vallee
** Last update Thu Jul 10 15:01:39 2014 david vallee
*/

#include "../serveur.h"

int	exec_cmd(t_serveur *s, int fd, char *cmd)
{
  t_team *tmp = s->team;

  while (tmp)
    {
      if (strncmp(cmd, tmp->data, strlen(cmd) - 1) == 0)
	{
	  initClient(s, fd, tmp->data);
	  return (0);
	}
      tmp = tmp->next;
    }
  if (strncmp(cmd, "GRAPHICS", 8) == 0)
    {
      new_monitor(&s->fdMonitor, fd);
      show_Monitor(s->fdMonitor);
      s->ctab[fd].type = MONITEUR;
      initGraphMonitor(s, fd);
      return (0);
    }    
  parsecmd(cmd, s, fd);
  return (0);
}
