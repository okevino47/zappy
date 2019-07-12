##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Big makefile
##

SERVER_PATH = src/server/
GRAPHIC_PATH = src/graphics/

SERVER_NAME = zappy_server
GRAPHIC_NAME = zappy_graphic

all:	server	graphical

graphical:
	$(MAKE) -C $(GRAPHIC_PATH)
	cp $(GRAPHIC_PATH)$(GRAPHIC_NAME) ./

server:
	$(MAKE) -C $(SERVER_PATH)
	cp $(SERVER_PATH)$(SERVER_NAME) ./

#all:
#	$(MAKE) -C $(SERVER_PATH)
#	cp $(SERVER_PATH)server ./

tests_run:
	$(MAKE) -C $(SERVER_PATH) tests_run

tests_func:
	$(MAKE) -C $(SERVER_PATH) tests_func

every_tests:
	$(MAKE) -C $(SERVER_PATH) every_tests

clean:
	$(MAKE) -C $(SERVER_PATH) clean
	$(MAKE) -C $(GRAPHIC_PATH) clean

fclean:
	$(MAKE) -C $(SERVER_PATH) fclean
	$(MAKE) -C $(GRAPHIC_PATH) fclean
	rm -rf $(GRAPHIC_NAME)
	rm -rf $(SERVER_NAME)

re:	fclean all

go:	re
	$(MAKE) -C $(SERVER_PATH) clean
	$(MAKE) -C $(GRAPHIC_PATH) clean

.PHONY:		all graphical server clean fclean re go
