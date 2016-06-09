/*
** sidewinder.c for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 22:06:48 2016 Thierry LEVISSE
** Last update Sun May 22 23:35:18 2016 Thierry LEVISSE
*/

#include	"maze.h"
#include	"core.h"

void		start_sidewinder(t_maze *data)
{
  unsigned int	i;

  i = 0;
  while (i < data->width)
    {
      data->laby[i] = '*';
      i++;
    }
}

void		drill_wall(t_maze *data, t_cursor *cur)
{
  unsigned int	rand_hole;

  rand_hole = rand() % cur->size;
  if (rand_hole % 2 == 1)
    rand_hole--;
  data->laby[cur->point - data->width + rand_hole] = '*';
}

void		debug_show_way(t_maze *data, t_cursor *cur)
{
  unsigned int	i;

  i = 0;
  while (i < cur->size)
    {
      data->laby[cur->point + i] = '*';
      i++;
    }
}

void		select_way(t_cursor *cur, t_maze *data)
{
  if (data->width - 1 - (cur->point % data->width) == 0)
    cur->size = 1;
  else if (cur->point + 8 < next_right_side(cur, data))
    {
      cur->size = 1 + (rand() % (data->width / 50 + 3)) * 2;
      if (cur->point % data->width % 2 == 1 && cur->size != 1)
	cur->size -= 1;
    }
  else
    {
      cur->size = 1 + (rand() %
		       ((data->width - (cur->point % data->width)) - 1));
      if (cur->size % 2 == 0 && cur->size != 1)
	cur->size -= 1;
    }
  debug_show_way(data, cur);
  drill_wall(data, cur);
}
