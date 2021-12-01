#ifndef GROUP_H
#define GROUP_H
#include "AVLnode.h"
#include "player.h"
#include <stdbool.h>

#include <iostream>


class  group
{


    private:
        int groupID;
        std::shared_ptr<AVL_node<player,int>> group_players_tree;
        std::shared_ptr<AVL_node<player,int>> max_level_player;


    


    public:

        group() : groupID(-1) , group_players_tree(nullptr), max_level_player(nullptr) {}; //constructor
        group(int groupID, std::shared_ptr<AVL_node<player,int>> group_players_tree, std::shared_ptr<AVL_node<player,int>> max_level_player )
        : groupID(groupID) , group_players_tree(group_players_tree), max_level_player(max_level_player) {}; //constructor
        
        ~group(); //destructor
        group(const group&); //copy constructor
        group& operator=(const group& other); // avl_node1= avl_node2
    
        friend bool operator==(const group& group1, const group& group2);
        friend bool operator<(const group& group1, const group& group2);
        friend bool operator>(const group& group1, const group& group2);

        int getGroupID();
        std::shared_ptr<AVL_node<player,int>> getPlayers_tree(); // maybe &
        std::shared_ptr<AVL_node<player,int>> getMax_level_player();






};

// group::
group::~group()
{
    group_players_tree->postOrderAndDestory(group_players_tree);
    max_level_player = nullptr; // check that it dosnt point to family

}


group::group(const group& other) : groupID(other.groupID)  // copy constructor
{
    // AVL_node<player, int> tree_copy = *(other.group_players_tree);
    // std::shared_ptr<AVL_node<player,int>> 
    // std::shared_ptr<AVL_node<player,int>> tmp = (std::make_shared<AVL_node>(tree_copy));

    other->group_players_tree = clone(this->getPlayers_tree)
    /*
        node  *clone( root ) :  
       if (root == NULL ) : return root; 
     
       //create new node and make it a copy of node pointed by root 
       node *temp = (node *)malloc(sizeof(node)) ; 
       temp->data = root-> data;    //copying data 
       temp->left = clone(root -> left);    //cloning left child 
       temp->right = clone(root -> right);  //cloning right child 
       return temp; 
    */




} 





#endif 