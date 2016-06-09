/*
** calculate.c for dante in /home/thierry/Rendu/dante/astar/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 19 17:29:35 2016 Thierry LEVISSE
** Last update Sun May 22 21:50:10 2016 Thierry LEVISSE
*/

#include	<math.h>
#include	"maze.h"
#include	"astar.h"

float	distance_to_start(unsigned int x,
			  unsigned int y)
{
  return (sqrt(pow(x, 2) + pow(y, 2)));
}

float	distance_to_end(unsigned int x,
			unsigned int y,
			t_maze *data)
{
  return (sqrt(pow(data->width - x, 2) + pow(data->height - y, 2)));
}

void	f_cost(t_astar *distance)
{
  distance->f_cost = distance->g_cost + distance->h_cost;
}

void	cost(t_astar *distance,
	     unsigned int x,
	     unsigned int y,
	     t_maze *data)
{
  int	cur;

  cur = convert_xy(x, y, data);
  distance[cur].g_cost = distance_to_start(x, y);
  distance[cur].h_cost = distance_to_end(x, y, data);
  distance[cur].f_cost = distance[cur].g_cost + distance[cur].h_cost;
}
