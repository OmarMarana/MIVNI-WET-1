#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLnode.h"
#include <iostream>

// void NodePointSiblingsToNull(const std::shared_ptr<AVL_node<int,int>>& root)
// {

// }

void printNode(const std::shared_ptr<AVL_node<int,int>>& root){
std::cout << root->getKey() << " " ;
}

int main() {
    std::shared_ptr<AVL_node<int,int>> root;
    root = root->insert(root,2,2);
    root = root->treeBalance(root->find(root,2));
    root = root->insert(root,1,1);
    root = root->treeBalance(root->find(root,1));
    root = root->insert(root,5,5);
    root = root->treeBalance(root->find(root,5));
    root = root->insert(root,6,6);
    root = root->treeBalance(root->find(root,6));
    root = root->insert(root,7,7);
    root = root->treeBalance(root->find(root,7));
    root = root->insert(root,10,10);
    root = root->treeBalance(root->find(root,10));
    root = root->insert(root,3,3);
    root = root->treeBalance(root->find(root,3));
    root = root->insert(root,8,8);
    root = root->treeBalance(root->find(root,8));
    root = root->insert(root,9,9);
    root = root->treeBalance(root->find(root,9));
    root = root->insert(root,15,15);
    root = root->treeBalance(root->find(root,15));

    root = root->insert(root,33,33);
    root = root->treeBalance(root->find(root,33));
    root = root->insert(root,18,18);
    root = root->treeBalance(root->find(root,18));
    root = root->insert(root,17,17);
    root = root->treeBalance(root->find(root,17));
    root = root->insert(root,41,41);
    root = root->treeBalance(root->find(root,41));
    root = root->insert(root,88,88);
    root = root->treeBalance(root->find(root,88));
    root = root->insert(root,52,52);
    root = root->treeBalance(root->find(root,52));
    root = root->insert(root,51,51);
    root = root->treeBalance(root->find(root,51));
    root = root->insert(root,66,66);
    root = root->treeBalance(root->find(root,66));
    root = root->insert(root,31,31);
    root = root->treeBalance(root->find(root,31));
    root = root->insert(root,4,4);
    root = root->treeBalance(root->find(root,4));


    // std::shared_ptr<AVL_node<int,int>> avl_node = root->find(root,17);
    // avl_node = avl_node->getFather();
    root = root->deleteNode(root ,17);
    // root = root->treeBalance(avl_node);


    // avl_node = root->find(root,33);
    // avl_node = avl_node->getFather();
    root = root->deleteNode(root ,33);
    // root = root->treeBalance(avl_node);


    // avl_node = root->find(root,6);
    // avl_node = avl_node->getFather();
    root = root->deleteNode(root ,18);
    // root = root->treeBalance(avl_node);

    root = root->deleteNode(root ,6);

    root = root->deleteNode(root ,15);

    root = root->deleteNode(root ,1);

    root = root->deleteNode(root ,9);
    

    root = root->deleteNode(root ,31);
    root = root->deleteNode(root ,4);
    root = root->deleteNode(root ,52);
    root = root->deleteNode(root ,66);
    root = root->deleteNode(root ,88);
    root = root->deleteNode(root ,66);
    root = root->deleteNode(root ,7);
    root = root->deleteNode(root ,3);
    root = root->deleteNode(root ,5);
    root = root->deleteNode(root ,2);
    root = root->deleteNode(root ,51);
    root = root->deleteNode(root ,10);
    
    root->inOrder(root,printNode);
    std::cout << std::endl ;
    root->preOrder(root,printNode);
    

    //31,4,52,66,88,66,7,3,5,2,51,10
    root->postOrder(root);

    return 0;

}