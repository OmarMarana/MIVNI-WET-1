#ifndef PLAYER_MANAGER_H
#define PLAYER_MANGER_H

#include "library1.h"
#include "AVLnode.h"
#include <iostream>
#include "group.h"
#include "player.h"

class PlayerManager
{
    private:

    AVL_node<player,int> *player_tree;
    AVL_node<group,int> *group_tree;
    

    
    

    public:

    player() : playerID(-1), level(-1),group_node(nullptr),  player_node(nullptr); //constructor
    player(int playerID,int level, AVL_node<group,int> *group_node, AVL_node<player,int> *player_node) :
    playerID(playerID), level(level), group_node(group_node), player_node(player_node) ; //constructor
    ~player(); //destructor
    player(const player&); //copy constructor
    player& operator=(const player& other); // avl_node1= avl_node2

    friend bool operator==(const player& player1, const player& player2);
    friend bool operator>(const player& player1, const player& player2);
    friend bool operator<(const player& player1, const player& player2);
}


#endif