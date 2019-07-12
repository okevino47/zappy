##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME    =       zappy_graphic

CC      =       g++

RM      =       rm -f

SRC     =       main.cpp	\
		Monitor.cpp	\
		Map.cpp		\
		Gem.cpp		\
		Food.cpp	\
		Egg.cpp		\
		Player.cpp	\
		Network.cpp	\
		Parser.cpp	\
		Audio.cpp

OBJ     =       $(addprefix src/, $(SRC:.cpp=.o))

CPPFLAGS  =     -W -Wall -Wextra -Werror -Iinclude -lsfml-system \
		-lsfml-graphics -lsfml-window -lsfml-audio -g3

all:    $(NAME)

$(NAME):        $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

go:	re
	$(RM) $(OBJ)

.PHONY: all clean fclean re go
