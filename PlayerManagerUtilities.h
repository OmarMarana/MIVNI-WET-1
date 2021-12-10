//
// Created by omarm on 02/12/2021.
//

#ifndef MIVNI_PLAYERMANAGERUTILITIES_H
#define MIVNI_PLAYERMANAGERUTILITIES_H

#include "AVLnode.h"

//******************************************************
//******************************************************
//******************************************************
//LevelAndId
//******************************************************
//******************************************************
//******************************************************

//class LevelAndId;
class player;

class LevelAndId
{
private:
    int Level;
    int Id;
    std::shared_ptr<AVL_node<player,int>> player_node;
    friend class player;

public:
    LevelAndId(int Level, int Id, std::shared_ptr<AVL_node<player,int>> player_node) : Level(Level) , Id(Id), player_node(player_node){};
    LevelAndId() : Level(0) , Id(0), player_node(nullptr){};
    ~LevelAndId();
    LevelAndId(const LevelAndId& other) ;
    LevelAndId& operator=(const LevelAndId& other);

    int getId() const;
    int getLevel() const;
    std::shared_ptr<AVL_node<player,int>> getPlayer_node() const;


    bool operator==(const LevelAndId& other) const ;     // check how to declare as friend
    bool operator<(const LevelAndId& other) const ;
    bool operator>(const LevelAndId& other) const ;

    void setPlayer_node(std::shared_ptr<AVL_node<player,int>> new_player_node);

};

//******************************************************
//******************************************************
//******************************************************
//LevelAndId
//******************************************************
//******************************************************
//******************************************************

class group;
class player
{

private:
    LevelAndId level_and_id;
    std::shared_ptr<AVL_node<group,int>> group_node;

public:


    player() : level_and_id(-1,-1,nullptr) ,group_node(nullptr) {}; //constructor
    player(int level,int playerID, std::shared_ptr<AVL_node<group,int>> group_node) :
            level_and_id(level,playerID,nullptr), group_node(group_node) {}; //constructor
    ~player(); //destructor
    player(const player&) = default; //copy constructor
    player& operator=(const player& other); // avl_node1= avl_node2
    LevelAndId getplayerLevelAndId();
    std::shared_ptr<AVL_node<group,int>> getGroup_node() const ;// maybe &

    void setPlayerGnode(std::shared_ptr<AVL_node<group,int>> gnode);
    void setPlayerLevel(int new_level);


};

//******************************************************
//******************************************************
//******************************************************
//group
//******************************************************
//******************************************************
//******************************************************


class  group
{
private:
    int groupID;
    int num_of_players;
    std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> group_players_tree;
    std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> max_level_player;

public:

    group() : groupID(-1) , num_of_players(0), group_players_tree(nullptr), max_level_player(nullptr) {}; //constructor
    group(int groupID,int num_of_players ,std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> group_players_tree,
          std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> max_level_player ): groupID(groupID) ,num_of_players(num_of_players)
            , group_players_tree(group_players_tree), max_level_player(max_level_player) {}; //constructor

    ~group(); //destructor
    group(const group&); //copy constructor
    group& operator=(const group& other); // group1 = group2

    int getGroupID() const;
    int get_num_of_players() const;
    std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> getPlayers_tree() const;
    std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> getMax_level_player() const;

    void setPlayers_tree(std::shared_ptr<AVL_node<LevelAndId,LevelAndId>>new_group_players_tree ) ;
    void set_max_level_player(std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> new_max_level_player) ;
    void setnNum_of_players(int delta);
    void updatePlayerTreeLI(std::shared_ptr<AVL_node<LevelAndId,LevelAndId>> root,
                                   std::shared_ptr<AVL_node<player,int>> new_player_node );
};



#endif //MIVNI_PLAYERMANAGERUTILITIES_H
