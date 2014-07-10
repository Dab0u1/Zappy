/*
** cmd_1.c for ZAP in /home/gonon_c/rendu/Zappy
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Tue Jul  8 19:25:59 2014 gonon_c
** Last update Wed Jul  9 22:56:39 2014 gonon_c
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
