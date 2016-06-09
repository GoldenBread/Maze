/*
** maze.h for dante in /home/thierry/Rendu/dante/generateur
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Mon May 16 17:01:02 2016 Thierry LEVISSE
** Last update Sun May 22 21:47:37 2016 Thierry LEVISSE
*/

#include	<stdlib.h>

#ifndef MAZE_H_
# define MAZE_H_

typedef struct	s_maze
{
  char		*laby;
  unsigned int	width;
  unsigned int	height;
  int		direction;
  char		count;
}		t_maze;

typedef struct	s_cursor
{
  unsigned int	point;
  unsigned int	size;
}		t_cursor;

void	exit_errors(int errno);
void	scan_error(char *laby);
t_maze	*get_map(char *name);
void	my_bzero(char *str, size_t size);

#endif
