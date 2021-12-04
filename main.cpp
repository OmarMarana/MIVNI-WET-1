#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "AVLnode.h"
#include <iostream>

#include "PlayerManager.h"
//#include "PlayerManagerUtilities.h"

#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>


//#include "group.h"
//#include "player.h"

// void NodePointSiblingsToNull(const std::shared_ptr<AVL_node<int,int>>& root)
// {

// }

// void printNode(const std::shared_ptr<AVL_node<int,int>>& root){
// std::cout << root->getKey() << " " ;
// }

void printNode(const std::shared_ptr<AVL_node<player,LevelAndId>>& root)
{
    std::cout<< "(" << root->getKey().getLevel() << " , "<< root->getKey().getId()<< ")" << "  " ;
}

void PrintAll(int *playerIDs, int numOfPlayers) {
    if (numOfPlayers > 0) {
        std::cout << "Rank	||	Player" << std::endl;
    }

    for (int i = 0; i < numOfPlayers; i++) {
        std::cout << i + 1 << "\t||\t" << playerIDs[i] << std::endl;
    }
    std::cout << "and there are no more players!" << std::endl;

    free (playerIDs);
}


int main() {


//    //basic LL root change
//    tree.addNode(3,3);
//    tree.addNode(2,2);
//    tree.addNode(1,1);
//    tree.printTree();
//    tree.treeClear();

//    root = root->insert(root,3,3);
//    root = root->treeBalance(root->find(root,3));
//    root = root->insert(root,2,2);
//    root = root->treeBalance(root->find(root,2));
//    root = root->insert(root,1,1);
//    root = root->treeBalance(root->find(root,1));

    //****************************************************************

//    //basic LR root change
//    tree.addNode(3,3);
//    tree.addNode(1,1);
//    tree.addNode(2,2);
//    tree.printTree();
//    tree.treeClear();

//    root = root->insert(root,3,3);
//    root = root->treeBalance(root->find(root,3));
//    root = root->insert(root,1,1);
//    root = root->treeBalance(root->find(root,1));
//    root = root->insert(root,2,2);
//    root = root->treeBalance(root->find(root,2));

    //****************************************************************
//    //basic RR root change
//    tree.addNode(1,1);
//    tree.addNode(2,2);
//    tree.addNode(3,3);
//    tree.printTree();
//    tree.treeClear();

//    root = root->insert(root,1,1);
//    root = root->treeBalance(root->find(root,1));
//    root = root->insert(root,2,2);
//    root = root->treeBalance(root->find(root,2));
//    root = root->insert(root,3,3);
//    root = root->treeBalance(root->find(root,3));


    //****************************************************************

//    //basic RL root change
//    tree.addNode(1,1);
//    tree.addNode(3,3);
//    tree.addNode(2,2);
//    tree.printTree();
//    tree.treeClear();

//    root = root->insert(root,1,1);
//    root = root->treeBalance(root->find(root,1));
//    root = root->insert(root,3,3);
//    root = root->treeBalance(root->find(root,3));
//    root = root->insert(root,2,2);
//    root = root->treeBalance(root->find(root,2));


    //****************************************************************
//    tree.addNode(6,6);
//    tree.addNode(4,4);
//    tree.addNode(8,8);
//    tree.addNode(3,3);
//    tree.addNode(5,5);
//    tree.addNode(7,7);
//    tree.addNode(1,1);
//    tree.addNode(2,2);
//    tree.printTree();
//    tree.treeClear();

//    root = root->insert(root,6,6);
//    root = root->treeBalance(root->find(root,6));
//    root = root->insert(root,4,4);
//    root = root->treeBalance(root->find(root,4));
//    root = root->insert(root,8,8);
//    root = root->treeBalance(root->find(root,8));
//    root = root->insert(root,3,3);
//    root = root->treeBalance(root->find(root,3));
//    root = root->insert(root,5,5);
//    root = root->treeBalance(root->find(root,5));
//    root = root->insert(root,7,7);
//    root = root->treeBalance(root->find(root,7));
//    root = root->insert(root,1,1);
//    root = root->treeBalance(root->find(root,1));
//    root = root->insert(root,2,2);
//    root = root->treeBalance(root->find(root,2));


    //****************************************************************

//    std::vector<int> vector;
//    for (int i=1; i<=3; i++) vector.push_back(i);
//
//    //Randomly insert and removes nodes
//    for (int k = 0; k < 10; ++k) {
//        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
//        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
//
//            root = root->insert(root,*it,*it);
//            root = root->treeBalance(root->find(root,*it));
//
//
//        }
//        root->inOrder(root,printNode);
//        std::cout << std::endl ;
//        root->preOrder(root,printNode);
//        std::cout << std::endl;
//
//        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
//        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
//
//            root = root->deleteNode(root ,*it);
//            root->inOrder(root,printNode);
//            std::cout << std::endl ;
//            root->preOrder(root,printNode);
//
//        }
//        root->postOrder(root);
//
//        root->inOrder(root,printNode);
//        std::cout << std::endl ;
//        root->preOrder(root,printNode);
//        std::cout << '\n';
//    }

    //****************************************************************
    //check that clone really creates a new tree thats not related to the tree thats being cloned

    // std::shared_ptr<AVL_node<int,int>> root;

    // root = root->insert(root,2,2);
    // root = root->treeBalance(root->find(root,2));
    // root = root->insert(root,1,1);
    // root = root->treeBalance(root->find(root,1));
    // root = root->insert(root,5,5);
    // root = root->treeBalance(root->find(root,5));
    // root = root->insert(root,6,6);
    // root = root->treeBalance(root->find(root,6));
    // root = root->insert(root,7,7);
    // root = root->treeBalance(root->find(root,7));
    // root = root->insert(root,10,10);
    // root = root->treeBalance(root->find(root,10));
    // root = root->insert(root,3,3);
    // root = root->treeBalance(root->find(root,3));

    // std::shared_ptr<AVL_node<int,int>> root2;

    // root2 = root2->clone(root,root->getFather());
    // root2 = root2->deleteNode(root2 ,6);

    // root->inOrder(root,printNode);
    // std::cout << std::endl ;
    // root->preOrder(root,printNode);

    // std::cout << std::endl ;
    // std::cout << "****************************************************************************************************" ;
    // std::cout << std::endl ;

    // root2->inOrder(root2,printNode);
    // std::cout << std::endl ;
    // root2->preOrder(root2,printNode);

    // root->postOrderAndDestroy(root);
    // root2->postOrderAndDestroy(root2);

    //****************************************************************
    //test for properly defined order on LevelAndId

//     std::shared_ptr<AVL_node<int,int>> root;
//    std::shared_ptr<AVL_node<player,LevelAndId>> tree;
//
//    tree = tree->insert(tree,LevelAndId(9,5,nullptr),player(9,5,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(9,5,nullptr)));
//    tree = tree->insert(tree,LevelAndId(8,6,nullptr),player(8,6,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(8,6,nullptr)));
//    tree = tree->insert(tree,LevelAndId(10,4,nullptr),player(10,4,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,4,nullptr)));
//    tree = tree->insert(tree,LevelAndId(10,3,nullptr),player(10,3,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,3,nullptr)));
//    tree = tree->insert(tree,LevelAndId(10,1,nullptr),player(10,1,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,1,nullptr)));

//    tree = tree->insert(tree,LevelAndId(10,5),player(10,5,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,5)));
//
//    tree = tree->insert(tree,LevelAndId(10,7),player(10,7,nullptr,nullptr));
//    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,7)));


//    tree->inOrder(tree,printNode);
//    std::cout << std::endl ;
//    tree->preOrder(tree,printNode);
//
//    tree->postOrderAndDestroy(tree);

//     write new print and start checking


    //****************************************************************
    //test PM ADDGROUP AND DEST



    PlayerManager pm1;
//    int g1ID =1;
    StatusType  res1 = pm1.PMAddGroup(1);
    res1 = pm1.PMAddGroup(4);
    res1 = pm1.PMAddGroup(7);
    res1 = pm1.PMAddGroup(2);
    res1 = pm1.PMAddGroup(10);

    if(res1 != SUCCESS)
    {
        std::cout << "PMAddGroup FAILED" << std::endl;
    }

    StatusType res2 = pm1.PMAddPlayer(1,7,5);
    res2 = pm1.PMAddPlayer(3,7,3);
    res2 = pm1.PMAddPlayer(5,7,3);

    if(res2 != SUCCESS)
    {
        std::cout << "PMAddpLAYER FAILED" << std::endl;
    }

    StatusType res3 = pm1.PMRemovePlayer(3);
    res3 = pm1.PMRemovePlayer(1);
    if(res3 != SUCCESS)
    {
        std::cout << "PMREMOVEPlayer FAILED" << std::endl;
    }

    res2 = pm1.PMAddPlayer(9,2,500);
    res2 = pm1.PMAddPlayer(4,2,501);
    res2 = pm1.PMAddPlayer(10,2,501);
    res2 = pm1.PMAddPlayer(2,2,501);
    res2 = pm1.PMAddPlayer(7,2,500);

    int  pID;
    StatusType res4 = pm1.PMGetHighestLevel(2,&pID);
    if(res4 != SUCCESS)
    {
        std::cout << "PMGetHighestLevel FAILED" << std::endl;
    }

//    res2 = pm1.PMRemovePlayer(9);
//    res2 = pm1.PMRemovePlayer(4);
//    res2 = pm1.PMRemovePlayer(10);
//    res2 = pm1.PMRemovePlayer(2);
//    res2 = pm1.PMRemovePlayer(7);
//    res2 = pm1.PMRemovePlayer(5);


    int* Players ;
    int numOfPlayers;
    StatusType res5 = pm1.PMGetAllPlayersByLevel(-1,&Players,&numOfPlayers);
    if(res5 != SUCCESS)
    {
        std::cout << "PMGetAllPlayersByLevel FAILED" << std::endl;
    }


     res4 = pm1.PMGetHighestLevel(-2,&pID);
    if(res4 != SUCCESS)
    {
        std::cout << "PMGetHighestLevel FAILED" << std::endl;
    }

    int *Player1;
    StatusType res6 = pm1.PMGetGroupsHighestLevel(2,&Player1);
    if(res6 != SUCCESS)
    {
        std::cout << "PMGetAllPlayersByLevel FAILED" << std::endl;
    }

    StatusType res7 = pm1.PMIncreaseLevel(7,2);
    if(res7 != SUCCESS)
    {
        std::cout << "PMGetAllPlayersByLevel FAILED" << std::endl;
    }



    PrintAll(Player1, 2);

    std::cout << "id is " << pID << std::endl;
//    pm1.Getgroup_tree()->inOrder(pm1.Getgroup_tree(),printNode);
//    std::cout << std::endl ;
//    pm1.Getgroup_tree()->preOrder(pm1.Getgroup_tree(),printNode);





    //****************************************************************

    /**
        check if the conversion between <AVL_node<group,int>>* and void* is possible
        check if its possible to acess field thru void*
        test showed that player can still point to its location in its group
        without having group.h in player.h, and thats possible by using void* conversions
         from and to (AVL_node<T,S>*) AND by using SP.get() which returns the raw (dumb) pointer
        that is saved in SP
     */

    /**
     * check if its possible to move LevelAndId to a seperate file
     *
     */





//    int group1ID = 3;
//    group group1(group1ID, nullptr, nullptr);
//    int playerId = 5;
//    player player1(8,playerId, nullptr, nullptr);
//    std::shared_ptr<AVL_node<player,int>> player_node = (std::make_shared<AVL_node<player,int>>(playerId,player1));
//
//
//
//    std::shared_ptr<AVL_node<group,int>> group_node = (std::make_shared<AVL_node<group,int>>(group1ID,group1)); // why cpy constructor if there is reference in avl node
//
////    std::shared_ptr<AVL_node<int,int>> group_node = (std::make_shared<AVL_node<int,int>>(1,1));
////    player player1(3,1, nullptr, nullptr);
//    player1.setPlayerGnode(group_node.get());
//    void * void_group_node = group_node.get();
//
//    AVL_node<group,int> *void_group_node_conv = (AVL_node<group,int>*) (void_group_node);
////    AVL_node<int,int> *void_group_node_conv = (AVL_node<int,int>*) (void_group_node);
////
//    std::cout << "print using the SP"<< std::endl ;
//    std::cout << group_node->getKey() << " " ;
//    std::cout << std::endl ;
//
//    std::cout << "print using the void* converted to true type"<< std::endl ;
//    std::cout << void_group_node_conv->getKey() << " " ;
//
//    std::cout << std::endl ;
//
//    std::cout << "print using player field"<< std::endl ;
//    std::cout << ((AVL_node<int,int>*)(player1.getGroup_node()))->getKey() << " " ;


//     std::shared_ptr<AVL_node<T,S>> root(new AVL_node(key,info)); // make ptr with new if there is problems



    //****************************************************************

//    root = root->insert(root,8,8);
//    root = root->treeBalance(root->find(root,8));
//    root = root->insert(root,9,9);
//    root = root->treeBalance(root->find(root,9));
//    root = root->insert(root,15,15);
//    root = root->treeBalance(root->find(root,15));
//
//    root = root->insert(root,33,33);
//    root = root->treeBalance(root->find(root,33));
//    root = root->insert(root,18,18);
//    root = root->treeBalance(root->find(root,18));
//    root = root->insert(root,17,17);
//    root = root->treeBalance(root->find(root,17));
//    root = root->insert(root,41,41);
//    root = root->treeBalance(root->find(root,41));
//    root = root->insert(root,88,88);
//    root = root->treeBalance(root->find(root,88));
//    root = root->insert(root,52,52);
//    root = root->treeBalance(root->find(root,52));
//    root = root->insert(root,51,51);
//    root = root->treeBalance(root->find(root,51));
//    root = root->insert(root,66,66);
//    root = root->treeBalance(root->find(root,66));
//    root = root->insert(root,31,31);
//    root = root->treeBalance(root->find(root,31));
//    root = root->insert(root,4,4);
//    root = root->treeBalance(root->find(root,4));
//
//
//    // std::shared_ptr<AVL_node<int,int>> avl_node = root->find(root,17);
//    // avl_node = avl_node->getFather();
//    root = root->deleteNode(root ,17);
//    // root = root->treeBalance(avl_node);
//
//
//    // avl_node = root->find(root,33);
//    // avl_node = avl_node->getFather();
//    root = root->deleteNode(root ,33);
//    // root = root->treeBalance(avl_node);
//
//
//    // avl_node = root->find(root,6);
//    // avl_node = avl_node->getFather();
//    root = root->deleteNode(root ,18);
//    // root = root->treeBalance(avl_node);
//
//    root = root->deleteNode(root ,6);
//
//    root = root->deleteNode(root ,15);
//
//    root = root->deleteNode(root ,1);
//
//    root = root->deleteNode(root ,9);
//
//
//    root = root->deleteNode(root ,31);
//    root = root->deleteNode(root ,4);
//    root = root->deleteNode(root ,52);
//    root = root->deleteNode(root ,66);
//    root = root->deleteNode(root ,88);
//    root = root->deleteNode(root ,66);
//    root = root->deleteNode(root ,7);
//    root = root->deleteNode(root ,3);
//    root = root->deleteNode(root ,5);
//    root = root->deleteNode(root ,2);
//    root = root->deleteNode(root ,51);
//    root = root->deleteNode(root ,10);

//    root->inOrder(root,printNode);
//    std::cout << std::endl ;
//    root->preOrder(root,printNode);
//
//
//    //31,4,52,66,88,66,7,3,5,2,51,10
//    root->postOrder(root);

    return 0;

}