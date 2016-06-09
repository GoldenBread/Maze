/*
** get_next_line.h for getnextline in /home/thierry/Rendu/CPE_2015_getnextline/include
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Mon Jan  4 10:04:41 2016 Thierry LEVISSE
** Last update Sun May  1 18:49:32 2016 Thierry LEVISSE
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (20)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);
int	my_strtool(char *str, int mode, int size);
void	my_strcat_spe(char *dest, char *src);
void	set_in_b_buf(char *buf, char *b_buf, char *get_read);
void	my_realloc_spe(char **str, size_t size);
void	*my_xmalloc(size_t size);
int	check_buf_backn(char *str);

#endif /*!GET_NEXT_LINE_H_ */
