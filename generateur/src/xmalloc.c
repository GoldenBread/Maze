/*
** xmalloc.c for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 14:24:48 2016 Thierry LEVISSE
** Last update Fri May 13 14:24:54 2016 Thierry LEVISSE
*/

#include	<stdlib.h>

void	*my_xmalloc(size_t size)
{
  void	*tmp;

  if (!(tmp = malloc(size)))
    exit(2);
  return (tmp);
}
