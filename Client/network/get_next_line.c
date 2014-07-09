/*
** get_next_line.c for get_nextline.c in /home/vallee_c//Modules/ProgElem/get_next_line/test2
** 
** Made by david1 vallee
** Login   <vallee_c@epitech.net>
** 
** Started on  Tue Apr 30 11:09:27 2013 david1 vallee
** Last update Tue Jul  8 20:06:58 2014 david vallee
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
  static char	buff[BUFF_SIZE];
  static int	r;
  static int	cursor_b;
  int		cursor_s;
  char		*line;

  line = 0;
  cursor_s = 0;
  while (1)
    {
      if (cursor_b >= r)
        {
          cursor_b = 0;
          cursor_s = 0;
          if ((r = read(fd, buff, BUFF_SIZE)) == -1)
            return (NULL);
          else if (r == 0)
            return (line);
        }
      if (buff[cursor_s + cursor_b] == '\n')
	return (buff_cat(line, buff, cursor_s, &cursor_b));
      if ((cursor_s + cursor_b) == r - 1)
        line = buff_cat(line, buff, cursor_s + 1, &cursor_b);
      cursor_s++;
    }
}

char	*buff_cat(char *line, char *buff, int cursor_s, int *cursor_b)
{
  char		*new_line;
  int		last_size;

  last_size = 0;
  if (line != NULL)
    last_size = strlen(line);
  if ((new_line = 
       malloc(sizeof(*new_line) * (cursor_s + 1 + last_size))) == NULL)
    return (NULL);
  if (line == NULL)
    strncpy(new_line, "", last_size);
  else
    strncpy(new_line, line, last_size);
  strncpy((new_line + last_size), (buff + *cursor_b), cursor_s);
  new_line[cursor_s + last_size] = '\0';
  *cursor_b = *cursor_b + cursor_s + 1;
  if (line != NULL)
    free(line);
  return (new_line);
}
