/*
** client.h for ZAP in /home/gonon_c/rendu/Zappy/Client
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 17:16:15 2014 gonon_c
** Last update Sun Jul  6 18:22:53 2014 gonon_c
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include "network/network.h"

typedef struct	s_option
{
  char		*ip;
  int		port;
  char		*nomEquipe;
}		t_option;

typedef struct	s_client
{
  int		fd;
  char		*nomEquipe;
}		t_client;

int		start(t_client *);
int		exec_cmd(int);
int		opt_p(t_option *option, char **av, int *j);
int		opt_h(t_option *option, char **av, int *j);
int		opt_n(t_option *option, char **av, int *j);

#endif /* !CLIENT_H_ */
