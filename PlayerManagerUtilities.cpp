//
// Created by omarm on 02/12/2021.
//

#include "PlayerManagerUtilities.h"



//******************************************************
//******************************************************
//******************************************************
//player
//******************************************************
//******************************************************
//******************************************************


player::~player()
{
    this->group_node = nullptr;
    // this->player_node = nullptr;
}
void player::setPlayerLevel(int new_level)
{
    this->level_and_id.Level = new_level;
}

player& player::operator=(const player& other)
{
    this->level_and_id = other.level_and_id;
    this->group_node = nullptr;
    // this->player_node = nullptr;

    this->group_node =  other.group_node;
    // this->player_node = other.player_node;

    //max_level_player = nullptr; // check that it dosnt point to family
    //group& group::operator=(const group& other)
    return *this;

}


std::shared_ptr<AVL_node<group,int>> player::getGroup_node()const
{
    return this->group_node;
}


// std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> player::getPlayer_node()const
// {
//     return this->player_node;
// }

LevelAndId player::getplayerLevelAndId()
{
    return this->level_and_id;
}


void player::setPlayerGnode(std::shared_ptr<AVL_node<group,int>> gnode)
{
    this->group_node= gnode;
}


//******************************************************
//******************************************************
//******************************************************
//group
//******************************************************
//******************************************************
//******************************************************





group::~group()
{
    group_players_tree->postOrderAndDestroy(group_players_tree);
    group_players_tree = nullptr;
    max_level_player = nullptr; // check that it dosnt point to family

}


group::group(const group& other) : groupID(other.groupID),num_of_players(other.num_of_players)  // copy constructor
{
    // AVL_node<player, int> tree_copy = *(other.group_players_tree);
    // std::shared_ptr<AVL_node<player,int>>
    // std::shared_ptr<AVL_node<player,int>> tmp = (std::make_shared<AVL_node>(tree_copy));
    /*
     * OTHER:
     * gropuID =3;
     * tree = null;
     * max = null;
     *
     * */

    if(other.group_players_tree == nullptr)
    {
        this->group_players_tree = nullptr;
    }
    else
    {
        this->group_players_tree = other.group_players_tree->clone( other.group_players_tree, other.group_players_tree->getFather());
    }

    if(other.max_level_player == nullptr)
    {
        this->max_level_player = nullptr;
    }
    else
    {
        this->max_level_player = this->group_players_tree->find(this->group_players_tree, other.max_level_player->getKey());
    }


}


group& group::operator=(const group& other) // group1 = group2
{
    this->groupID = other.groupID;
    this->num_of_players = other.num_of_players;
    //dest
    group_players_tree->postOrderAndDestroy(group_players_tree);
    max_level_player = nullptr; // check that it dosnt point to family

    //cpy_const
    if(other.group_players_tree == nullptr)
    {
        this->group_players_tree = nullptr;

    }
    else
    {
        this->group_players_tree = other.group_players_tree->clone( other.group_players_tree, other.group_players_tree->getFather());
        this->max_level_player = this->group_players_tree->find(this->group_players_tree, other.max_level_player->getKey());
    }



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


std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> group::getPlayers_tree() const
{
    return this->group_players_tree;

}

std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> group::getMax_level_player() const
{
    return this->max_level_player;
}

void group::setPlayers_tree(std::shared_ptr<AVL_node<LevelAndId,LevelAndId>>new_group_players_tree )
{
    this->group_players_tree = new_group_players_tree;
}


void group::set_max_level_player(std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> new_max_level_player)
{
    this->max_level_player = new_max_level_player;
}

void group::setnNum_of_players(int delta)
{
    this->num_of_players += delta;

}

int group::get_num_of_players() const
{
    return this->num_of_players;
}


//******************************************************
//******************************************************
//******************************************************
//LevelAndId
//******************************************************
//******************************************************
//******************************************************

//
// Created by omarm on 02/12/2021.
//



bool LevelAndId::operator>(const LevelAndId& other) const
{

    /*
    if its not less than and not equal then it must be larger than
    assuming the < and == are defined properly;
    */
    if( (*this < other ) == false && (*this == other ) == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LevelAndId::operator<(const LevelAndId& other) const
{
    //LI1 < LI2?
    //this < other? true if this.id > other.id
    if(this->Level == other.Level)
    {
        if(this->Id > other.Id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //if levels arent equal then ids are irrelevant
    return this->Level < other.Level;
}

bool LevelAndId::operator==(const LevelAndId& other) const
{
    return ( (this->Id == other.Id) && (this->Level == other.Level) );
}

int LevelAndId::getLevel() const
{
    return Level;
}
int LevelAndId::getId() const
{
    return Id;
}

std::shared_ptr<AVL_node<player,int>> LevelAndId::getPlayer_node() const
{
    return this->player_node;
}

LevelAndId::~LevelAndId()
{
    this->player_node = nullptr;
}


void  LevelAndId::setPlayer_node(std::shared_ptr<AVL_node<player,int>> new_player_node)
{
    this->player_node = new_player_node;
}

LevelAndId::LevelAndId(const LevelAndId& other ) : Level(other.Level),Id(other.Id)
{
    this->player_node = nullptr;
    this->player_node = other.player_node;
}





