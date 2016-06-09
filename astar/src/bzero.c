/*
** bzero.c for dante in /home/thierry/Rendu/dante
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 21:45:53 2016 Thierry LEVISSE
** Last update Sun May 22 21:46:58 2016 Thierry LEVISSE
*/

#include	<stdlib.h>

void		my_bzero(char *str, size_t size)
{
  unsigned int	i;

  i = 0;
  while (i < size)
    {
      str[i] = '\0';
      i++;
    }
}
