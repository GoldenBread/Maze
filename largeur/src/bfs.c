/*
** bfs.c for dante in /home/thierry/Rendu/dante/largeur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 23:09:41 2016 Thierry LEVISSE
** Last update Sun May 22 23:10:10 2016 Thierry LEVISSE
*/

#include	"maze.h"
#include	"core.h"
#include	"bfs.h"

unsigned int	bfs_loop(t_maze *data,
			 t_bfs **stack,
			 t_misc_bfs *misc)
{
  t_position	pos;

  convert_linear(misc->cur, &pos.x, &pos.y, data);
  misc->alrdy_been[misc->cur] = 1;
  check_compass(data, &pos, stack, misc);
  del_bot_stack(stack);
  if (*stack == NULL)
    exit_errors(4);
  if (*stack && (*stack)->head)
    misc->cur = convert_xy((*stack)->head->x, (*stack)->head->y, data);
  return (misc->cur);
}

void		bfs(t_maze *data,
		    t_bfs *stack,
		    t_misc_bfs *misc)

{
  misc->cur = 0;
  stack = NULL;
  add_top_stack(0, 0, &stack);
  while (bfs_loop(data, &stack, misc) != (data->width * data->height) - 1);
}
