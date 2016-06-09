/*
** dfs.c for dante in /home/thierry/Rendu/dante/profondeur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 22:40:51 2016 Thierry LEVISSE
** Last update Sun May 22 22:40:52 2016 Thierry LEVISSE
*/

#include	<limits.h>
#include	"dfs.h"
#include	"maze.h"
#include	"position.h"
#include	"core.h"

void	exec_dead_end(int count,
		      t_dfs **stack,
		      t_maze *data,
		      t_misc_dfs *misc)
{
  if (count > 3 && *stack)
    {
      *stack = (*stack)->head->tail;
      misc->cur = convert_xy((*stack)->x, (*stack)->y, data);
      misc->previous[misc->cur] = (*stack)->previous;
      del_top_stack(stack);
    }
}

void		check_dead_end(t_maze *data,
			       t_misc_dfs *misc,
			       t_dfs **stack,
			       unsigned int *cur)
{
  int		count;
  t_position	pos;

  convert_linear(*cur, &pos.x, &pos.y, data);
  count = 0;
  if (pos.y <= 0 || (data->laby[convert_xy(pos.x, pos.y - 1, data)] == 'X' ||
		     misc->alrdy_been[convert_xy(pos.x, pos.y - 1, data)] == 1))
    count++;
  if (pos.y >= data->height - 1 ||
      (data->laby[convert_xy(pos.x, pos.y + 1, data)] == 'X' ||
       misc->alrdy_been[convert_xy(pos.x, pos.y + 1, data)] == 1))
    count++;
  if (pos.x <= 0 || (data->laby[convert_xy(pos.x - 1, pos.y, data)] == 'X' ||
		     misc->alrdy_been[convert_xy(pos.x - 1, pos.y, data)] == 1))
    count++;
  if (pos.x >= data->width - 1 ||
      (data->laby[convert_xy(pos.x + 1, pos.y, data)] == 'X' ||
       misc->alrdy_been[convert_xy(pos.x + 1, pos.y, data)] == 1))
    count++;
  exec_dead_end(count, stack, data, misc);
}

void	check_compass(t_maze *data,
		      t_position *pos,
		      t_dfs **stack,
		      t_misc_dfs *misc)
{
  data->count = 0;
  data->direction = 1;
  if (pos->y > 0 && data->laby[convert_xy(pos->x, pos->y - 1, data)] != 'X' &&
      misc->alrdy_been[convert_xy(pos->x, pos->y - 1, data)] != 1)
    set_and_check(misc, set_pos(pos->x, pos->y - 1), stack, data);
  data->direction = 0;
  if (pos->y < data->height - 1 &&
      data->laby[convert_xy(pos->x, pos->y + 1, data)] != 'X' &&
      misc->alrdy_been[convert_xy(pos->x, pos->y + 1, data)] != 1)
    set_and_check(misc, set_pos(pos->x, pos->y + 1), stack, data);
  data->direction = 2;
  if (pos->x > 0 && data->laby[convert_xy(pos->x - 1, pos->y, data)] != 'X' &&
      misc->alrdy_been[convert_xy(pos->x - 1, pos->y, data)] != 1)
    set_and_check(misc, set_pos(pos->x - 1, pos->y), stack, data);
  data->direction = 3;
  if (pos->x < data->width - 1 &&
      data->laby[convert_xy(pos->x + 1, pos->y, data)] != 'X' &&
      misc->alrdy_been[convert_xy(pos->x + 1, pos->y, data)] != 1)
    set_and_check(misc, set_pos(pos->x + 1, pos->y), stack, data);
}

unsigned int	dfs_loop(t_maze *data,
			 t_dfs **stack,
			 t_misc_dfs *misc)
{
  t_position	pos;

  misc->alrdy_been[misc->cur] = 1;
  convert_linear(misc->cur, &pos.x, &pos.y, data);
  check_dead_end(data, misc, stack, &misc->cur);
  check_compass(data, &pos, stack, misc);
  if (misc->cur == misc->old_cur && !(*stack))
    exit_errors(4);
  misc->old_cur = misc->cur;
  return (misc->cur);
}

void		dfs(t_maze *data,
		    t_dfs *stack,
		    t_misc_dfs *misc)

{
  misc->cur = 0;
  misc->old_cur = UINT_MAX;
  stack = NULL;
  while (dfs_loop(data, &stack, misc) != (data->width * data->height) - 1);
}
