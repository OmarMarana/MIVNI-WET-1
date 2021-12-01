#ifndef GROUP_H
#define GROUP_H
#include "AVLnode.h"
#include "player.h"
#include <stdbool.h>

#include <iostream>

//class player;

//class LevelAndId;

class  group
{
    private:
        int groupID;
        std::shared_ptr<AVL_node<player,LevelAndId>> group_players_tree;
        std::shared_ptr<AVL_node<player,LevelAndId>> max_level_player;


    


    public:

        group() : groupID(-1) , group_players_tree(nullptr), max_level_player(nullptr) {}; //constructor
        group(int groupID, std::shared_ptr<AVL_node<player,LevelAndId>> group_players_tree, 
        std::shared_ptr<AVL_node<player,LevelAndId>> max_level_player ): groupID(groupID) , 
        group_players_tree(group_players_tree), max_level_player(max_level_player) {}; //constructor
        
        ~group(); //destructor
        group(const group&); //copy constructor
        group& operator=(const group& other); // group1 = group2
    
        // friend bool operator==(const group& group1, const group& group2);
        // friend bool operator<(const group& group1, const group& group2);
        // friend bool operator>(const group& group1, const group& group2);

        int getGroupID() const;
        std::shared_ptr<AVL_node<player,LevelAndId>> getPlayers_tree() const; // maybe 
        std::shared_ptr<AVL_node<player,LevelAndId>> getMax_level_player() const;






};

// group::










#endif 