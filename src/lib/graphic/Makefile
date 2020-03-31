##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

all:
	$(MAKE) -C ./sfml/
	$(MAKE) -C ./sdl2/
	$(MAKE) -C ./ncurses/

debug:
	$(MAKE) -C ./sfml/ debug
	$(MAKE) -C ./sdl2/ debug
	$(MAKE) -C ./ncurses/ debug

clean:
	$(MAKE) -C ./sfml/ clean
	$(MAKE) -C ./sdl2/ clean
	$(MAKE) -C ./ncurses/ clean

fclean:
	$(MAKE) -C ./sfml/ fclean
	$(MAKE) -C ./sdl2/ fclean
	$(MAKE) -C ./ncurses/ fclean

re:	fclean all

.PHONY:	all clean fclean re debug
