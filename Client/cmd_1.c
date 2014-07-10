/*
** cmd_1.c for ZAP in /home/gonon_c/rendu/Zappy
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Tue Jul  8 19:25:59 2014 gonon_c
** Last update Thu Jul 10 17:00:02 2014 david vallee
*/

#include "network.h"
#include "client.h"

int           take(int fd, char *cmd)
{
  send_msg(fd, cmd);
  return (0);
}

int           inventory(int fd, char *cmd)
{
  send_msg(fd, cmd);  
  return (0);
}

int           left(int fd, char *cmd)
{
  send_msg(fd, cmd);  
  return (0);
}

int           right(int fd, char *cmd)
{
  send_msg(fd, cmd);  
  return (0);
}

int           advance(int fd, char *cmd)
{
  send_msg(fd, cmd);  
  return (0);  
}
