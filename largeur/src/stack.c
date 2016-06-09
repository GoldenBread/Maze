/*
** stack.c for dante in /home/thierry/Rendu/dante/largeur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 23:10:59 2016 Thierry LEVISSE
** Last update Sun May 22 23:12:00 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	"maze.h"
#include	"bfs.h"
#include	"core.h"
#include	"position.h"

void	add_top_stack(unsigned int x,
		      unsigned int y,
		      t_bfs **stack)
{
  t_bfs	*tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->x = x;
  tmp->y = y;
  tmp->next = NULL;
  tmp->prev = *stack;
  if (*stack != NULL)
    {
      (*stack)->next = tmp;
      tmp->head = (*stack)->head;
      (*stack)->head->tail = tmp;
    }
  else
    {
      tmp->head = tmp;
      tmp->tail = tmp;
    }
  *stack = tmp;
}

void	del_bot_stack(t_bfs **stack)
{
  t_bfs	*tmp;

  if (*stack)
    {
      tmp = (*stack)->head;
      (*stack)->head = (*stack)->head->next;
      if (tmp->next != NULL)
	{
	  tmp->next->prev = NULL;
	  tmp->next->tail = *stack;
	}
      else
	*stack = NULL;
      if (tmp)
	free(tmp);
    }
}

void	set_and_check(t_misc_bfs *misc,
		      t_position *pos,
		      t_bfs **stack,
		      t_maze *data)
{
  misc->previous[convert_xy(pos->x, pos->y, data)] = data->direction;
  misc->cur = convert_xy(pos->x, pos->y, data);
  add_top_stack(pos->x, pos->y, stack);
  (*stack)->previous = data->direction;
  free(pos);
}

void	check_compass(t_maze *data,
		      t_position *pos,
		      t_bfs **stack,
		      t_misc_bfs *misc)
{
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

