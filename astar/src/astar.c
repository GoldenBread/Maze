/*
** astar.c for dante in /home/thierry/Rendu/dante/astar/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 23:18:08 2016 Thierry LEVISSE
** Last update Sun May 22 23:21:02 2016 Thierry LEVISSE
*/

#include	<limits.h>
#include	"maze.h"
#include	"astar.h"

void	set_and_check(t_astar *distance,
		      unsigned int x,
		      unsigned int y,
		      t_maze *data)
{
  if (distance[convert_xy(x, y, data)].g_cost >
      distance_to_start(x, y) ||
      distance[convert_xy(x, y, data)].g_cost == -1)
    {
      cost(distance, x, y, data);
      distance[convert_xy(x, y, data)].previous = data->direction;
    }
}

void	check_compass(t_astar *distance,
		      t_position *pos,
		      t_maze *data)
{
  distance[convert_xy(pos->x, pos->y, data)].alrdy_been = 1;
  data->direction = 1;
  if (pos->y > 0 && data->laby[convert_xy(pos->x, pos->y - 1, data)] != 'X' &&
      distance[convert_xy(pos->x, pos->y - 1, data)].alrdy_been != 1)
    set_and_check(distance, pos->x, pos->y - 1, data);
  data->direction = 0;
  if (pos->y < data->height &&
      data->laby[convert_xy(pos->x, pos->y + 1, data)] != 'X' &&
      distance[convert_xy(pos->x, pos->y + 1, data)].alrdy_been != 1)
    set_and_check(distance, pos->x, pos->y + 1, data);
  data->direction = 2;
  if (pos->x > 0 && data->laby[convert_xy(pos->x - 1, pos->y, data)] != 'X' &&
      distance[convert_xy(pos->x - 1, pos->y, data)].alrdy_been != 1)
    set_and_check(distance, pos->x - 1, pos->y, data);
  data->direction = 3;
  if (pos->x < data->width &&
      data->laby[convert_xy(pos->x + 1, pos->y, data)] != 'X' &&
      distance[convert_xy(pos->x + 1, pos->y, data)].alrdy_been != 1)
    set_and_check(distance, pos->x + 1, pos->y, data);
}

int		get_lowest(t_maze *data, t_astar *distance)
{
  int		lowest_fcost;
  int		lowest_cur;
  unsigned int	cur;

  lowest_fcost = INT_MAX;
  lowest_cur = INT_MAX;
  cur = 0;
  while (cur < (data->width * data->height))
    {
      if (distance[cur].f_cost < lowest_fcost &&
	  distance[cur].f_cost != -1 &&
	  distance[cur].alrdy_been != 1)
	{
	  lowest_fcost = distance[cur].f_cost;
	  lowest_cur = cur;
	}
      cur++;
    }
  return (lowest_cur);
}

unsigned int	astar_loop(t_maze *data, t_astar *distance)
{
  unsigned int	cur;
  t_position	pos;

  cur = get_lowest(data, distance);
  if (cur == INT_MAX)
    exit_errors(4);
  distance[cur].alrdy_been = 1;
  convert_linear(cur, &pos.x, &pos.y, data);
  check_compass(distance, &pos, data);
  return (cur);
}

void		astar(t_maze *data, t_astar *distance)
{
  while (astar_loop(data, distance) != (data->width * data->height) - 1);
}
