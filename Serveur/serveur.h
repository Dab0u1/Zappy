/*
** serveur.h for Zap in /home/gonon_c/Desktop/PSU_2013_zappy/Serveur
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 13:47:07 2014 gonon_c
// Last update Wed Jul  9 21:25:11 2014 david vallee
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Map/map.h"

// Client type

# define FREE 0
# define NOINIT 1
# define CLIENT 2
# define MONITEUR 3

# define MAXMONITOR 10

# define FOOD 0
# define LINEMATE 1
# define DERAUMERE 2
# define SIBUR 3
# define MENDIANE 4
# define PHIRAS 5
# define THYSTAME 6
# define PLAYER 7
# define EGGS 8

typedef struct		s_obj
{
  int			type;
  struct s_obj		*next;
}			t_obj;

typedef struct		s_monitor
{
  int			fd;
  struct s_monitor	*next;
}			t_monitor;

typedef struct		s_team
{
  char			*data;
  struct s_team		*next;
}			t_team;

typedef struct		s_client
{
  int			id;
  char			type;
  int			x;
  int			y;
  int			o;
  int			lvl;
  int			team;
  t_obj			*inventaire;
}			t_client;

typedef struct		s_serveur
{
  t_client		*ctab;
  t_map			*map;
  t_monitor		*fdMonitor;
  t_team		*team;
  int			t;
  int			maxClient;
  int			maxClientbyTeam;
  int			isRuning;
  int			fd_max; //le fdMax pour le select du serveur
  int			idmax; // id max des clients
  int			fd; // fd du serveur

}			t_serveur;

typedef struct		s_option
{
  int			port;
  int			worldX;
  int			worldY;
  t_team		*team;
  int			maxClientbyTeam;
  int			t;
}			t_option;

void			add_client(t_serveur *);
int			init_serveur(t_serveur *, t_option *);
int			initGraphMonitor(t_serveur *, int);
int			initClient(t_serveur *s, int fd, char *team);
int			send_msg(int, char *);
int			send_msgToAll(t_serveur *, char *);
int			send_msgToAll_exeptOne(t_serveur *, char *, int);
int			send_msgToAll_Monitor(t_serveur *s, char *msg);
int			opt_p(t_option *option, char **av, int *i);
int			opt_x(t_option *option, char **av, int *i);
int			opt_y(t_option *option, char **av, int *i);
int			opt_c(t_option *option, char **av, int *i);
int			opt_t(t_option *option, char **av, int *i);
int			opt_n(t_option *option, char **av, int *i);
int			bct_all_map(int fd, t_map *map);
int			bct(int fd, t_map *map, int x, int y);
void			msz(int fd, int x, int y);
int			new_monitor(t_monitor **list, int fd);
int			del_monitor(t_monitor **list, int fd);
void			show_Monitor(t_monitor *tmp);

#endif /* !SERVEUR_H_ */
