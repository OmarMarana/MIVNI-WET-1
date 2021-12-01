#include "player.h"


player::~player()
{   
    this->group_node = nullptr;
    this->player_node = nullptr;
}

player& player::operator=(const player& other)
{
    this->level_and_id = other.level_and_id;
    this->group_node = nullptr;
    this->player_node = nullptr;

    this->group_node =  other.group_node;
    this->player_node = other.player_node;

    //max_level_player = nullptr; // check that it dosnt point to family
    //group& group::operator=(const group& other)
    return *this;

}


void* player::getGroup_node()
{
    return this->group_node;
}


std::shared_ptr<AVL_node<player,int>> player::getPlayer_node()
{
    return this->player_node;
}

LevelAndId player::getplayerLevelAndId()
{
    return this->level_and_id;
}
