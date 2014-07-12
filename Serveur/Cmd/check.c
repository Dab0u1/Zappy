#include "../serveur.h"

int		check_res_cell(t_cell *cell, int type, int fd)
{
  t_cell	*check;

  while (cell)
    {
      if (cell->type == type)
	return (0);
      cell = cell->next;
    }
  send_msg(fd, "ko\n");
  return (-1);
}

int		check_res_player(int *inv, int type, int fd)
{
  if (inv[type] != 0)
    return (0);
  send_msg(fd, "ko\n");
  return (-1);
}
