##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for the ex00
##

DIR		=	src/

DIR_BONUS       =       bonus/

SRC_BONUS       =       $(DIR_BONUS)Bonus.cpp

SRC		=	$(DIR)main.cpp		\
			$(DIR)neutrinos.cpp	\

OBJ 		= 	$(SRC:.cpp=.o)

OBJ_BONUS       =       $(SRC_BONUS:.cpp=.o)

CPPFLAGS 	=	-I./include -Wall -Wextra

CC		=	g++

RM		=	rm -f

NAME		=	206neutrinos

NAME_BONUS      =       bonus_206

NAME_TESTS	=	unit_tests

FLAGS_SFML      =       -lsfml-graphics -lsfml-window -lsfml-system

LIB_CRITERION	=	-lcriterion --coverage

%.o: %.cpp
			@$(CC) $(CPPFLAGS) -c $< -o $@
			@printf "[\033[0;32mCompiled\033[0m] % 30s\n" $< | tr ' ' '.'

all:			$(NAME)

$(NAME):		$(OBJ)
			@printf "[\033[0;33mBuild\033[0m] % 32s\n" $(NAME) | tr ' ' '.'
			@$(CC) -o $(NAME) $(OBJ)

bonus:			$(OBJ_BONUS)
			@printf "[\033[0;33mBuild\033[0m] % 32s\n" $(NAME_BONUS) | tr ' ' '.'
			@$(CC) -o $(NAME_BONUS) $(FLAGS_SFML) $(OBJ_BONUS)

tests_run:		fclean $(OBJ_TESTS)
			@$(CC) $(CPPFLAGS) -o $(NAME_TESTS) $(DIR)neutrinos.cpp tests/test.cpp $(LIB_CRITERION)
			@$(RM) $(OBJ_TESTS)
			./$(NAME_TESTS)

rm_tests:
			@$(RM) $(NAME_TESTS)
			@$(RM) *.gcda
			@$(RM) *.gcno

clean:
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME_BONUS) | tr ' ' '.'
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(OBJ_BONUS) | tr ' ' '.'
			@$(RM) $(OBJ_BONUS)
			@$(RM) $(NAME_BONUS)
			@$(RM) $(NAME)
			@$(RM) $(OBJ)

fclean:			rm_tests clean

re:			fclean all

debug:			CFLAGS	+=	-g3
debug:			re

.PHONY:			tests_run rm_tests fclean re
