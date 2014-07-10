/*
** send_cmd.c for Zap in /home/gonon_c/rendu/Zappy/Client
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Tue Jul  8 18:28:15 2014 gonon_c
** Last update Wed Jul  9 16:59:30 2014 gonon_c
*/

#include <string.h>
#include "client.h"
#include "network.h"

int		find_cmd(char *buf)
{
  int		i;
  char		opt_tab[10][15] =
    {
      "avance",
      "droite",
      "gauche",
      "inventaire",
      "prend objet",
      "expulse",
      "broadcast text",
      "incantation",
      "fork",
      "connect nbr",
    };
  i = 0;
  while (i < 10 && (strncmp(buf, opt_tab[i], (strlen(buf) - 1)) != 0))
    ++i;
  return (i);
}

int		print_err(int *bool)
{
  if (*bool == 0)
    {
      printf("invalid command\n");
      *bool = 1;
    }
  return (0);
}

int		exec_cmd(int fd, char *cmd)
{
  int           (*funct_tab[10])(int fd, char *cmd) =
    {
      &advance, &right,
      &left, &inventory,
      &take, &expels,
      &broadcast, &incantation,
      &furk, &connect_nbr
    };
  int		j;
  int		bool;
  
  bool = 0;
  j = find_cmd(cmd);
  if (j >= 10) 
    print_err(&bool);
  else
    funct_tab[j](fd, cmd);
  return (0);
}

int			read_cmd(int fd)
{
  char			cmd[255];
  int			r;

  if ((r = read(0, cmd, 255)) == -1)
    {
      printf("exec_cmd: read fail !\n");
      return (-1);
    }
  else if (r == 0)
    {
      printf("Close client\n");
      return (-1);
    }
  cmd[r] = '\0';
  exec_cmd(fd, cmd);
  return (0);
}
