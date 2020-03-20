##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

MAIN_FILE		=	./src/Main.cpp
NAME			=	arcade

SRC				=	./src/soLoader/Exceptions.cpp		\
					./src/game/Core.cpp					\
					./src/graphic/Drawables.cpp			\

INCLUDE			=	./src/

CXXFLAGS		=	-Wall -Wextra -I $(INCLUDE) -ldl -fPIC

OBJ				=	$(SRC:.cpp=.o)
OBJ_MAIN		=	$(MAIN_FILE:.cpp=.o)

GRAPHIC_PATH	=	./src/lib/graphic/
GAME_PATH		=	./src/lib/game/

all: core graphicals games

core: $(OBJ) $(OBJ_MAIN)
	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)

graphicals:
	$(MAKE) -C $(GRAPHIC_PATH)

games:
	$(MAKE) -C $(GAME_PATH)

debug:
	g++ -o $(NAME) $(ALL_SRC) $(MAIN_FILE) $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C $(GRAPHIC_PATH) clean
	$(MAKE) -C $(GAME_PATH) clean

fclean:
	rm -f $(OBJ) $(OBJ_MAIN)
	rm -f $(NAME) $(NAME_TEST)
	$(MAKE) -C $(GRAPHIC_PATH) fclean
	$(MAKE) -C $(GAME_PATH) fclean

re:	fclean all

.PHONY:	all clean fclean re debug graphicals core
