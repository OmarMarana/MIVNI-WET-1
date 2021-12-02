#ifndef PLAYER_H
#define PLAYER_H

#include "AVLnode.h"
#include <iostream>
//#include "group.h"

//class group;


//****************************************************************
//****************************************************************
//****************************************************************
//****************************************************************
//****************************************************************
//****************************************************************
//is it okay that class LevelAndId is implemented in player.h file?
//maybe put the implementaion of LevelandID in THE PRIVATE PART of player
//****************************************************************
//****************************************************************
//****************************************************************
//****************************************************************
//****************************************************************
//****************************************************************







// class LevelAndId;

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

//        int getId();
        int getId()
        {
            return Id;
        }

//        int getLevel();
        int getLevel()
        {
            return Level;
        }

        //        bool operator==(const LevelAndId& other) ;     // check how to declare as friend
        bool operator==(const LevelAndId& other)
        {
            return ( (this->Id == other.Id) && (this->Level == other.Level) );
        }
//        bool operator<(const LevelAndId& other);
        bool operator<(const LevelAndId& other)
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

//        bool operator>(const LevelAndId& other);
        bool operator>(const LevelAndId& other)
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
        
    
};


class player 
{

    private:
    LevelAndId level_and_id;
//    std::shared_ptr<AVL_node<group,int>> group_node;
    void *group_node;
    std::shared_ptr<AVL_node<player,int>> player_node; 


    public:

//    player() : level_and_id(-1,-1) ,group_node(nullptr),  player_node(nullptr) {}; //constructor
//    player(int level,int playerID, std::shared_ptr<AVL_node<group,int>> group_node, std::shared_ptr<AVL_node<player,int>> player_node) :
//    level_and_id(level,playerID), group_node(group_node), player_node(player_node) {}; //constructor
//    ~player(); //destructor
//    player(const player&) = default; //copy constructor
//    player& operator=(const player& other); // avl_node1= avl_node2
//    LevelAndId getplayerLevelAndId();
//    std::shared_ptr<AVL_node<group,int>> getGroup_node(); // maybe &
//    std::shared_ptr<AVL_node<player,int>> getPlayer_node();





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

    

    // friend bool operator==(const player& player1, const player& player2);
    // friend bool operator>(const player& player1, const player& player2);
    // friend bool operator<(const player& player1, const player& player2);


};




//bool LevelAndId::operator==(const LevelAndId& other)
//{
//    return ( (this->Id == other.Id) && (this->Level == other.Level) );
//}


//bool LevelAndId::operator<(const LevelAndId& other)
//{
//    //LI1 < LI2?
//    //this < other? true if this.id > other.id
//    if(this->Level == other.Level)
//    {
//        if(this->Id > other.Id)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    //if levels arent equal then ids are irrelevant
//    return this->Level < other.Level;
//}

//bool LevelAndId::operator>(const LevelAndId& other)
//{
//
//    /*
//    if its not less than and not equal then it must be larger than
//    assuming the < and == are defined properly;
//    */
//    if( (*this < other ) == false || (*this == other ) == false)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

//int LevelAndId::getLevel()
//{
//    return Level;
//}

//int LevelAndId::getId()
//{
//    return Id;
//}



#endif 