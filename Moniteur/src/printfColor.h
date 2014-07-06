//
// printfColor.h for printfColor in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sun Jul  6 19:01:42 2014 david vallee
// Last update Sun Jul  6 19:17:52 2014 david vallee
//

#ifndef PRINTFCOLOR_H_
# define PRINTFCOLOR_H_

#include <stdio.h>

# define BLACK "30"
# define RED "31"
# define GREEN "32"
# define YELLOW "33"
# define BLUE "34"
# define MAGENTA "35"
# define CYAN "36"
# define WHITE "37"

# define clrscr() printf("%s", "\033[H\033[2J");
# define color(v) printf("\033[%sm",v);

#endif /* !PRINTFCOLOR_H_ */
