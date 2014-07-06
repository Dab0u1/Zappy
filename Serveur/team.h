//
// team.h for team in /home/vallee_c/rendu/PSU_2013_zappy
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sun Jul  6 15:38:42 2014 david vallee
// Last update Sun Jul  6 15:38:49 2014 david vallee
//

#ifndef TEAM_H_
# define TEAM_H_

typedef struct          s_team
{
  char                  *data;
  struct s_team         *next;
}                       t_team;

#endif /* !TEAM_H_ */
