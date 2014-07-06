/*
** main.c for main in /home/vallee_c/Zappy/Client
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:18:20 2014 david vallee
** Last update Sun Jul  6 19:47:00 2014 david vallee
*/

#include "client.h"

int		find_opt(char *buf)
{
  int		i;
  char		opt_tab[3][4] =
    {
      "-p",
      "-n",
      "-h",
    };
  i = 0;
  while (i < 3 && (strcmp(buf, opt_tab[i]) != 0))
    ++i;
  return (i);
}

int		print_rules(int	*bool)
{
  if (*bool == 0)
    {
      printf("invalid option, -n [team name] -p [port] -h [machine name]\n");
      *bool = 1;
    }
  return (0);
}

int		exec_opt(t_option *option, int ac, char **av)
{
  int           (*funct_tab[3])(t_option *option, char **av, int *i) =
    {
      &opt_p,
      &opt_n,
      &opt_h
    };
  int		i;
  int		j;
  int		bool;
  
  i = 1;
  bool = 0;
  while (i < ac)
    {
      j = find_opt(av[i]);
      if (j >= 3) 
	print_rules(&bool);
      else
	  funct_tab[j](option, av, &i);
      ++i;
    }
  return (0);
}

int	get_option(t_client *client, int ac, char **av)
{
  t_option	option;

  option.port = 4242;
  option.ip = strdup("127.0.0.1");
  option.nomEquipe = strdup("default");
  exec_opt(&option, ac, av);
  client->nomEquipe = option.nomEquipe;
  if ((client->fd = connect_to_server(option.ip, option.port)) == -1) 
    {
      printf("Fail to connect to server !\n");
      return (-1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_client	client;
 
  if (get_option(&client, ac, av) == -1)
    return (0);
  start(&client);
  return (0);
}
