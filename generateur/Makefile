##
## Makefile for dante in /home/thierry/Rendu/dante
## 
## Made by Thierry LEVISSE
## Login   <thierry@epitech.net>
## 
## Started on Fri May 13 13:37:04 2016 Thierry LEVISSE
## Last update Sun May 22 22:10:35 2016 Thierry LEVISSE
##

NAME1	=	generateur

SRC1	=	src/core.c \
		src/sidewinder.c \
		src/case_cur.c \
		src/init_maze.c \
		src/my_strcmp.c \
		src/print_laby.c \
		src/convert_dimension.c \
		src/xmalloc.c

OBJ1	=	$(SRC1:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wextra -Wall -I./src/include/

DEBUG	=	-g -ggdb3

all: $(NAME1)

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

clean:
	$(RM) $(OBJ1)

fclean: clean
	$(RM) $(NAME1)

debug: fclean $(OBJ1)
	$(CC) $(DEBUG) $(OBJ1) -o $(NAME1)

re: fclean all
