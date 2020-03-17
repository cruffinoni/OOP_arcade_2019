##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

MAIN_FILE		=	./src/Main.cpp
NAME			=	arcade

#SRC_GAME		=	\
#					./src/game				\

#SRC_GRAPHIC		=	\
#					./src/graphic				\

SRC				=	\
					./src/DLLoader/Exceptions.cpp

NAME_TEST		=	test_arcade

SRC_TEST		=	./Tests/Combinations.cpp	\
					./Tests/Game.cpp			\

INCLUDE			=	./src/

CXXFLAGS		=	-Wall -Wextra -I $(INCLUDE) -ldl

ALL_SRC			=	$(SRC_GAME) $(SRC_GRAPHIC) $(SRC)
OBJ				=	$(ALL_SRC:.cpp=.o)
OBJ_MAIN		=	$(MAIN_FILE:.cpp=.o)

GRAPHIC_PATH	=	./src/lib/graphic/

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CXXFLAGS)

debug:
	g++ -o $(NAME) $(ALL_SRC) $(MAIN_FILE) $(CXXFLAGS)

tests_run:
	g++ $(CXXFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(ALL_SRC) -lcriterion --coverage

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C $(GRAPHIC_PATH) clean

fclean:
	rm -f $(OBJ) $(OBJ_MAIN)
	rm -f $(NAME) $(NAME_TEST)
	$(MAKE) -C $(GRAPHIC_PATH) fclean

graphicals:
	$(MAKE) -C $(GRAPHIC_PATH)

graphicals_re:
	$(MAKE) -C $(GRAPHIC_PATH) re

core: all

re:	fclean core graphicals

.PHONY:	all clean fclean re debug tests_run graphicals graphicals_re core
