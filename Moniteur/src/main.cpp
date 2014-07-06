//
// main.cpp for main in /home/vallee_c/Zappy/GraphEngine
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:46:58 2014 david vallee
// Last update Sun Jul  6 05:32:04 2014 david vallee
//

#include "../graphEngine/GraphEngine.hpp"
#include "World.hpp"
#include "../network/network.h"

void	intro()
{
  printf("\n\n --------------- Welcome to Trantor ! ------------\n\n");
  printf("-> Rotate the camera with z,s,q,d \n-> Move with i,j,k,l\n");
  printf("-> Move Pikachu with Up arrow and rotate it with Right and Left arrow\n\n\n");
  printf("-----------------------------------------------------------\n\n\n");
}

int	main(int ac, char ** av)
{
  World		world;
  int		loading;
  int		fd;

  if (ac != 3)
    {
      printf("Usage : ./moniteur <ip> <port>");
      return (0);
    }
  fd = connect_to_server(av[1], atoi(av[2]));
  if (fd == -1)
    {
      printf("Fail to connect to server\n");
      return (0);
    }
  world.setFdServer(fd);
  printf("  Connect to server %s with port : %s\n\n", av[1], av[2]);
  load(world);

  graphEngine	window(world);
  window.init();
  while (window.getKey())
    window.draw();
  return (0);
}
