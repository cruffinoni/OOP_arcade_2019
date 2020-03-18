##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

MAIN_FILE		=	./src/Main.cpp
NAME			=	arcade

SRC				=	./src/SoLoader/Exceptions.cpp		\
					./src/game/Core.cpp					\

INCLUDE			=	./src/

CXXFLAGS		=	-Wall -Wextra -I $(INCLUDE) -ldl

OBJ				=	$(SRC:.cpp=.o)
OBJ_MAIN		=	$(MAIN_FILE:.cpp=.o)

GRAPHIC_PATH	=	./src/lib/graphic/

all: core graphicals

core: $(NAME)

graphicals:
	$(MAKE) -C $(GRAPHIC_PATH)

graphicals_re:
	$(MAKE) -C $(GRAPHIC_PATH) re

$(NAME): $(OBJ) $(OBJ_MAIN)
	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)

debug:
	g++ -o $(NAME) $(ALL_SRC) $(MAIN_FILE) $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C $(GRAPHIC_PATH) clean

fclean:
	rm -f $(OBJ) $(OBJ_MAIN)
	rm -f $(NAME) $(NAME_TEST)
	$(MAKE) -C $(GRAPHIC_PATH) fclean

re:	fclean core graphicals

.PHONY:	all clean fclean re debug tests_run graphicals graphicals_re core
