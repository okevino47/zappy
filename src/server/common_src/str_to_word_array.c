/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** str to word array
*/

#include "server.h"

/*!
* @brief gets the nb of elem of an array of strings
* @param tab the tab to calcul the size
* @return int nb of elem in the array
*/
int tab_size(char **tab)
{
	int i = 0;

	for (; tab[i] != NULL; i++);
	return (i);
}

/*!
* @brief splits a string into a word array with spaces and \t
* @param command the string to explode
* @return char ** the array containing all words
*/
char **str_to_word_array(char *command)
{
	char **tab = NULL;
	char *word = strtok(command, " \t");

	for (int i = 0; word; i++) {
		tab = realloc(tab, sizeof(char *) * (i + 2));
		tab[i] = malloc(sizeof(char) * (strlen(word) + 1));
		strcpy(tab[i], word);
		tab[i + 1] = NULL;
		word = strtok(NULL, " \t");
	}
	return (tab);
}