/*
** EPITECH PROJECT, 2018
** primary
** File description:
** primary.hpp primary.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <zconf.h>

#include "server.h"

TestSuite(initialisation);
TestSuite(display);

/*!
*	2 test on valid argument on "init_square_struct"
*/
Test(initialisation, valid_square_struct)
{
	square_t *square = malloc(sizeof(square_t));

	square->food = 7;
	init_square_struct(square);
	cr_assert(square->food == 0, \
	"Error: in \"init_square_struct\" at valid test");
}

/*!
*	1 test on valid argument on "init_teams_struct"
*/
Test(initialisation, team_struct_valid)
{
	teams_t *teams = init_teams_struct("test", 4);

	cr_assert(teams->max_players == 4, \
	"Error: in \"init_team_struct\" at valid test");
}

/*!
*	1 test on valid argument on "init_stones_struct"
*/
Test(initialisation, valid_stone_struct)
{
	stones_t *stones;

	init_stones_struct(&stones);
		cr_assert(stones->der == 0, \
	"Error: in \"init_stone_struct\" at valid test");
}

/*!
*	1 test on valid argument on "init_server_struct"
*/
Test(initialisation, valid_server_struct)
{
	server_t *server;

	server = init_server_struct(3, 10, 5, 5);
	cr_assert(server->fd == 3 && server->y == 5, \
	"Error: in \"init_server_struct\" at valid test");
}

/*!
*	1 test on valid argument on "init_map"
*/
Test(initialisation, valid_map)
{
	square_t **map = NULL;

	map = init_map(5, 5);
	cr_assert(map != NULL, \
	"Error: in \"init_map\" at valid test");
}

/*!
*	1 tests on valid argument on "func_array_init"
*/
Test(initialisation, command_array_init)
{
	char **tab = NULL;

	tab = command_array();
	cr_assert(tab != NULL, \
	"Error: in \"init_command_array\" at valid test");
}

/*!
*	1 tests on valid argument on "func_array_init"
*/
Test(initialisation, func_array_init)
{
	fp *tab = NULL;

	tab = func_array_init();
	cr_assert(tab != NULL, \
	"Error: in \"init_func_array\" at valid test");
}

/*!
*	1 tests on valid argument on "action_init"
*/
Test(initialisation, action_struct_init)
{
	actions_t	*action = NULL;

	action = init_struct_action(NULL, 5, 3);
	cr_assert(action != NULL, \
	"Error: in \"init_func_array\" at valid test");
}

/*!
*	1 tests on valid argument on "add_elem_action"
*	with player already set.
*/
Test(initialisation, add_elem_action_uninitialized)
{
	server_t	*server = init_server_struct(3, 5, 3, 3);
	players_t	*players = init_player_struct(4, server);

	add_elem_action(players, NULL, 5, 5);
	cr_assert(players->actions != NULL, \
	"Error: in \"add_elem_action\" at valid test");
}

/*!
*	1 tests on valid argument on "add_elem_action"
*	with player already set.
*/
Test(initialisation, add_elem_action_initialized)
{
	server_t	*server = init_server_struct(3, 5, 3, 3);
	actions_t	*action = init_struct_action(NULL, 5, 3);
	players_t	*players = init_player_struct(4, server);
	actions_t	*tmp = action;
	int i			= 0;

	add_elem_action(players, NULL, 5, 5);
	while (tmp) {
		tmp = tmp->next;
		i += 1;
	}
	cr_assert(i == 1, \
	"Error: in \"add_elem_action\" at valid test");
}

/*!
*	1 tests on valid argument on "fp_init_graph"
*/
Test(initialisation, fp_init_graph_valid)
{
	fp_g *tab = NULL;

	tab = fp_init_graph();
	cr_assert(tab != NULL, \
	"Error: in \"fp_init_graph\" at valid test");
}

/*!
*	1 tests on valid argument on "fp_init_graph"
*/
Test(initialisation, command_array_graph_valid)
{
	char **tab = NULL;

	tab = command_array_graph();
	cr_assert(tab != NULL, \
	"Error: in \"command_array_graph\" at valid test");
}

/*!
*	1 tests on valid argument on "init_graph_struct"
*/
Test(initialisation, init_graph_struct_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	cr_assert(server->graph != NULL, \
	"Error: in \"fp_init_graph\" at valid test");
}

/*!
*	1 tests on valid argument on "init_graph_monitor"
*/
Test(initialisation, init_graph_monitor_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	add_tmp_client(5, server);
	cr_assert(init_graph_monitor(-1, server) == ERROR, \
	"Error: in \"init_graph_monitor\" at wrong test");
}

