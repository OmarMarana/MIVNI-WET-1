#ifndef PLAYER_H
#define PLAYER_H

#include "AVLnode.h"
#include <iostream>
#include "group.h"


class player 
{
    public:
        class LevelAndId;
    
    private:
    class LevelAndId a;
    std::shared_ptr<AVL_node<group,int>> group_node; 
    std::shared_ptr<AVL_node<player,int>> player_node; 

    

    protected:
    int getplayerID();
    int getlevel();
    AVL_node<group,int>* group_node(); // maybe & 
    AVL_node<player,int>* player_node();
    

    

    public:

    player() : playerID(-1), level(-1),group_node(nullptr),  player_node(nullptr) {}; //constructor
    player(int playerID,int level, std::shared_ptr<AVL_node<group,int>> group_node, std::shared_ptr<AVL_node<player,int>> player_node) :
    playerID(playerID), level(level), group_node(group_node), player_node(player_node) {}; //constructor
    ~player(); //destructor
    player(const player&); //copy constructor
    player& operator=(const player& other); // avl_node1= avl_node2

    // friend bool operator==(const player& player1, const player& player2);
    // friend bool operator>(const player& player1, const player& player2);
    // friend bool operator<(const player& player1, const player& player2);


};

class player::LevelAndId
{   
    private:
        int Level;
        int Id;
        friend class player;

    public:
        LevelAndId() =default;
        ~LevelAndId() =default;
        LevelAndId(const LevelAndId&) =default;
        LevelAndId& operator=(const LevelAndId& other) = default;


        bool operator==(const LevelAndId& other) ;     // check how to declare as friend
        bool operator<(const LevelAndId& other);
        bool operator>(const LevelAndId& other);
        
    
};



bool player::LevelAndId::operator==(const LevelAndId& other)
{
    return (this->Id == other.Level) && (this->Level == other.Level);
}


bool player::LevelAndId::operator<(const LevelAndId& other)
{
    if(this->Id < other.Id)
    {
        return this->Level >= other.Level;
    }
    return this->Level < other.Level;
}


#endif 