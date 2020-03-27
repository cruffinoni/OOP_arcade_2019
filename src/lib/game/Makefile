##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile for the project
##

all:
	$(MAKE) -C ./nibbler/
	$(MAKE) -C ./pacman/

debug:
	$(MAKE) -C ./nibbler/ debug
	$(MAKE) -C ./pacman/ debug

clean:
	$(MAKE) -C ./nibbler/ clean
	$(MAKE) -C ./pacman/ clean

fclean:
	$(MAKE) -C ./nibbler/ fclean
	$(MAKE) -C ./pacman/ fclean

re:	fclean all

.PHONY:	all clean fclean re debug
