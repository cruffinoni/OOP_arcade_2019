##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

NAME			=	lib_arcade_sdl2.so

INCLUDE			=	../../..

SRC				=	./SDL2.cpp

BIN_DIRECTORY	=	../../../../lib/

CXXFLAGS		=	-Wall -Wextra -I $(INCLUDE) -fPIC -shared -lSDL2 -lSDL2_ttf

OBJ				=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)
	cp $(NAME) $(BIN_DIRECTORY)

debug:
	g++ -o $(NAME) $(SRC) $(MAIN_FILE) $(CXXFLAGS) -g
	cp $(NAME) $(BIN_DIRECTORY)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f $(BIN_DIRECTORY)$(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
