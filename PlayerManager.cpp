//
// Created by omarm on 02/12/2021.
//


#include "PlayerManager.h"
#include "AVLnode.h"
#include <execution>


PlayerManager::~PlayerManager()
{
    this->level_and_id_player_tree->postOrderAndDestroy(this->level_and_id_player_tree);
    this->int_player_tree->postOrderAndDestroy(this->int_player_tree);
    this->group_tree->postOrderAndDestroy(this->group_tree);
    this->max_level_group_tree->postOrderAndDestroy(this->max_level_group_tree);
}



StatusType PlayerManager::PMAddGroup( int GroupID)
{
    if(GroupID <= 0) return INVALID_INPUT;
    if(this->group_tree->find(this->group_tree,GroupID) != nullptr)
    {
        return FAILURE;
    }

    try
    {
        group new_group(GroupID, 0,nullptr, nullptr);
        this->group_tree =  this->group_tree->insert(this->group_tree,GroupID,new_group);
        this->group_tree = this->group_tree->treeBalance(this->group_tree->find(this->group_tree
                ,GroupID));

    }
    catch(std::exception& e)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

//in seg fault situations check here, bcus here we assume that trees arent null, they are all
// SP's that thier dumb ptr is null so in all cases its okay to derefrence thier pointers
StatusType PlayerManager::PMAddPlayer( int PlayerID, int GroupID, int Level)
{
    if(PlayerID <= 0 || GroupID <= 0 || Level < 0)
    {
        return INVALID_INPUT;
    }

    if(this->group_tree == nullptr || this->group_tree->find(this->group_tree,GroupID) == nullptr)
    {
        return FAILURE;
    }

    if(this->int_player_tree->find(this->int_player_tree,PlayerID) != nullptr)
    {
        return FAILURE;
    }

    try
    {

        num_of_players++;
        LevelAndId levelAndId(Level,PlayerID, nullptr);

        this->level_and_id_player_tree =this->level_and_id_player_tree->insert(this->level_and_id_player_tree ,levelAndId,levelAndId);
        this->level_and_id_player_tree = this->level_and_id_player_tree->treeBalance(this->level_and_id_player_tree->find
                (this->level_and_id_player_tree,levelAndId ));

//        if(this->max_level_group_tree == nullptr)  //
//        {
//            this->max_level_group_tree =this->max_level_group_tree->insert(this->max_level_group_tree,int,levelAndId);
//        }



        std::shared_ptr<AVL_node<LevelAndId,int>> max_level_node = this->max_level_group_tree->find(this->max_level_group_tree,GroupID);
        if(max_level_node == nullptr)
        {
            this->max_level_group_tree =this->max_level_group_tree->insert(this->max_level_group_tree,GroupID,levelAndId);
            this->max_level_group_tree =this->max_level_group_tree->treeBalance(this->max_level_group_tree->find(this->max_level_group_tree ,
                                                                                                                 GroupID));
        }
        else
        {
            if(levelAndId > max_level_node->getInfo())
            {
                max_level_node->setInfo(levelAndId);
            }
        }


        if(levelAndId >max_level_min_ID)
        {
            this->max_level_min_ID = levelAndId;
        }

        std::shared_ptr<AVL_node<group,int>> group_node = this->group_tree->find(this->group_tree,GroupID);
//        group_node->getInfo().getPlayers_tree()->insert(group_node->getInfo().getPlayers_tree(),levelAndId,levelAndId);
        group_node->getInfo().setPlayers_tree(group_node->getInfo().getPlayers_tree()->insert(group_node->getInfo().getPlayers_tree(
        ),levelAndId,levelAndId));
        group_node->getInfo().setPlayers_tree(group_node->getInfo().getPlayers_tree()->treeBalance
        (group_node->getInfo().getPlayers_tree()->find(group_node->getInfo().getPlayers_tree(),levelAndId)));


        std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> new_max_level_player = group_node->getInfo().getPlayers_tree()->find(
                group_node->getInfo().getPlayers_tree(),levelAndId);
        if( group_node->getInfo().getMax_level_player() == nullptr || levelAndId > group_node->getInfo().getMax_level_player()->getInfo())
        {
            group_node->getInfo().set_max_level_player(new_max_level_player);
        }


        group_node->getInfo().setnNum_of_players();


        player new_player(Level, PlayerID, group_node,group_node->getInfo().getPlayers_tree()->find(
                group_node->getInfo().getPlayers_tree(),levelAndId));

        this->int_player_tree = this->int_player_tree->insert(this->int_player_tree,PlayerID,new_player);
        this->int_player_tree = this->int_player_tree->treeBalance(this->int_player_tree->find(this->int_player_tree,PlayerID));

        std::shared_ptr<AVL_node<player,int>> player_node = this->int_player_tree->find(this->int_player_tree,PlayerID );

        std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> level_and_id_node = group_node->getInfo().getPlayers_tree()->
                find(group_node->getInfo().getPlayers_tree(),levelAndId) ;

        level_and_id_node->getInfo().setPlayer_node(player_node);









    }
    catch(std::exception& e) {
        return ALLOCATION_ERROR;
    }


    return SUCCESS;
}

std::shared_ptr<AVL_node<group,int>>  PlayerManager::Getgroup_tree()const
{
    return group_tree;
}
