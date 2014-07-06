//
// network.h for network in /home/vallee_c/TECH2/SystemeUnix/my_irc/irc0.1/Client
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 17:05:02 2014 david vallee
// Last update Fri Jul  4 16:58:55 2014 david vallee
//

#ifndef NETWORK_H_
# define NETWORK_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int	connect_to_server(char *ip, int port);
int	close_connect(int fd);
char	*get_msg(int fd);
int	send_msg(int fd, char *msg);

#endif /* !NETWORK_H_ */
