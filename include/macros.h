/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** macros
*/

#ifndef MACROS_H_
	#define MACROS_H_

#define CMD_INVENTORY ("Inventory")
#define CMD_FWD ("Forward")
#define CMD_RIGHT ("Right")
#define CMD_LEFT ("Left")
#define CMD_LOOK ("Look")
#define CMD_BROAD ("Broadcast")
#define CMD_EJECT ("Eject")
#define CMD_TAKE ("Take")
#define CMD_SET ("Set")
#define CMD_CONN_NBR ("Connect_nbr")
#define CMD_FORK ("Fork")
#define CMD_INCANT ("Incantation")

#define REPL_OK ("ok\n")
#define REPL_KO ("ko\n")
#define REPL_OK_INCANT ("Current level: %d\n")
#define REPL_INVENTORY ("[ food %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystame %d ]\n")
#define REPL_BROAD ("message %d, %s\n")

#define ABS(a) ((a < 0) ? (a * -1) : (a))

enum e_test_activation {
	ACTIV = 1,
	DESAC = 0
};

enum e_return_values {
	SUCCESS = 0,
	ERROR	= 84,
	FAILURE = -1
};

enum e_actions {
	CONN_NBR,
	INVENTORY,
	FWD,
	RIGHT,
	LEFT,
	LOOK,
	BROAD,
	EJECT,
	TAKE,
	SET,
	FORK,
	INCANT,
};

typedef enum e_direction {
	D_UP = 1,
	D_RIGHT = 2,
	D_DOWN = 3,
	D_LEFT = 4
}	e_direction;

#endif /* !MACROS_H_ */
