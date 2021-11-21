#ifndef GROUP_H
#define GROUP_H
#include "AVLnode.h"
#include "player.h"
#include <stdbool>

#include <iostream>


class  group
{


    private:
    int groupID;
    AVL_node <player,int> *players_tree;
    AVL_node<player,int> *max_level_player;

    public:

    group() : groupID(-1) , players_tree(nullptr), max_level_player(nullptr); //constructor
    group(int groupID, AVL_node <player, int> *players_tree, AVL_node<player,int> *max_level_player ) : groupID(groupID) , 
    players_tree(players_tree), max_level_player(max_level_player)); //constructor
    
    ~group(); //destructor
    group(const group&); //copy constructor
    group& operator=(const group& other); // avl_node1= avl_node2

    friend bool operator==(const group& group1, const group& group2);
    friend bool operator<(const group& group1, const group& group2);
    friend bool operator>(const group& group1, const group& group2);

    
    

    
};


#endif 