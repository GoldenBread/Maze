/*
** bfs.h for dante in /home/thierry/Rendu/dante/largeur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat May 21 22:46:56 2016 Thierry LEVISSE
** Last update Sun May 22 23:15:39 2016 Thierry LEVISSE
*/

#include	"position.h"

#ifndef BFS_H_
# define BFS_H_

typedef struct	s_bfs
{
  unsigned int	x;
  unsigned int	y;
  char		previous;
  struct s_bfs	*next;
  struct s_bfs	*prev;
  struct s_bfs	*head;
  struct s_bfs	*tail;
}		t_bfs;

/*
** 0 NORTH
** 1 SOUTH
** 2 EAST
** 3 WEST
*/

typedef struct	s_misc_bfs
{
  char		*alrdy_been;
  char		*previous;
  unsigned int	cur;
  unsigned int	old_cur;
}		t_misc_bfs;

void	check_compass(t_maze *data,
		      t_position *pos,
		      t_bfs **stack,
		      t_misc_bfs *misc);

void	bfs(t_maze *data,
	    t_bfs *stack,
	    t_misc_bfs *misc);

void	del_bot_stack(t_bfs **stack);

void	add_top_stack(unsigned int x,
		      unsigned int y,
		      t_bfs **stack);

#endif
