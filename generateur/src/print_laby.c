/*
** printf_laby.c for dante in /home/thierry/Rendu/dante
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 19 16:34:55 2016 Thierry LEVISSE
** Last update Fri May 27 17:46:28 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	"maze.h"

void		disp_between(char *str, unsigned int cur, unsigned int size)
{
  unsigned int	i;
  char		tmp[size + 1];

  i = 0;
  while (i < size)
    {
      tmp[i] = str[cur];
      cur++;
      i++;
    }
  tmp[i] = '\0';
  printf("%s\n", tmp);
}

void		disp_between_w_backn(char *str,
				     unsigned int cur,
				     unsigned int size)
{
  unsigned int	i;
  char		tmp[size + 1];

  i = 0;
  while (i < size)
    {
      tmp[i] = str[cur];
      cur++;
      i++;
    }
  tmp[i] = '\0';
  printf("%s", tmp);
  fflush(stdout);
}

void		disp_laby(t_maze *data)
{
  unsigned int	cur;

  cur = 0;
  while (cur < data->width * data->height)
    {
      if (cur + data->width < data->width * data->height)
	disp_between(data->laby, cur, data->width);
      else
	disp_between_w_backn(data->laby, cur, data->width);
      cur += data->width;
    }
}
