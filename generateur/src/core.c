/*
** core.c for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 13:42:09 2016 Thierry LEVISSE
** Last update Fri May 27 17:39:17 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<time.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"core.h"
#include	"maze.h"
#include	"position.h"

void	help_me(char *name)
{
  fprintf(stderr, "%s x y [parfait]\n", name);
  exit(1);
}

void		core_process_perfect(t_maze *data)
{
  t_cursor	cur;

  init_cursor(&cur);
  blank_area(data);
  start_sidewinder(data);
  cur.point = data->width * 2;
  while (cur.point < data->width * data->height)
    {
      select_way(&cur, data);
      move_cursor(&cur, data);
    }
  pair_height_case(data);
  impair_width_case(data);
}

void		core_process_imperfect(t_maze *data)
{
  unsigned int	i;
  unsigned int	cur;

  core_process_perfect(data);
  i = 0;
  while (i < data->width / 2)
    {
      cur = rand() % (data->width * data->height);
      while (data->laby[cur] != 'X' && cur < data->width * data->height)
	cur++;
      data->laby[cur] = '*';
      i++;
    }
}

void	init_maze(t_maze *data, char **argv)
{
  data->width = atoi(argv[1]);
  data->height = atoi(argv[2]);
  malloc_laby(&data->laby, data->width, data->height);
}

int		main(int argc, char **argv)
{
  t_maze	data;

  srand(time(NULL) * getpid());
  if (argc == 3 || (argc == 4 && (!my_strcmp(argv[3], "parfait"))))
    {
      init_maze(&data, argv);
      if (argc == 4 &&
	  !my_strcmp(argv[3], "parfait") && data.width > 0 && data.height > 0)
	core_process_perfect(&data);
      else if (argc == 3 && data.width > 0 && data.height > 0)
	core_process_imperfect(&data);
      else
	help_me(argv[0]);
      disp_laby(&data);
    }
  else
    help_me(argv[0]);
  return (0);
}
