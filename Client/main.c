/*
** main.c for main in /home/vallee_c/Zappy/Client
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:18:20 2014 david vallee
** Last update Fri Jul  4 17:03:36 2014 david vallee
*/

#include "client.h"

int	get_option(t_client *client, int ac, char **av)
{
  int	port;
  char *ip;

  port = 4242;
  ip = strdup("127.0.0.1");
  client->nomEquipe = strdup("test");
  if ((client->fd = connect_to_server(ip, port)) == -1) 
    return (-1);
  free(ip);

  // Ici recuperer argument
  return (0);
}

int	main(int ac, char **av)
{
  t_client	client;
 
  get_option(&client, ac, av);
  start(&client);
  return (0);
}
