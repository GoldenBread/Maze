/*
** main.c for dante in /home/thierry/Rendu/dante/astar/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 19 01:56:03 2016 Thierry LEVISSE
** Last update Sun May 22 23:42:29 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<math.h>
#include	<fcntl.h>
#include	"maze.h"
#include	"core.h"
#include	"astar.h"
#include	"position.h"

void	help_me(char *name)
{
  fprintf(stderr, "Usage: %s maze1.txt\n", name);
}

void	next_pos(t_position *pos, t_astar *distance, t_maze *data)
{
  int	cur;

  cur = convert_xy(pos->x, pos->y, data);
  if (distance[cur].previous == 0)
    pos->y -= 1;
  else if (distance[cur].previous == 1)
    pos->y += 1;
  else if (distance[cur].previous == 3)
    pos->x -= 1;
  else if (distance[cur].previous == 2)
    pos->x += 1;
}

void		gimme_path(t_astar *distance, t_maze *data)
{
  t_position	pos;

  pos.x = data->width - 1;
  pos.y = data->height - 1;
  while (pos.x > 0 || pos.y > 0)
    {
      data->laby[convert_xy(pos.x, pos.y, data)] = 'o';
      next_pos(&pos, distance, data);
    }
  data->laby[convert_xy(pos.x, pos.y, data)] = 'o';
}

void		init_distance(t_astar *distance, t_maze *data)
{
  unsigned int	i;

  i = 0;
  while (i < data->width * data->height)
    {
      distance[i].g_cost = -1;
      distance[i].h_cost = -1;
      distance[i].f_cost = -1;
      distance[i].previous = -1;
      distance[i].alrdy_been = 0;
      i++;
    }
  cost(distance, 0, 0, data);
}

int		main(int argc, char **argv)
{
  t_maze	*data;
  t_astar	*distance;

  if (argc == 2)
    {
      data = get_map(argv[1]);
      scan_error(data->laby);
      distance = my_xmalloc(sizeof(*distance) * (data->width * data->height));
      init_distance(distance, data);
      astar(data, distance);
      gimme_path(distance, data);
      disp_laby(data);
      free(distance);
      free(data->laby);
      free(data);
    }
  else
    help_me(argv[0]);
  return (0);
}
