/*
** dfs.h for dante in /home/thierry/Rendu/dante/profondeur/src/include
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat May 21 00:10:43 2016 Thierry LEVISSE
** Last update Sun May 22 22:46:19 2016 Thierry LEVISSE
*/

#include	"maze.h"
#include	"position.h"

#ifndef DFS_H_
# define DFS_H_

typedef struct	s_dfs
{
  unsigned int	x;
  unsigned int	y;
  char		previous;
  struct s_dfs	*next;
  struct s_dfs	*prev;
  struct s_dfs	*head;
  struct s_dfs	*tail;
}		t_dfs;

/*
** 0 NORTH
** 1 SOUTH
** 2 EAST
** 3 WEST
*/

typedef struct	s_misc_dfs
{
  char		*alrdy_been;
  char		*previous;
  unsigned int	cur;
  unsigned int	old_cur;
}		t_misc_dfs;

void	dfs(t_maze *data,
	    t_dfs *stack,
	    t_misc_dfs *misc);

void	del_top_stack(t_dfs **stack);

void	set_and_check(t_misc_dfs *misc,
		      t_position *pos,
		      t_dfs **stack,
		      t_maze *data);

#endif
