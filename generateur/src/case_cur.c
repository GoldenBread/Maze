/*
** case_cur.c for dante in /home/thierry/Rendu/dante/generateur
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 22:04:02 2016 Thierry LEVISSE
** Last update Fri May 27 17:49:33 2016 Thierry LEVISSE
*/

#include	"maze.h"
#include	"core.h"

void	init_cursor(t_cursor *cur)
{
  cur->point = 0;
  cur->size = 0;
}

unsigned int	next_right_side(t_cursor *cur, t_maze *data)
{
  unsigned int	i;

  i = 0;
  while ((cur->point + i) % data->width != data->width - 1)
    i++;
  return (cur->point + i);
}

void	move_cursor(t_cursor *cur, t_maze *data)
{
  if (cur->point + cur->size >= next_right_side(cur, data))
    cur->point = next_right_side(cur, data) + data->width + 1;
  else
    cur->point += cur->size + 1;
}

void	pair_height_case(t_maze *data)
{
  if (data->width % 2 == 0 && data->height % 2 == 0)
    data->laby[data->width * data->height - 2] = '*';
}

void	impair_width_case(t_maze *data)
{
  int	cur;

  if (data->height != 2 && data->width % 2 == 1)
    {
      cur = convert_xy(data->width - 2,
		       data->height - (2 - data->height % 2),
		       data);
      data->laby[cur] = '*';
      cur = convert_xy(data->width - 1,
		       rand() % (data->height - (2 - data->height % 2)),
		       data);
      data->laby[cur] = 'X';
    }
}
