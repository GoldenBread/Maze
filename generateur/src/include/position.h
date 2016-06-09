/*
** position.h for dante in /home/thierry/Rendu/dante/generateur
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 14:54:26 2016 Thierry LEVISSE
** Last update Fri May 20 13:45:02 2016 Thierry LEVISSE
*/

#ifndef POSITION_H_
# define POSITION_H_

typedef struct	s_position
{
  unsigned int	x;
  unsigned int	y;
}		t_position;

typedef	struct	s_compass
{
  char		n;
  char		s;
  char		e;
  char		w;
}		t_compass;

#endif
