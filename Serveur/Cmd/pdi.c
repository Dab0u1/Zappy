/*
** pdi.c for pdi in /home/vallee_c/rendu/PSU_2013_zappy/Serveur/Cmd
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Thu Jul 10 15:43:30 2014 david vallee
** Last update Thu Jul 10 15:48:57 2014 david vallee
*/

#include "../serveur.h"

int	pdi(t_serveur *s, int i)
{
  char	buff[30];

  sprintf(buff, "pdi #%d\n", i);
  send_msgToAll_Monitor(s, buff);
}
