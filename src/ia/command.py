#!/usr/bin/env python3

import getInfo
import time

# @brief return lvl of the player after evolution
# @param string to parse
# @param current lvl
# @return lvl on the player


def checkCurrentLevel(data, lvl):
    if ("Current" in data):
        data = data.replace("b'", "")
        data = data.replace("\\n", "")
        data = data.replace("'", "")
        data = data.replace("]", "")
        data = data.replace("[", "")
        listData = data.split(":")
        returnValue = listData[1]
        return (returnValue)
    else:
        return (lvl)

# @brief return position of the elem in 2D from look
# @param requested elem
# @param current lvl
# @param socket
# @return number of forward
# @return number of forward after turning action
# @return requested elem


def findPosElem(elem, lvl, sock):
    view = getInfo.getLook(sock, lvl)
    view = view.replace("b'", "")
    view = view.replace("\\n", "")
    view = view.replace("'", "")
    view = view.replace("]", "")
    view = view.replace("[", "")
    listView = view.split(',')
    pos = -1
    nb_forward = 0
    nb_turn = 0
    x = -1
    while (x < len(listView)):
        listElem = listView[x].split(' ')
        y = 0
        while (y < len(listElem)):
            if (listElem[y] == elem):
                pos = x
                break
            y = y + 1
        x = x + 1
    if (pos == -1):
        return (0, 0, -1)
    x = 0
    while (x <= lvl):
        if (pos >= (x * (x + 1) - x) and pos <= (x * (x + 1) + x)):
            nb_forward = x
            break
        x = x + 1
    nb_turn = pos - (x * (x + 1))
    return (nb_forward, nb_turn, elem)

# @brief return the missing stone to evolve or food if he doesn't have
# enough of it
# @param current lvl of the player
# @param socket
# @return missing stone or food


def getLvl(lvl, sock):
    i = 0
    inventory = getInfo.getInventory(sock, lvl)
    inventory = inventory.replace("b'", "")
    inventory = inventory.replace("\\n", "")
    inventory = inventory.replace("'", "")
    inventory = inventory.replace("]", "")
    inventory = inventory.replace("[", "")
    copyInventory = inventory
    inventory = inventory.split(',')
    while (i < len(inventory)):
        ligne = inventory[i]
        if (i != 0):
            ligne = ligne[1:]
        ligne = ligne.split(' ')
        if (ligne[0] == "food" and ligne[1] < "5"):
            return ("food")
        i = i + 1
    return (stoneNeeded(lvl, copyInventory))

# @brief return the missing stone to evolve
# @param current lvl of the player
# @param inventory of the player
# @return stone


def stoneNeeded(lvl, inventory):
    i = 0
    j = 0
    stone = getStoneByLvl(lvl)
    inventory = inventory.split(',')
    while (i < len(inventory)):
        ligne = inventory[i]
        if (i != 0):
            ligne = ligne[1:]
        ligne = ligne.split(' ')
        j = 0
        while (j < len(stone)):
            listStone = stone[j].split(' ')
            if (ligne[0] == listStone[0] and ligne[1] <= listStone[1]):
                return (listStone[0])
            j = j + 1
        i = i + 1
    return (-1)

# @brief return tab according to the lvl of the player
# @param current lvl of the player
# @return tab of stone


def getStoneByLvl(lvl):
    stone = []
    if (lvl == 1):
        stone.append("linemate 1")
    elif (lvl == 2):
        stone.append("linemate 1")
        stone.append("deraumere 1")
        stone.append("sibur 1")
    elif (lvl == 3):
        stone.append("linemate 2")
        stone.append("sibur 1")
        stone.append("phiras 2")
    elif (lvl == 4):
        stone.append("linemate 1")
        stone.append("deraumere 1")
        stone.append("sibur 2")
        stone.append("phiras 1")
    elif (lvl == 5):
        stone.append("linemate 1")
        stone.append("deraumere 2")
        stone.append("sibur 1")
        stone.append("mendiane 3")
    elif (lvl == 6):
        stone.append("linemate 1")
        stone.append("deraumere 2")
        stone.append("sibur 3")
        stone.append("phiras 1")
    elif (lvl == 7):
        stone.append("linemate 2")
        stone.append("deraumere 2")
        stone.append("sibur 2")
        stone.append("mendiane 2")
        stone.append("phiras 2")
        stone.append("thystame 1")
    return (stone)
