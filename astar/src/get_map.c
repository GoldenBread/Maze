/*
** get_map.c for dante in /home/thierry/Rendu/dante
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 21:36:38 2016 Thierry LEVISSE
** Last update Sun May 22 23:17:34 2016 Thierry LEVISSE
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<string.h>
#include	<stdlib.h>
#include	"maze.h"
#include	"get_next_line.h"

t_maze		*get_map(char *name)
{
  t_maze	*tmp;
  int		fd;
  char		*str;

  tmp = my_xmalloc(sizeof(*tmp));
  if ((fd = open(name, O_RDONLY)) == -1)
    exit_errors(2);
  str = get_next_line(fd);
  tmp->height = 1;
  if (str != NULL)
    {
      tmp->width = strlen(str);
      tmp->laby = my_xmalloc(tmp->width + 1);
      my_bzero(tmp->laby, tmp->width + 1);
      strcat(tmp->laby, str);
      free(str);
    }
  while ((str = get_next_line(fd)))
    {
      tmp->laby = realloc(tmp->laby, tmp->width * (tmp->height + 2));
      strcat(tmp->laby, str);
      free(str);
      tmp->height++;
    }
  return (tmp);
}
