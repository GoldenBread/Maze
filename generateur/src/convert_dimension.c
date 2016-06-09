/*
** convert_dimension.c for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 19 17:03:45 2016 Thierry LEVISSE
** Last update Fri May 20 18:41:22 2016 Thierry LEVISSE
*/

#include	"maze.h"

unsigned int	convert_xy(unsigned int x, unsigned int y, t_maze *data)
{
  return ((data->width * y) + x);
}

void	convert_linear(unsigned int cur,
		       unsigned int *x,
		       unsigned int *y,
		       t_maze *data)
{
  *x = cur % data->width;
  *y = cur / data->width;
}
