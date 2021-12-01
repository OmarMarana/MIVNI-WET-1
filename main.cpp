#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLnode.h"
#include <iostream>

#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>


#include "group.h"
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

    // std::shared_ptr<AVL_node<int,int>> root;
    std::shared_ptr<AVL_node<player,LevelAndId>> tree;

    tree = tree->insert(tree,LevelAndId(9,5),player(9,5,nullptr,nullptr));
    tree = tree->treeBalance(tree->find(tree,LevelAndId(9,5)));
    tree = tree->insert(tree,LevelAndId(8,6),player(8,6,nullptr,nullptr));
    tree = tree->treeBalance(tree->find(tree,LevelAndId(8,6)));
    tree = tree->insert(tree,LevelAndId(10,4),player(10,4,nullptr,nullptr));
    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,4)));
    tree = tree->insert(tree,LevelAndId(10,3),player(10,3,nullptr,nullptr));
    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,3)));
    tree = tree->insert(tree,LevelAndId(10,1),player(10,1,nullptr,nullptr));
    tree = tree->treeBalance(tree->find(tree,LevelAndId(10,1)));

    
    tree->inOrder(tree,printNode);
    std::cout << std::endl ;
    tree->preOrder(tree,printNode);
    
    tree->postOrderAndDestroy(tree);

    // write new print and start checking


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