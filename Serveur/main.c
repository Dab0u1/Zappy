/*
** main.c for main in /home/vallee_c/Zappy/Serveur
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 14:27:30 2014 david vallee
** Last update Sun Jul  6 15:09:11 2014 gonon_c
*/

#include "serveur.h"

int		find_opt(char *buf)
{
  int		i;
  char		opt_tab[6][5] =
    {
      "-p",
      "-x",
      "-y",
      "-n",
      "-c",
      "-t",
    };
  i = 0;
  while (i < 6 && (strcmp(buf, opt_tab[i]) != 0))
    ++i;
  return (i);
}

int		print_rules(int	*bool)
{
  if (*bool == 0)
    {
      printf("invalid option, -n [team name] -p [port] -x [weight]");
      printf("-y [height] -c[group capacity] -t [frequency]\n");
      *bool = 1;
    }
  return (0);
}

int		exec_opt(t_option *option,int ac, char **av)
{
  int           (*funct_tab[6])(t_option *option, char **av, int *i) =
    {
      &opt_p,
      &opt_x,
      &opt_y,
      &opt_n,
      &opt_c,
      &opt_t
    };
  int		i;
  int		j;
  int		bool;
  
  i = 1;
  bool = 0;
  while (i < ac)
    {
      j = find_opt(av[i]);
      if (j >= 6) 
	print_rules(&bool);
      else
	  funct_tab[j](option, av, &i);
      ++i;
    }
  return (0);
}

int		get_option(t_option *option, int ac, char **av)
{
  option->port = 4242;
  option->worldX = 20;
  option->worldY = 20;
  option->team = NULL;
  option->maxClientbyTeam = 5;
  option->t = 100;
  exec_opt(option, ac, av);
  return (0);
}

int		main(int ac, char **av)
{
  t_option option;

  if (get_option(&option, ac, av) == -1)
    return (0);
  serveur(&option);
  return (0);
}
