/*
** client.h for ZAP in /home/gonon_c/rendu/Zappy/Client
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Wed Jul  9 23:42:14 2014 gonon_c
** Last update Thu Jul 10 00:05:56 2014 gonon_c
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
  int		x;
  int		y;
}		t_client;

int		start(t_client *);
int		read_cmd(int);
int		opt_p(t_option *option, char **av, int *j);
int		opt_h(t_option *option, char **av, int *j);
int		opt_n(t_option *option, char **av, int *j);
int		take(int fd, char *cmd);
int		inventory(int fd, char *cmd);
int		left(int fd, char *cmd);
int		right(int fd, char *cmd);
int		advance(int fd, char *cmd);
int		expels(int fd, char *cmd);
int		broadcast(int fd, char *cmd);
int		incantation(int fd, char *cmd);
int		furk(int fd, char *cmd);
int		connect_nbr(int fd, char *cmd);

#endif /* !CLIENT_H_ */
