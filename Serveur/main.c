/*
** main.c for main in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:27:30 2014 david vallee
** Last update Fri Jul  4 15:47:43 2014 david vallee
*/

#include "serveur.h"

int		get_option(t_option *option, int ac, char **av)
{
  // Init des valeur par defaut

  option->port = 4242;
  option->worldX = 20;
  option->worldY = 20;
  option->team = 0; // faire liste chainé de team 
  option->maxClientbyTeam = 5;
  option->t = 100;

  // Ici Faire tableau de pointeur sur fonction pour parsser les options retourn -1 en cas d'erreur

  return (0);
}

int		main(int ac, char **av)
{
  t_option option;

  if (get_option(&option, ac, av) == -1)
    return (0);
  serveur(option);
  return (0);
}
