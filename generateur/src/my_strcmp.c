/*
** my_strcmp.c for dante in /home/thierry/Rendu/dante/generateur/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 13:57:29 2016 Thierry LEVISSE
** Last update Fri May 13 13:57:29 2016 Thierry LEVISSE
*/

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' || str2[i] != '\0')
    {
      if (str1[i] < str2[i])
	return (-1);
      else if (str1[i] > str2[i])
	return (1);
      i++;
    }
  return (0);
}
