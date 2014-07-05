/*
** send_msg.c for send_msg in /home/vallee_c/Zappy/Client/network
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Fri Jul  4 16:33:21 2014 david vallee
** Last update Fri Jul  4 16:34:30 2014 david vallee
*/

int	send_msg(int fd, char *msg)
{
  if (write(fd, msg, strlen(msg)) == -1)
    return (-1);
  return (0);
}
