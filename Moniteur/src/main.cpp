//
// main.cpp for main in /home/vallee_c/Zappy/GraphEngine
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:46:58 2014 david vallee
// Last update Sat Jul  5 11:15:00 2014 david vallee
//

#include "../graphEngine//GraphEngine.hpp"

void	intro()
{
  printf("\n\n --------------- Welcome to Trantor ! ------------\n\n");
  printf("-> Rotate the camera with z,s,q,d \n-> Move with i,j,k,l\n");
  printf("-> Move Pikachu with Up arrow and rotate it with Right and Left arrow\n\n\n");
  printf("-----------------------------------------------------------\n\n\n");
}

int	main()
{
  //  World		world;
  graphEngine	window;

  window.init();
  intro();
  while (window.getKey())
    window.draw();
  return (0);
}
