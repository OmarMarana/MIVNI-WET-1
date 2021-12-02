//
// Created by omarm on 02/12/2021.
//


#include "PlayerManager.h"
#include "AVLnode.h"
#include "group.h"
#include <execution>

StatusType PlayerManager::PMAddGroup( int GroupID)
{
    if(GroupID <= 0) return INVALID_INPUT;
    if(this->group_tree->find(this->group_tree,GroupID) != nullptr)
    {
        return FAILURE;
    }

    try
    {
        group new_group(GroupID, nullptr, nullptr);
        this->group_tree =  this->group_tree->insert(this->group_tree,GroupID,new_group);
    }
    catch(std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType PlayerManager::PMAddPlayer( int PlayerID, int GroupID, int Level)
{
    if(PlayerID <= 0 || GroupID <= 0 || Level < 0)
    {
        return INVALID_INPUT;
    }
    if(this->group_tree->find(this->group_tree,GroupID) == nullptr ||
       this->int_player_tree->find(this->int_player_tree,PlayerID) != nullptr)
    {
        return FAILURE;
    }
    try
    {
        std::shared_ptr<AVL_node<group,int>> player_group_node = this->group_tree->find(this->group_tree,GroupID);
        //make playerinfo(lvelandid,inttreenode =null,lelveandidtreenode=null);
        // insert playerinfo to tree in group
        //get the SP-AVL-wnode in the tree in the group
        //give it to new player
        //insert player to inttree and lelvetree
        //get the nodes in lelvel tree and idtree
        //asign the nodes into player info
        player new_player(Level,PlayerID,player_group_node.get(), nullptr);
        LevelAndId levelAndId(Level,PlayerID);
        player_group_node->getInfo().getPlayers_tree()->insert(player_group_node->getInfo().getPlayers_tree(),levelAndId,)
    }
    catch(std::exception& e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}
