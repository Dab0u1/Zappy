//
// get_msg.cpp for get_msg.cpp in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src/network
// 
// Made by david vallee
// Login   <vallee_c@epitech.net>
// 
// Started on  Tue Jul  8 19:46:08 2014 david vallee
// Last update Thu Jul 10 17:28:14 2014 david vallee
//

#include <cstring>
#include <fstream>
#include "network.h"

int	cmd_len(int i, char *str)
{
  while (str[i] && str[i] != '\n')
    ++i;
  return (i);
}

char	*get_next_cmd(char *cmd, int *pos)
{
  char	*str;
  int	len;
  int	i;

  len = cmd_len(*pos, cmd);
  str = new char[len + 2];
  i = 0;
  while (cmd[*pos] && cmd[*pos] != '\n')
    {
      str[i] = cmd[*pos];
      *pos = *pos + 1;
      ++i;
    }
  str[i] = '\n';
  str[i + 1] = '\0';
  return (str);
}

int		get_msg(int fd, std::string &msg)
{
  static char	buff[8096];
  static int	pos = 0;
  static int	r = 1;
  static int	len = 0;
  char		*line;
  int		i;

  if (pos == r)
    {
      pos = 0;
      if ((r = read(fd, buff + len, 8096 - len)) == -1)
	{
	  r = 0;
	  return (-1);
	}
      else if (r == 0)
	{
	  printf("%s\n", "Serveur shutdown");
	  return (-2);
	}
      buff[r] = '\0';
    }
  if ((line = get_next_cmd(buff, &pos)) == NULL)
    return (-1);
  if (buff[pos] == '\n')
    {
      len = 0;
      pos++;
      msg = std::string(line);
      return (1);
    }
  memset(buff, 0, 4096);
  len = strlen(line);
  i = 0;
  while (line[i])
    {
      buff[i] = line[i];
      ++i;
    }
  return (0);
}
