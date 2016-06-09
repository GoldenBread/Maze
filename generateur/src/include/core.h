/*
** core.h for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 14:00:30 2016 Thierry LEVISSE
** Last update Sun May 22 23:35:30 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	"position.h"
#include	"maze.h"

#ifndef CORE_H_
# define CORE_H_

int		my_strcmp(char *str1, char *str2);
void		*my_xmalloc(size_t size);

void		disp_laby(t_maze *data);
unsigned int	convert_xy(unsigned int x,
			   unsigned int y,
			   t_maze *data);
void	    convert_linear(unsigned int cur,
			   unsigned int *x,
			   unsigned int *y,
			   t_maze *data);

unsigned int	next_right_side(t_cursor *cur, t_maze *data);

t_position	*set_pos(unsigned int x,
			 unsigned int y);

void	init_cursor(t_cursor *cur);

void	blank_area(t_maze *data);

void	start_sidewinder(t_maze *data);

void	select_way(t_cursor *cur, t_maze *data);

void	move_cursor(t_cursor *cur, t_maze *data);

void	pair_height_case(t_maze *data);

void	impair_width_case(t_maze *data);

void	malloc_laby(char **laby, int width, int height);

unsigned int	next_right_side(t_cursor *cur, t_maze *data);


#endif