/*!
*	1 tests on valid argument on "set_tab_bct"
*/
Test(initialisation, set_tab_bct_valid)
{
	char	*tab[4];

	tab[0] = malloc(sizeof(char) * 4);
	strcpy(tab[0], "bct\0");
	set_tab_bct(tab, 1, 2);

	cr_assert(strcmp(tab[2], "1") == 0 && strcmp(tab[1], "2") == 0 , \
	"Error: in \"set_tab_bct\" at valid test");
}

/*!
*	1 tests on valid argument on "mct"
*/
Test(initialisation, mct_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	char *tab[4];

	server->map = init_map(3, 3);
	tab[0] = malloc(sizeof(char) * 4);
	strcpy(tab[0], "bct\0");
	cr_assert(mct(server, tab) == SUCCESS , \
	"Error: in \"mct\" at valid test");
}

/*!
*	Tests on graphical_client_commands files
*/

/*!
*	1 test on "ebo" with valid test
*/
Test(graphical_proto, ebo_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	eggs->id = 4;
	cr_assert(ebo(server, eggs) == SUCCESS, \
	"Error: in \"ebo\" at valid test");
}

/*!
*	1 test on "ebo" with wrong test
*/
Test(graphical_proto, ebo_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	cr_assert(ebo(server, eggs) == ERROR, \
	"Error: in \"ebo\" at valid test");
}

/*!
*	1 test on "edi" with valid test
*/
Test(graphical_proto, edi_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	eggs->id = 4;
	cr_assert(edi(server, eggs) == SUCCESS, \
	"Error: in \"edi\" at valid test");
}

/*!
*	1 test on "edi" with wrong test
*/
Test(graphical_proto, edi_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	cr_assert(edi(server, eggs) == ERROR, \
	"Error: in \"edi\" at wrong test");
}

/*!
*	1 test on "eht" with wrong test
*/
Test(graphical_proto, eht_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	eggs->id = 4;
	cr_assert(eht(server, eggs) == SUCCESS, \
	"Error: in \"eht\" at valid test");
}

/*!
*	1 test on "eht" with wrong test
*/
Test(graphical_proto, eht_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	cr_assert(eht(server, eggs) == ERROR, \
	"Error: in \"eht\" at wrong test");
}

/*!
*	1 test on "enw" with wrong test
*/
Test(graphical_proto, enw_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	eggs->id = 4;
	cr_assert(enw(server, players, eggs) == SUCCESS, \
	"Error: in \"enw\" at valid test");
}

/*!
*	1 test on "enw" with wrong test
*/
Test(graphical_proto, enw_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*players = init_player_struct(6, server);
	eggs_t		*eggs = init_eggs_struct(players, 5);

	cr_assert(enw(server, players, eggs) == ERROR, \
	"Error: in \"enw\" at wrong test");
}

/*!
* 	One test on "msz" with valid argument
*/
Test(graphical_proto, map_size_valid)
{
	server_t	*server;

	server = init_server_struct(3, 10, 3, 3);
	server->graph = init_graph_struct();
	server->graph->fd = 3;
	cr_assert(msz(server, NULL) == SUCCESS, \
	"Error: in \"msz\" at valid test");
}

/*!
* 	One test on "msz" with wrong argument
*/
Test(graphical_proto, map_size_wrong)
{
	server_t	*server;

	server = init_server_struct(3, 10, 3, 3);
	cr_assert(msz(server, NULL) == ERROR, \
	"Error: in \"msz\" at wrong test");
}

/*!
*	1 tests on valid argument on "suc"
*/
Test(graphical_proto, suc_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(suc(server) == SUCCESS , \
	"Error: in \"suc\" at valid test");
}

/*!
*	1 tests on wrong argument on "suc"
*/
Test(graphical_proto, suc_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	cr_assert(suc(server) == ERROR , \
	"Error: in \"suc\" at wrong test");
}

/*!
*	1 tests on valid argument on "pbc"
*/
Test(graphical_proto, pbc_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);
	char 		*msg = "test";

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pbc(server, player, msg) == SUCCESS , \
	"Error: in \"pbc\" at valid test");
}

/*!
*	1 tests on wrong argument on "pbc"
*/
Test(graphical_proto, pbc_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);
	char 		*msg = "test";

	cr_assert(pbc(server, player, msg) == ERROR , \
	"Error: in \"pbc\" at wrong test");
}

