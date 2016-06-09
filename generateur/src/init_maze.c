/*
** init_maze.c for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 22:08:02 2016 Thierry LEVISSE
** Last update Sun May 22 22:16:55 2016 Thierry LEVISSE
*/

#include	"maze.h"
#include	"core.h"

void	malloc_laby(char **laby, int width, int height)
{
  *laby = my_xmalloc(width * height);
}

void		blank_area(t_maze *data)
{
  unsigned int	i;

  i = 0;
  while (i < data->width * data->height)
    {
      data->laby[i] = 'X';
      i++;
    }
  data->laby[data->width * data->height - 1] = '*';
}
