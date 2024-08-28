##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##

SRC =	$(wildcard ./src/operators/*.c) \
		$(wildcard ./src/builtins/*.c) \
		$(wildcard ./src/parsing/*.c) \
		$(wildcard ./src/tree/*.c) \
		$(wildcard ./src/*.c) \
		$(wildcard ./lib/*.c)

OBJ =	$(SRC:.c=.o)

NAME = amazed

CFLAGS = -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

cs:
	coding-style . . && clear && cat coding-style-reports.log
