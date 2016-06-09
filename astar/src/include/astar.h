/*
** astar.h for dante in /home/thierry/Rendu/dante/astar/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 19 19:26:27 2016 Thierry LEVISSE
** Last update Sun May 22 23:20:39 2016 Thierry LEVISSE
*/

#include	"core.h"

#ifndef ASTAR_H_
# define ASTAR_H_

/*
** 0 NORTH
** 1 SOUTH
** 2 EAST
** 3 WEST
*/

typedef struct	s_astar
{
  float		g_cost;
  float		h_cost;
  float		f_cost;
  int		previous;
  char		alrdy_been;
}		t_astar;

typedef struct		s_queue
{
  unsigned int		cur;
  double		f_cost;
  struct s_queue	*next;
  struct s_queue	*prev;
  struct s_queue	*head;
  struct s_queue	*tail;
}			t_queue;

float	distance_to_start(unsigned int x,
			  unsigned int y);

float	distance_to_end(unsigned int x,
			unsigned int y,
			t_maze *data);

void	f_cost(t_astar *distance);

void	cost(t_astar *distance,
	     unsigned int x,
	     unsigned int y,
	     t_maze *data);

void	init_distance(t_astar *distance, t_maze *data);

void	astar(t_maze *data, t_astar *distance);

#endif
