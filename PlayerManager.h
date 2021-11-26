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

    PlayerManager() :player_tree(nullptr),group_tree(nullptr) {}; //constructor
    PlayerManager(AVL_node<player,int> *player_tree, AVL_node<group,int> *group_tree) :
    player_tree(player_tree),group_tree(group_tree) {} ; //constructor
    ~PlayerManager(); //destructor
    PlayerManager(const PlayerManager& player_manager); //copy constructor
    PlayerManager& operator=(const PlayerManager& other); // avl_node1= avl_node2


    StatusType PMAddGroup( int GroupID);


    // res = pm.addplayer(1,2,10).adp;

    StatusType PMAddPlayer( int PlayerID, int GroupID, int Level);

    StatusType PMRemovePlayer( int PlayerID);

    StatusType PMReplaceGroup( int GroupID, int ReplacementID);

    StatusType PMIncreaseLevel( int PlayerID, int LevelIncrease);

    StatusType PMGetHighestLevel( int GroupID, int *PlayerID);

    StatusType PMGetAllPlayersByLevel( int GroupID, int **Players, int *numOfPlayers);

    StatusType PMGetGroupsHighestLevel( int numOfGroups, int **Players);
};


#endif