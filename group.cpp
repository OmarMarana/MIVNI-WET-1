#include "group.h"


group::~group()
{
    group_players_tree->postOrderAndDestroy(group_players_tree);
    max_level_player = nullptr; // check that it dosnt point to family

}


group::group(const group& other) : groupID(other.groupID)  // copy constructor
{
    // AVL_node<player, int> tree_copy = *(other.group_players_tree);
    // std::shared_ptr<AVL_node<player,int>> 
    // std::shared_ptr<AVL_node<player,int>> tmp = (std::make_shared<AVL_node>(tree_copy));

    this->group_players_tree = other.group_players_tree->clone( other.group_players_tree, other.group_players_tree->getFather());
    this->max_level_player = this->group_players_tree->find(this->group_players_tree, other.max_level_player->getKey());
    

} 


group& group::operator=(const group& other) // group1 = group2
{
    //dest
    group_players_tree->postOrderAndDestroy(group_players_tree);
    max_level_player = nullptr; // check that it dosnt point to family
    
    //cpy_const
    this->group_players_tree = other.group_players_tree->clone( other.group_players_tree, other.group_players_tree->getFather());
    this->max_level_player = this->group_players_tree->find(this->group_players_tree, other.max_level_player->getKey());

    return *this;
}

// bool operator==(const group& group1, const group& group2)
// {
//     //shared_ptr find(groups, int)
    
    
// }

int group::getGroupID() const
{
    return this->groupID;
}


std::shared_ptr<AVL_node<player,player::LevelAndId>> group::getPlayers_tree() const
{
    return this->group_players_tree;
    
}

std::shared_ptr<AVL_node<player,player::LevelAndId>> group::getMax_level_player() const
{
    return this->max_level_player;
}
