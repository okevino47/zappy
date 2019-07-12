##
## EPITECH PROJECT, 2018
## zappy
## File description:
## makefie
##

SERVER_PATH	= common_src/

TEST_PATH	= tests/

COMMANDS_PATH	= client_commands/

GRAPH_PATH	= graphical_client_commands/

SERVER_SRC_MAIN =	$(SERVER_PATH)main_server.c

SERVER_SRC_GEN 	= 	$(SERVER_PATH)init_structs.c			\
			$(SERVER_PATH)init_map.c			\
			$(SERVER_PATH)create_chained_list_teams.c	\
			$(SERVER_PATH)handle_params.c			\
			$(SERVER_PATH)socket.c				\
			$(SERVER_PATH)launch_server.c			\
			$(SERVER_PATH)create_chained_list_player.c	\
			$(SERVER_PATH)tmp_client.c			\
			$(SERVER_PATH)parse_commands.c			\
			$(SERVER_PATH)get_current_player.c		\
			$(SERVER_PATH)stock_command.c			\
			$(SERVER_PATH)str_to_word_array.c		\
			$(SERVER_PATH)commands_array.c			\
			$(SERVER_PATH)create_chained_list_actions.c	\
			$(SERVER_PATH)init_cbuff.c			\
			$(SERVER_PATH)exec_commands.c			\
			$(SERVER_PATH)ressources_generation.c		\
			$(SERVER_PATH)remove_client.c			\
			$(SERVER_PATH)create_chained_list_squares.c	\
			$(SERVER_PATH)create_chained_list_eggs.c	\
			$(SERVER_PATH)end_game.c			\
			$(SERVER_PATH)check_client.c			\
			$(SERVER_PATH)update_game.c			\
			$(COMMANDS_PATH)broadcast_command.c		\
			$(COMMANDS_PATH)connect_nbr_command.c		\
			$(COMMANDS_PATH)eject_command.c			\
			$(COMMANDS_PATH)fork_command.c			\
			$(COMMANDS_PATH)forward_command.c		\
			$(COMMANDS_PATH)take_command.c			\
			$(COMMANDS_PATH)incantation_command.c		\
			$(COMMANDS_PATH)inventory_command.c		\
			$(COMMANDS_PATH)left_command.c			\
			$(COMMANDS_PATH)look_command.c			\
			$(COMMANDS_PATH)right_command.c			\
			$(COMMANDS_PATH)set_command.c			\
			$(COMMANDS_PATH)incant_lvl_two_to_lvl_six.c	\
			$(COMMANDS_PATH)incant_lvl_seven_to_lvl_eight.c	\
			$(COMMANDS_PATH)look_additional_func.c		\
			$(COMMANDS_PATH)broadcast_calc_sound.c		\
			$(COMMANDS_PATH)convert_broad_nb.c		\
			$(COMMANDS_PATH)incant_propagation.c		\
			$(GRAPH_PATH)graphical_init.c			\
			$(GRAPH_PATH)parse_graph_command.c		\
			$(GRAPH_PATH)fp_array_graph.c			\
			$(GRAPH_PATH)pnw.c				\
			$(GRAPH_PATH)pbc.c				\
			$(GRAPH_PATH)pex.c				\
			$(GRAPH_PATH)pic.c				\
			$(GRAPH_PATH)pie.c				\
			$(GRAPH_PATH)pfk.c				\
			$(GRAPH_PATH)pdr.c				\
			$(GRAPH_PATH)pgt.c				\
			$(GRAPH_PATH)pdi.c				\
			$(GRAPH_PATH)enw.c				\
			$(GRAPH_PATH)eht.c				\
			$(GRAPH_PATH)ebo.c				\
			$(GRAPH_PATH)edi.c				\
			$(GRAPH_PATH)seg.c				\
			$(GRAPH_PATH)smg.c				\
			$(GRAPH_PATH)suc.c				\
			$(GRAPH_PATH)sbp.c				\
			$(GRAPH_PATH)msz.c				\
			$(GRAPH_PATH)bct.c				\
			$(GRAPH_PATH)mct.c				\
			$(GRAPH_PATH)tna.c				\
			$(GRAPH_PATH)ppo.c				\
			$(GRAPH_PATH)plv.c				\
			$(GRAPH_PATH)pin.c				\
			$(GRAPH_PATH)quit.c


TEST_SRC_GEN	= $(TEST_PATH)primary.c

SERVER_OBJ_MAIN	= $(SERVER_SRC_MAIN:.c=.o)

SVERVER_OBJ	= $(SERVER_SRC_GEN:.c=.o)

TEST_OBJ	= $(TEST_SRC_GEN:.c=.o)

SERVER_NAME	= zappy_server

TEST_NAME	= tests_run

CFLAGS		= -I../../include -W -Wall -Wextra -Werror --coverage -lm

LDFLAGS		+= -lcriterion -lgcov

TEST_GARB	= $(TEST_PATH)*.gcda $(TEST_PATH)*.gcno

SERVER_GARB	= $(SERVER_PATH)*.gcda $(SERVER_PATH)*.gcno

COMMANDS_GARB	= $(COMMANDS_PATH)*.gcda $(COMMANDS_PATH)*.gcno

GRAPH_GARB	= $(GRAPH_PATH)*.gcda $(GRAPH_PATH)*.gcno

TEST_FILES	= $(TEST_GARB) $(SERVER_GARB) $(COMMANDS_GARB) $(GRAPH_GARB)

SRC_GCDA	= $(SERVER_PATH)*.gcda $(COMMANDS_PATH)*.gcda $(GRAPH_PATH)*.gcda

GCDA_FILES	= $(TEST_PATH)*.gcda $(SRC_GCDA)

GCOV_FILES	= ./*.c.gcov

all:		$(SERVER_NAME)

$(SERVER_NAME): $(SERVER_OBJ_MAIN) $(SVERVER_OBJ)
	gcc $(SERVER_OBJ_MAIN) $(SVERVER_OBJ) -o $(SERVER_NAME) $(CFLAGS)

tests_run:	$(TEST_OBJ) $(SVERVER_OBJ)
	gcc $(TEST_OBJ) $(SVERVER_OBJ) -o $(TEST_NAME) $(LDFLAGS) -lm
	./$(TEST_NAME)
	gcov $(GCDA_FILES)

tests_func: all clean
	./tests/functionnal_tests.sh

every_tests: tests_run tests_func

clean:
	rm -f $(SERVER_OBJ_MAIN) $(SVERVER_OBJ) $(TEST_OBJ) $(TEST_FILES)
	rm -f $(GCOV_FILES)

fclean: clean
	rm -f $(SERVER_NAME) $(TEST_NAME)

re: fclean all

go: re
	rm -f $(SERVER_OBJ_MAIN) $(SVERVER_OBJ) $(TEST_OBJ) $(TEST_FILES)

.PHONY: all tests_run clean fclean re go
