//
// exec_opt.cpp for ZAP in /home/gonon_c/rendu/Zappy/Moniteur
// 
// Made by gonon_c
// Login   <gonon_c@epitech.net>
// 
// Started on  Sun Jul  6 18:54:41 2014 gonon_c
// Last update Sun Jul  6 19:54:36 2014 david vallee
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "option.h"

int		find_opt(char *buf)
{
  int		i;
  char		opt_tab[5][4] =
    {
      "-p",
      "-y",
      "-x",
      "-f",
      "-h",
    };
  i = 0;
  while (i < 5 && (strcmp(buf, opt_tab[i]) != 0))
    ++i;
  return (i);
}

int		print_rules(int	*cool)
{
  if (*cool == 0)
    {
      printf("invalid option, - -p [port] -h [ip] -x [weight]\n");
      printf("-y [height] -f [fullscreen]");
      *cool = 1;
    }
  return (0);
}

int		exec_opt(t_option *option, int ac, char **av)
{
  int           (*funct_tab[5])(t_option *option, char **av, int *i) =
    {
      &opt_p,
      &opt_y,
      &opt_x,
      &opt_f,
      &opt_h
    };
  int		i;
  int		j;
  int		cool;
  
  i = 1;
  cool = 0;
  while (i < ac)
    {
      j = find_opt(av[i]);
      if (j >= 5) 
	print_rules(&cool);
      else
	  funct_tab[j](option, av, &i);
      ++i;
    }
  return (0);
}

int		default_value(t_option *option)
{
  option->port = 4242;
  option->ip = strdup("127.0.0.1");
  option->x = 800; 
  option->y = 600;
  option->fullscreen = false;
}
