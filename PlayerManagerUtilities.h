//
// Created by omarm on 02/12/2021.
//

#ifndef MIVNI_PLAYERMANAGERUTILITIES_H
#define MIVNI_PLAYERMANAGERUTILITIES_H


//******************************************************
//******************************************************
//******************************************************
//player
//******************************************************
//******************************************************
//******************************************************



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
    std::shared_ptr<AVL_node<player,LevelAndId>> getPlayers_tree(); // maybe
    std::shared_ptr<AVL_node<player,LevelAndId>> getMax_level_player();


};

//******************************************************
//******************************************************
//******************************************************
//class LevelAndId
//******************************************************
//******************************************************
//******************************************************


class LevelAndId
{
private:
    int Level;
    int Id;
    friend class player;

public:
    LevelAndId(int Level, int Id) : Level(Level) , Id(Id){};
    LevelAndId() =default;
    ~LevelAndId() =default;
    LevelAndId(const LevelAndId&) =default;
    LevelAndId& operator=(const LevelAndId& other) = default;

    int getId() const;
    int getLevel() const;


    bool operator==(const LevelAndId& other) const ;     // check how to declare as friend
    bool operator<(const LevelAndId& other) const ;
    bool operator>(const LevelAndId& other) const ;


};


#endif //MIVNI_PLAYERMANAGERUTILITIES_H
