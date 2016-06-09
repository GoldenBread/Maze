/*
** stack.c for dante in /home/thierry/Rendu/dante
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 22:51:29 2016 Thierry LEVISSE
** Last update Sun May 22 22:52:30 2016 Thierry LEVISSE
*/

#include	"core.h"
#include	"dfs.h"

void	add_top_stack(unsigned int x,
		      unsigned int y,
		      t_dfs **stack)
{
  t_dfs	*tmp;

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

void	del_top_stack(t_dfs **stack)
{
  t_dfs	*tmp;

  if (*stack && (*stack)->head->tail)
    {
      tmp = (*stack)->head->tail;
      if (tmp->prev != NULL)
	{
	  *stack = tmp->prev;
	  if (*stack)
	    {
	      (*stack)->head->tail = *stack;
	      (*stack)->next = NULL;
	    }
	}
      else
	*stack = NULL;
      if (tmp)
	free(tmp);
    }
}

void	set_and_check(t_misc_dfs *misc,
		      t_position *pos,
		      t_dfs **stack,
		      t_maze *data)
{
  if (data->count == 0)
    {
      misc->previous[convert_xy(pos->x, pos->y, data)] = data->direction;
      misc->cur = convert_xy(pos->x, pos->y, data);
    }
  else
    {
      add_top_stack(pos->x, pos->y, stack);
      (*stack)->previous = data->direction;
    }
  free(pos);
  data->count++;
}
