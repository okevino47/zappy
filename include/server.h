/*
** EPITECH PROJECT, 2018
** irc
** File description:
** server.h
*/

#ifndef SERVER_H_
	#define SERVER_H_

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <math.h>
#include "macros.h"
#include "structs.h"

typedef void (*fp)(server_t *, actions_t *, int);
typedef int (*fp_g)(server_t *, char **);

void init_stones_struct(stones_t **stone);
players_t *init_player_struct(int fd, server_t *server);
server_t *init_server_struct(int fd, int freq, int x, int y);
teams_t *init_teams_struct(char *name, int max_players);
square_t **init_map(int x, int y);
void init_square_struct(square_t *square);
int handle_params(char **av, int ac);
void handle_client(fd_set read_set, fd_set *active_set, server_t *server);
int create_socket(int port);
void init_teams_list(server_t *server, char **av);
void launch_server(server_t *server);
void add_tmp_client(int fd, server_t *server);
int check_client(int fd, server_t *server);
teams_t *get_team_by_name(char *name, server_t *server);
players_t *get_valid_player(int fd, server_t *server);
void add_elem_player(server_t *server, char *name, players_t *player);
int delete_tmp_client(int fd, server_t *server);
players_t *get_current_player(const int fd, const server_t *server);
players_t *check_if_player_is_in_team(const int fd, players_t *player);
void stock_command(char *command, int fd, server_t *server);
void parse_commands(int fd, server_t *server);
char **str_to_word_array(char *command);
int tab_size(char **tab);
char **command_array(void);
void create_action_elem(int command_id, players_t *player, char **tab, \
	server_t *server);
cbuff_t *init_cbuff_struct(void);
fp *func_array_init(void);
void update_cycles(server_t *server, fd_set *active_set);
void delete_action_elem(actions_t *action, players_t *player);
int count_all_ressources(const square_t *square);
int handle_other_ressources_set(int i, square_t *square, players_t *player);
int gen_ressources(square_t *square, const int choice);
int generate_random_values(const server_t *server, int *line, int *col, \
	int *choice);
square_t **random_ressources_generation(const server_t *server);
players_t *get_current_player(const int fd, const server_t *server);
void add_player_square(players_t *player, server_t *server);
void delete_player_square(players_t *player, server_t *server);
teams_t *get_team_by_player(players_t *player, server_t *server);
char **ressources_array(void);
char **name_stones_array(void);
actions_t *init_struct_action(char **tab, int cycles, int id);
void add_elem_action(players_t *player, char **tab, int cycles, int id);
int choose_eject_square_coord(int *line, int *col, const players_t *player, \
	const server_t *server);
void eject_command(server_t *server, actions_t *action, int fd);
int choose_eject_square_coord(int *line, int *col, const players_t *player, \
const server_t *server);
int eject_every_player(const int line, const int col, node_player_t **list, \
	server_t *server);
bool check_lvl(int lvl, square_t *square);
void update_lvl(square_t *square);
void rise_lvl_two(players_t *player, server_t *server);
void rise_lvl_three(players_t *player, server_t *server);
void rise_lvl_four(players_t *player, server_t *server);
void rise_lvl_five(players_t *player, server_t *server);
void rise_lvl_six(players_t *player, server_t *server);
void rise_lvl_seven(players_t *player, server_t *server);
void rise_lvl_eight(players_t *player, server_t *server);
int update_y(players_t *player, int y);
int add_perm_client(server_t *server, int fd, teams_t *team);
int remove_client(int fd, fd_set *active_set);
void delete_player_elem(players_t *player, server_t *server);
eggs_t *init_eggs_struct(players_t *player, int id);
eggs_t *add_elem_egg(teams_t *team, players_t *player);
void delete_egg_elem(teams_t *team, eggs_t *egg);
char *pickup_command(cbuff_t *c_buf);
void copy_buffer(char *buff_tmp, cbuff_t *c_buf);
void update_read_on(cbuff_t *buf, int len);
int init_graph_monitor(int fd, server_t *server);
graph_t *init_graph_struct(void);
char **command_array_graph(void);
fp_g *fp_init_graph(void);
void parse_graph_commands(server_t *server);
int pnw(server_t *server, teams_t *team, players_t *player);
int pex(server_t *server, players_t *player);
int pbc(server_t *server, players_t *player, char *message);
int pic(server_t *server, players_t *player);
int pie_success(server_t *server, players_t *player);
int pie_failure(server_t *server, players_t *player);
int pfk(server_t *server, players_t *player);
int pdr(server_t *server, players_t *player, int ressource);
int pgt(server_t *server, players_t *player, int ressource);
int pdi(server_t *server, players_t *player);
int enw(server_t *server, players_t *player, eggs_t *egg);
int eht(server_t *server, eggs_t *egg);
int ebo(server_t *server, eggs_t *egg);
int edi(server_t *server, eggs_t *egg);
int seg(server_t *server, teams_t *team);
int smg(server_t *server, char *mess);
int suc(server_t *server);
int sbp(server_t *server);
int msz(server_t *server, char **tab);
int bct(server_t *server, char **tab);
int mct(server_t *server, char **tab);
int tna(server_t *server, char **tab);
int ppo(server_t *server, char **tab);
int plv(server_t *server, char **tab);
int pin(server_t *server, char **tab);
int quit(server_t *server, char **tab);
char **set_tab_bct(char **tab, int i, int j);
int exec_commands_graph(char *command, server_t *server);
players_t *check_pin_ppo_plv(char **tab, server_t *server);
int end_game(server_t *server, fd_set *active_set);
void update_game(fd_set read_set, server_t *server, fd_set *active_set);
bool client_is_tmp(int fd, server_t *server);
int get_broadcast_nb(players_t *receiver, players_t *sender);
int convert_right(int broad_nb);
int convert_down(int broad_nb);
int convert_left(int broad_nb);
void handle_read_ret(int read_ret, server_t *server, players_t *player);
int x_equals_broad(players_t *receiver, players_t *sender);
int y_equals_broad(players_t *receiver, players_t *sender);
int elevation_underway_propagate(server_t *server, players_t *player);
int end_elevation_propagate(server_t *server, players_t *player);
int fail_elevation_propagate(server_t *server, players_t *player);
int fill_eject_list(node_player_t **list, const players_t *player, \
	const square_t **map);

void broadcast_command(server_t *server, actions_t *action, int fd);
void connect_nbr_command(server_t *server, actions_t *action, int fd);
void eject_command(server_t *server, actions_t *action, int fd);
void fork_command(server_t *server, actions_t *action, int fd);
void forward_command(server_t *server, actions_t *action, int fd);
void incantation_command(server_t *server, actions_t *action, int fd);
void inventory_command(server_t *server, actions_t *action, int fd);
void left_command(server_t *server, actions_t *action, int fd);
void look_command(server_t *server, actions_t *action, int fd);
void right_command(server_t *server, actions_t *action, int fd);
void set_command(server_t *server, actions_t *action, int fd);
void take_command(server_t *server, actions_t *action, int fd);

#endif /* !SERVER_H_ */