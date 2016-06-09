/*
** main.c for dante in /home/thierry/Rendu/dante/profondeur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 20 23:40:29 2016 Thierry LEVISSE
** Last update Sun May 22 22:49:43 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<math.h>
#include	<fcntl.h>
#include	"maze.h"
#include	"core.h"
#include	"dfs.h"
#include	"position.h"

void	help_me(char *name)
{
  fprintf(stderr, "Usage: %s maze1.txt\n", name);
}

void	set_alrdybeen(t_maze *data, t_misc_dfs *misc)
{
  misc->alrdy_been = my_xmalloc(data->width * data->height);
  my_bzero(misc->alrdy_been, data->width * data->height);
  misc->previous = my_xmalloc(data->width * data->height);
}

void	next_pos(t_position *pos, t_misc_dfs *misc, t_maze *data)
{
  int	cur;

  cur = convert_xy(pos->x, pos->y, data);
  if (misc->previous[cur] == 0)
    pos->y -= 1;
  else if (misc->previous[cur] == 1)
    pos->y += 1;
  else if (misc->previous[cur] == 3)
    pos->x -= 1;
  else if (misc->previous[cur] == 2)
    pos->x += 1;
}

void		gimme_path(t_misc_dfs *misc, t_maze *data)
{
  t_position	pos;

  pos.x = data->width - 1;
  pos.y = data->height - 1;
  while (pos.x > 0 || pos.y > 0)
    {
      data->laby[convert_xy(pos.x, pos.y, data)] = 'o';
      next_pos(&pos, misc, data);
    }
  data->laby[convert_xy(pos.x, pos.y, data)] = 'o';
}

int		main(int argc, char **argv)
{
  t_maze	*data;
  t_dfs		stack;
  t_misc_dfs	misc;

  if (argc == 2)
    {
      data = get_map(argv[1]);
      scan_error(data->laby);
      set_alrdybeen(data, &misc);
      dfs(data, &stack, &misc);
      gimme_path(&misc, data);
      disp_laby(data);
      free(data->laby);
      free(data);
    }
  else
    help_me(argv[0]);
  return (0);
}
