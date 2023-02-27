##
## EPITECH PROJECT, 2022
## B-MUL-100-REN-1-1-myradar-jean-yanis.jeffroy
## File description:
## Makefile
##

SRC		=	src/main.c

SRC		+=	src/init/game.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_paint

CFLAGS	:=	-I include/ -Wall -Wextra -g

LDLIBS 	:=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)
	@echo "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f $(shell find -name '*.gc*' -type f)
	@echo "\033[1;31mClean done\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31mFclean done\033[0m"

re:	fclean all

.PHONY: all clean fclean re

%:
	@echo "\033[1;31mUnknow rule\033[0m"
