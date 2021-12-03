//
// Created by omarm on 02/12/2021.
//


#include "PlayerManager.h"
#include "AVLnode.h"
#include <exception>
//#include <execution>

void fun(std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> sp)
{
    std::cout << "in fun(): sp.use_count() == " << sp.use_count()
              << " (object @ " << sp << ")\n";
}


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

        max_level_node = nullptr;


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

        new_max_level_player = nullptr;

        group_node->getInfo().setnNum_of_players(1);


        player new_player(Level, PlayerID, group_node);

        this->int_player_tree = this->int_player_tree->insert(this->int_player_tree,PlayerID,new_player);
        this->int_player_tree = this->int_player_tree->treeBalance(this->int_player_tree->find(this->int_player_tree,PlayerID));

        std::shared_ptr<AVL_node<player,int>> player_node = this->int_player_tree->find(this->int_player_tree,PlayerID );

        std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> level_and_id_node = group_node->getInfo().getPlayers_tree()->
                find(group_node->getInfo().getPlayers_tree(),levelAndId) ;

        group_node = nullptr;
        level_and_id_node->getInfo().setPlayer_node(player_node);

        level_and_id_node= nullptr;
        player_node = nullptr;

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


StatusType PlayerManager::PMRemovePlayer( int PlayerID)
{
    if(PlayerID <= 0)
    {
        return INVALID_INPUT;
    }


    if(this->int_player_tree->find(this->int_player_tree,PlayerID) == nullptr)
    {
        return FAILURE;
    }

    try
    {
        this->num_of_players--;
        std::shared_ptr<AVL_node<player,int>> player_node = this->int_player_tree->find(this->int_player_tree,PlayerID);
//        group player_node->getInfo().getGroup_node()->getInfo() = player_node->getInfo().getGroup_node()->getInfo();

        // gr1 = g2;
        LevelAndId player_to_remove_LI = player_node->getInfo().getplayerLevelAndId();

        this->level_and_id_player_tree = this->level_and_id_player_tree->
                deleteNode(this->level_and_id_player_tree,player_to_remove_LI);

        std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> LI_node_in_group_subtree =
                player_node->getInfo().getGroup_node()->getInfo().getPlayers_tree()->find(
                player_node->getInfo().getGroup_node()->getInfo().getPlayers_tree(),player_to_remove_LI);

        LI_node_in_group_subtree->getInfo().setPlayer_node(nullptr);


//        fun(LI_node_in_group_subtree);

//        std::cout << "************" <<std::endl;
        LI_node_in_group_subtree = nullptr;

//        fun(LI_node_in_group_subtree);
        player_node->getInfo().getGroup_node()->getInfo().setPlayers_tree
        (player_node->getInfo().getGroup_node()->getInfo().getPlayers_tree()->deleteNode(
                player_node->getInfo().getGroup_node()->getInfo().getPlayers_tree(),player_to_remove_LI
                ));


        player_node->getInfo().getGroup_node()->getInfo().setnNum_of_players(-1); //maybe def

        if(player_node->getInfo().getGroup_node()->getInfo().getMax_level_player()->getKey() == player_to_remove_LI)
        {
            std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> new_max_player_in_group = player_node->getInfo().getGroup_node()->getInfo().getPlayers_tree()->getNodeWithBiggestKey(player_node->getInfo().getGroup_node()->getInfo().getPlayers_tree());
            player_node->getInfo().getGroup_node()->getInfo().set_max_level_player(new_max_player_in_group); // write this func
            this->max_level_group_tree->find(this->max_level_group_tree,player_node->getInfo().getGroup_node()->getInfo().getGroupID())->setInfo(new_max_player_in_group->getKey()) ;// implement
            //changed avlnode setinfo from referencce arg to copy constructor arg, check if this change influences the other functions we wrote ctrl+F setinfo
            new_max_player_in_group = nullptr;
        }

        player_node->getInfo().setPlayerGnode(nullptr);
        this->int_player_tree =this->int_player_tree->deleteNode(this->int_player_tree,PlayerID);

        player_node = nullptr;

        if(this->max_level_min_ID == player_to_remove_LI)
        {
            this->max_level_min_ID = this->level_and_id_player_tree->getNodeWithBiggestKey(this->level_and_id_player_tree)->getInfo();
        }


    }
    catch(std::exception& e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;

}

StatusType PlayerManager::PMGetHighestLevel( int GroupID, int *PlayerID)
{
    if(PlayerID == nullptr || GroupID==0)
    {
        return  INVALID_INPUT;
    }

    if(GroupID > 0 && this->group_tree->find(this->group_tree, GroupID) == nullptr)
    {
        return FAILURE;
    }



    try
    {


        if(GroupID < 0)
        {
            if(this->num_of_players == 0)
            {
                *PlayerID = -1;
                return SUCCESS;
            }

            *PlayerID = this->max_level_min_ID.getId();
        }
        else
        {

            std::shared_ptr<AVL_node<group,int>> group_node = this->group_tree->find(this->group_tree,GroupID);
            if(group_node->getInfo().get_num_of_players() == 0)
            {
                *PlayerID = -1;
                return SUCCESS;
            }

            *PlayerID = group_node->getInfo().getMax_level_player()->getKey().getId();

            group_node = nullptr;
        }



    }
    catch(std::exception& e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;


}


