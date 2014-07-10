/*
** monitorList.c for monitorList in /home/vallee_c/rendu/PSU_2013_zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed Jul  9 20:07:48 2014 david vallee
** Last update Thu Jul 10 14:35:52 2014 david vallee
*/

#include "../serveur.h"

int	new_monitor(t_monitor **list, int fd)
{
  t_monitor *elem;

  if ((elem = malloc(sizeof(t_monitor))) == NULL)  
    return (-1);
  elem->fd = fd;
  elem->next = *list;
  *list = elem;
  return (0);
}

int	del_monitor(t_monitor **list, int fd)
{
  return (0);
}

void	show_Monitor(t_monitor *tmp)
{
  while (tmp)
    {
      printf("%d, ", tmp->fd);
      tmp = tmp->next;
    }
  printf("%s", "\n");
}
