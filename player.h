#ifndef PLAYER_H
#define PLAYER_H

#include "AVLnode.h"
#include <iostream>
#include "level_and_id.h"


class player 
{

    private:
    LevelAndId level_and_id;
//    std::shared_ptr<AVL_node<group,int>> group_node;
    void *group_node;
    std::shared_ptr<AVL_node<player,int>> player_node; 


    public:


    player() : level_and_id(-1,-1) ,group_node(nullptr),  player_node(nullptr) {}; //constructor
    player(int level,int playerID, void *group_node, std::shared_ptr<AVL_node<player,int>> player_node) :
            level_and_id(level,playerID), group_node(group_node), player_node(player_node) {}; //constructor
    ~player(); //destructor
    player(const player&) = default; //copy constructor
    player& operator=(const player& other); // avl_node1= avl_node2
    LevelAndId getplayerLevelAndId();
    void* getGroup_node(); // maybe &
    std::shared_ptr<AVL_node<player,int>> getPlayer_node();

    void setPlayerGnode(void *gnode);


};


#endif 