/*!
*	1 tests on valid argument on "pdi"
*/
Test(graphical_proto, pdi_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pdi(server, player) == SUCCESS , \
	"Error: in \"pdi\" at valid test");
}

/*!
*	1 tests on wrong argument on "pdi"
*/
Test(graphical_proto, pdi_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	cr_assert(pdi(server, player) == ERROR , \
	"Error: in \"pdi\" at wrong test");
}

/*!
*	1 tests on valid argument on "pdr"
*/
Test(graphical_proto, pdr_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pdr(server, player, 3) == SUCCESS , \
	"Error: in \"pdr\" at valid test");
}

/*!
*	1 tests on wrong argument on "pdr"
*/
Test(graphical_proto, pdr_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	cr_assert(pdr(server, player, 3) == ERROR , \
	"Error: in \"pdr\" at wrong test");
}

/*!
*	1 tests on valid argument on "pex"
*/
Test(graphical_proto, pex_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pex(server, player) == SUCCESS , \
	"Error: in \"pex\" at valid test");
}

/*!
*	1 tests on wrong argument on "pex"
*/
Test(graphical_proto, pex_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	cr_assert(pex(server, player) == ERROR , \
	"Error: in \"pex\" at wrong test");
}

/*!
*	1 tests on valid argument on "pfk"
*/
Test(graphical_proto, pfk_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pfk(server, player) == SUCCESS , \
	"Error: in \"pfk\" at valid test");
}

/*!
*	1 tests on wrong argument on "pfk"
*/
Test(graphical_proto, pfk_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	cr_assert(pfk(server, player) == ERROR , \
	"Error: in \"pfk\" at wrong test");
}

/*!
*	1 tests on valid argument on "pie_success"
*/
Test(graphical_proto, pie_success_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pie_success(server, player) == SUCCESS , \
	"Error: in \"pie_success\" at valid test");
}

/*!
*	1 tests on wrong argument on "pie_success"
*/
Test(graphical_proto, pie_success_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	cr_assert(pie_success(server, player) == ERROR , \
	"Error: in \"pie_success\" at wrong test");
}

/*!
*	1 tests on valid argument on "pie_failure"
*/
Test(graphical_proto, pie_failure_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pie_failure(server, player) == SUCCESS , \
	"Error: in \"pie_failure\" at valid test");
}

/*!
*	1 tests on wrong argument on "pie_failure"
*/
Test(graphical_proto, pie_failure_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	players_t	*player = init_player_struct(5, server);

	server->graph = init_graph_struct();
	cr_assert(pie_failure(server, player) == ERROR , \
	"Error: in \"pie_failure\" at wrong test");
}

/*!
*	1 tests on valid argument on "sbp"
*/
Test(graphical_proto, sbp_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(sbp(server) == SUCCESS , \
	"Error: in \"sbp\" at valid test");
}

/*!
*	1 tests on wrong argument on "sbp"
*/
Test(graphical_proto, sbp_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	cr_assert(sbp(server) == ERROR , \
	"Error: in \"sbp\" at wrong test");
}

/*!
*	1 tests on valid argument on "seg"
*/
Test(graphical_proto, seg_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	teams_t		*team = init_teams_struct("test", 3);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(seg(server, team) == SUCCESS , \
	"Error: in \"seg\" at valid test");
}

/*!
*	1 tests on wrong argument on "seg"
*/
Test(graphical_proto, seg_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	teams_t		*team = init_teams_struct("test", 3);

	server->graph = init_graph_struct();
	cr_assert(seg(server, team) == ERROR , \
	"Error: in \"seg\" at wrong test");
}

/*!
*	1 tests on valid argument on "smg"
*/
Test(graphical_proto, smg_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(smg(server, "test") == SUCCESS , \
	"Error: in \"smg\" at valid test");
}

/*!
*	1 tests on wrong argument on "smg"
*/
Test(graphical_proto, smg_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	cr_assert(smg(server, "test") == ERROR , \
	"Error: in \"smg\" at wrong test");
}

/*!
*	1 tests on valid argument on "tna"
*/
Test(graphical_proto, tna_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	server->teams = init_teams_struct("test", 2);
	server->teams->players = init_player_struct(5, server);
	server->teams->players->next = init_player_struct(6, server);
	cr_assert(tna(server, NULL) == SUCCESS , \
	"Error: in \"tna\" at valid test");
}

