##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

NAME			=	lib_arcade_gametest.so

INCLUDE			=	../../..

SRC				=	./TestGame.cpp

GAMES_DIRECTORY	=	../../../../games/

CXXFLAGS		=	-Wall -Wextra -I $(INCLUDE) -fPIC -shared

OBJ				=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)
	cp $(NAME) $(GAMES_DIRECTORY)

debug:
	g++ -o $(NAME) $(SRC) $(MAIN_FILE) $(CXXFLAGS)
	cp $(NAME) $(GAMES_DIRECTORY)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f $(GAMES_DIRECTORY)$(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
