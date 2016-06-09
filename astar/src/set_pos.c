/*
** set_pos.c for dante in /home/thierry/Rendu/dante
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 22:47:21 2016 Thierry LEVISSE
** Last update Sun May 22 22:50:22 2016 Thierry LEVISSE
*/

#include	"position.h"
#include	"core.h"

t_position	*set_pos(unsigned int x,
			 unsigned int y)
{
  t_position	*pos;

  pos = my_xmalloc(sizeof(*pos));
  pos->x = x;
  pos->y = y;
  return (pos);
}
