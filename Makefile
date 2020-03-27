##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

MAIN_FILE		=	./src/Main.cpp
NAME			=	arcade

SRC				=	./src/soLoader/Exceptions.cpp		\
					./src/core/Core.cpp					\
					./src/core/KeyEvents.cpp			\
					./src/core/Exceptions.cpp			\
					./src/core/score/Exceptions.cpp		\
					./src/core/score/File.cpp			\
					./src/core/score/Game.cpp			\
					./src/core/menu/Menu.cpp			\
					./src/core/menu/Strip.cpp			\
					./src/graphic/Drawables.cpp			\
					./src/lib/graphic/Exceptions.cpp	\

INCLUDE			=	./src/

CXXFLAGS		=	-Wall -Wextra -I $(INCLUDE) -ldl -fPIC

OBJ				=	$(SRC:.cpp=.o)
OBJ_MAIN		=	$(MAIN_FILE:.cpp=.o)

GRAPHIC_PATH	=	./src/lib/graphic
GAME_PATH		=	./src/lib/game

all: core games graphicals

core: $(OBJ) $(OBJ_MAIN)
	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)

test: core
	$(MAKE) -C $(GAME_PATH)/test

graphicals:
	$(MAKE) -C $(GRAPHIC_PATH)

games:
	$(MAKE) -C $(GAME_PATH)

debug:
	g++ -o $(NAME) $(SRC) $(MAIN_FILE) $(CXXFLAGS)
	$(MAKE) -C $(GRAPHIC_PATH) debug
	$(MAKE) -C $(GAME_PATH) debug

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C $(GRAPHIC_PATH) clean
	$(MAKE) -C $(GAME_PATH) clean

fclean:
	rm -f $(OBJ) $(OBJ_MAIN)
	rm -f $(NAME) $(NAME_TEST)
	$(MAKE) -C $(GRAPHIC_PATH) fclean
	$(MAKE) -C $(GAME_PATH) fclean
	$(MAKE) -C $(GAME_PATH)/test fclean

re:	fclean all

.PHONY:	all clean fclean re debug graphicals core games test
