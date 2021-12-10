#ifndef PLAYER_MANAGER_H
#define PLAYER_MANGER_H

#include "library1.h"
// #include "AVLnode.h"
#include <iostream>
#include "PlayerManagerUtilities.h"

class PlayerManager
{
    private:

    std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> level_and_id_player_tree;
    std::shared_ptr<AVL_node<player,int>> int_player_tree;
    std::shared_ptr<AVL_node<group,int>> group_tree;
    std::shared_ptr<AVL_node<LevelAndId,int>> max_level_group_tree;
    int num_of_players;
    int num_of_non_empty_groups;
    LevelAndId max_level_min_ID;

    public:

    PlayerManager() :level_and_id_player_tree(nullptr),int_player_tree(nullptr),group_tree(nullptr),
    max_level_group_tree(nullptr) ,num_of_players(0),num_of_non_empty_groups(0) , max_level_min_ID(-1,-1,nullptr) {}; //constructor
    ~PlayerManager();
    std::shared_ptr<AVL_node<group,int>>  Getgroup_tree()const;


    StatusType PMAddGroup( int GroupID);

    StatusType PMAddPlayer( int PlayerID, int GroupID, int Level);

    StatusType PMRemovePlayer( int PlayerID);

    StatusType PMReplaceGroup( int GroupID, int ReplacementID);

    StatusType PMIncreaseLevel( int PlayerID, int LevelIncrease);

    StatusType PMGetHighestLevel( int GroupID, int *PlayerID);

    StatusType PMGetAllPlayersByLevel( int GroupID, int **Players, int *numOfPlayers);

    StatusType PMGetGroupsHighestLevel( int numOfGroups, int **Players);
};


#endif