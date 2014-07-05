//
// client.h for client in /home/vallee_c/Zappy/Client
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Fri Jul  4 16:31:36 2014 david vallee
// Last update Fri Jul  4 17:04:18 2014 david vallee
//

#ifndef CLIENT_H_
# define CLIENT_H_

#include "network/network.h"

typedef struct s_client
{
  int		fd;
  char		*nomEquipe;
}		t_client;

int		start(t_client *);
int		exec_cmd(int);

#endif /* !CLIENT_H_ */
