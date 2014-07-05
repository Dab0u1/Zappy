//
// serveur.h for serveur in /home/vallee_c/Zappy/Serveur
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Fri Jul  4 14:23:36 2014 david vallee
// Last update Fri Jul  4 17:22:35 2014 david vallee
//

#ifndef SERVEUR_H_
# define SERVEUR_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_CLIENT 255
#define FREE 1
#define NOFREE 0

typedef struct		s_client
{
  int			id;
  char			free;
}			t_client;

typedef struct		s_serveur
{
  struct sockaddr_in	sin;
  t_client		ctab[MAX_CLIENT]; // a changer par t_client *ctab = malloc(maxClient)
  int			idmax; // le nombre de joueur connecter
  int			maxClient;
  int			maxClientbyTeam;
  int			isRuning;
  int			fd_max;
  int			fd;  
}			t_serveur;

typedef struct		s_option
{
  int			port;
  int			worldX;
  int			worldY;
  int			team;
  int			maxClientbyTeam;
  int			t;
}			t_option;

typedef struct		s_world
{
  int			worldX;
  int			worldY;
  int			team;
  int			t;
}			t_world;

void			add_client(t_serveur *);
int			init_serveur(t_serveur *, t_option *);
int			send_msg(int, char *);
int			send_msgToAll(t_serveur *, char *);
int			send_msgToAll_exeptOne(t_serveur *, char *, int);

#endif /* !SERVEUR_H_ */
