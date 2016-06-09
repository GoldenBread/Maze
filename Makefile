##
## Makefile for dante in /home/thierry/Rendu/dante
## 
## Made by Thierry LEVISSE
## Login   <thierry@epitech.net>
## 
## Started on Fri May 13 13:37:04 2016 Thierry LEVISSE
## Last update Sun May 29 11:31:38 2016 Thierry LEVISSE
##

NAME1	=	./astar/solver

NAME2	=	./profondeur/solver

NAME3	=	./largeur/solver

NAME4	=	./generateur/generateur

SRC1	=	./astar/src/main.c \
		./astar/src/astar.c \
		./astar/src/calculate.c \
		./astar/src/get_map.c \
		./astar/src/bzero.c \
		./astar/src/set_pos.c \
		./astar/src/get_next_line.c \
		./astar/src/get_next_line_tools.c \
		./generateur/src/print_laby.c \
		./generateur/src/xmalloc.c \
		./generateur/src/errors.c \
		./generateur/src/convert_dimension.c

SRC2	=	./profondeur/src/main.c \
		./profondeur/src/dfs.c \
		./profondeur/src/stack.c \
		./astar/src/calculate.c \
		./astar/src/get_map.c \
		./astar/src/set_pos.c \
		./astar/src/bzero.c \
		./astar/src/get_next_line.c \
		./astar/src/get_next_line_tools.c \
		./generateur/src/xmalloc.c \
		./generateur/src/errors.c \
		./generateur/src/print_laby.c \
		./generateur/src/convert_dimension.c

SRC3	=	./largeur/src/main.c \
		./largeur/src/bfs.c \
		./largeur/src/stack.c \
		./astar/src/calculate.c \
		./astar/src/get_map.c \
		./astar/src/set_pos.c \
		./astar/src/bzero.c \
		./astar/src/get_next_line.c \
		./astar/src/get_next_line_tools.c \
		./generateur/src/xmalloc.c \
		./generateur/src/errors.c \
		./generateur/src/print_laby.c \
		./generateur/src/convert_dimension.c

SRC4	=	./generateur/src/core.c \
		./generateur/src/sidewinder.c \
		./generateur/src/case_cur.c \
		./generateur/src/init_maze.c \
		./generateur/src/my_strcmp.c \
		./generateur/src/print_laby.c \
		./generateur/src/convert_dimension.c \
		./generateur/src/xmalloc.c

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

OBJ3	=	$(SRC3:.c=.o)

OBJ4	=	$(SRC4:.c=.o)

CC	=	gcc -lm

RM	=	rm -f

CFLAGS	=	-W -Wextra -Wall \
		-I./generateur/src/include/ \
		-I./profondeur/src/include/ \
		-I./largeur/src/include/ \
		-I./astar/src/include/


all:		$(NAME1) $(NAME2) $(NAME3) $(NAME4)

$(NAME1):	$(OBJ1)
		$(CC) $(OBJ1) -o $(NAME1)

$(NAME2):	$(OBJ2)
		$(CC) $(OBJ2) -o $(NAME2)

$(NAME3):	$(OBJ3)
		$(CC) $(OBJ3) -o $(NAME3)

$(NAME4):	$(OBJ4)
		$(CC) $(OBJ4) -o $(NAME4)

clean:
		$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

fclean:		clean
		$(RM) $(NAME1) $(NAME2) $(NAME3) $(NAME4)

debug:		fclean $(OBJ1)
		$(CC) $(DEBUG) $(OBJ1) -o $(NAME1)

re:		fclean all

debug: 		CFLAGS += -g -ggdb3
debug: 		re
