/*
** errors.c for dante in /home/thierry/Rendu/dante
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun May 22 15:35:34 2016 Thierry LEVISSE
** Last update Sun May 22 15:44:09 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

void	exit_errors(int errno)
{
  char	*err[4];
  int	i;

  err[0] = strdup("Error: memory allocation failed\n");
  err[1] = strdup("Error: unable to open file\n");
  err[2] = strdup("Error: uncorrect file syntax\n");
  err[3] = strdup("Error: no valid path to target\n");
  err[4] = strdup("Error: empty file\n");
  write(2, err[errno - 1], strlen(err[errno - 1]));
  i = 0;
  while (i < 4)
    {
      free(err[i]);
      i++;
    }
  exit(errno);
}

void	scan_error(char *str)
{
  int	i;

  i = 0;
  if (!str)
    exit_errors(5);
  if (str[0] == 'X')
    exit_errors(4);
  while (str[i])
    {
      if (str[i] != '*' && str[i] != 'X')
	exit_errors(3);
      i++;
    }
}