/*!
*	1 tests on wrong argument on "tna"
*/
Test(graphical_proto, tna_wrong)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->teams = init_teams_struct("test", 2);
	server->teams->players = init_player_struct(4, server);
	server->teams->players->next = init_player_struct(5, server);
	cr_assert(tna(server, NULL) == ERROR , \
	"Error: in \"tna\" at wrong test");
}


/*!
*	1 tests on failure argument on "ppo"
*/
Test(graphical_proto, ppo_failure)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	char 		*tab[] = {
		"test",
		"test",
		"test",
		NULL
	};

	cr_assert(ppo(server, tab) == FAILURE , \
	"Error: in \"ppo\" at failure test");
}

/*!
*	1 tests on failure argument on "ppo"
*/
Test(graphical_proto, ppo_error)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	char 		*tab[] = {
		"ppo",
		"#4",
		NULL
	};

	server->graph = init_graph_struct();
	server->teams = init_teams_struct("test", 3);
	server->teams->players = init_player_struct(4, server);
	cr_assert(ppo(server, tab) == ERROR , \
	"Error: in \"ppo\" at error test");
}

/*!
*	1 tests on valid argument on "pnw"
*/
Test(graphical_proto, pnw_valid)
{
	server_t	*server = init_server_struct(5, 10, 3, 3);

	server->teams = init_teams_struct("test", 3);
	server->teams->players = init_player_struct(6, server);
	server->graph = init_graph_struct();
	server->graph->fd = 4;
	cr_assert(pnw(server, server->teams, \
	server->teams->players) == SUCCESS , \
	"Error: in \"pnw\" at valid test");
}

/*!
*	1 tests on valid argument on "pnw"
*/
Test(graphical_proto, pnw_wrong)
{
	server_t	*server = init_server_struct(5, 10, 3, 3);

	server->teams = init_teams_struct("test", 3);
	server->teams->players = init_player_struct(6, server);
	server->graph = init_graph_struct();
	cr_assert(pnw(server, server->teams, \
	server->teams->players) == ERROR , \
	"Error: in \"pnw\" at wrong test");
}

/*!
*	1 tests on failure argument on "plv"
*/
Test(graphical_proto, plv_failure)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	char 		*tab[] = {
		"test",
		"test",
		"test",
		NULL
	};

	cr_assert(plv(server, tab) == FAILURE , \
	"Error: in \"plv\" at failure test");
}

/*!
*	1 tests on failure argument on "plv"
*/
Test(graphical_proto, plv_error)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);
	char 		*tab[] = {
		"plv",
		"#4",
		NULL
	};

	server->graph = init_graph_struct();
	server->teams = init_teams_struct("test", 3);
	server->teams->players = init_player_struct(4, server);
	cr_assert(plv(server, tab) == ERROR , \
	"Error: in \"plv\" at error test");
}

/*!
*	1 tests on failure argument on "pgt"
*/
Test(graphical_proto, pgt_valid)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	server->graph->fd = 4;
	server->teams = init_teams_struct("test", 3);
	server->teams->players = init_player_struct(5, server);
	cr_assert(pgt(server, server->teams->players, 0) == SUCCESS , \
	"valid: in \"pgt\" at valid test");
}

/*!
*	1 tests on failure argument on "pgt"
*/
Test(graphical_proto, pgt_failure)
{
	server_t	*server = init_server_struct(3, 10, 3, 3);

	server->graph = init_graph_struct();
	server->teams = init_teams_struct("test", 3);
	server->teams->players = init_player_struct(5, server);
	cr_assert(pgt(server, server->teams->players, 0) == ERROR , \
	"valid: in \"pgt\" at failure test");
}

/*!
*	1 tests on failure argument on "pgt"
*/
Test(graphical_proto, handle_other_ressources_set_if)
{
	cr_assert(handle_other_ressources_set(-1, NULL, NULL) == FAILURE , \
	"valid: in \"pgt\" at failure test");
}

/*!
*	1 tests on valid argument on "end_game"
*/
Test(common_src, end_game_valid)
{
	server_t *server;
	char *av[] = {
		"./zappy_server",
		"-p",
		"2000",
		"-x",
		"3",
		"-y",
		"3",
		"-n",
		"test",
		"-c",
		"10",
		"-f",
		"10"
	};
	srand(time(NULL));
	handle_params(av, 13);
	server = init_server_struct(create_socket(atoi(av[2])), \
        atoi(av[13 - 1]), atoi(av[4]), atoi(av[6]));
	init_teams_list(server, av);
	cr_assert(end_game(server, server->active_set) == SUCCESS, \
        "Error: in \"end_game\" at valid test");
}