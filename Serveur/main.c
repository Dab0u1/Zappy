/*
** main.c for main in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:27:30 2014 david vallee
** Last update Sun Jul  6 21:17:32 2014 david vallee
*/

#include "serveur.h"

int		main(int ac, char **av)
{
  t_option option;

  if (get_option(&option, ac, av) == -1)
    return (0);
  serveur(&option);
  return (0);
}
