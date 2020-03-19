##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

all:
	$(MAKE) -C ./sfml/
	$(MAKE) -C ./sdl2/

debug:
	$(MAKE) -C ./sfml/ debug
	$(MAKE) -C ./sdl2/ debug

clean:
	$(MAKE) -C ./sfml/ clean
	$(MAKE) -C ./sdl2/ clean

fclean:
	$(MAKE) -C ./sfml/ fclean
	$(MAKE) -C ./sdl2/ fclean

re:	fclean all

.PHONY:	all clean fclean re debug
