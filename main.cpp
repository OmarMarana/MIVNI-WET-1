#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLnode.h"
#include <iostream>

void printNode(const std::shared_ptr<AVL_node<int,int>>& root){
   std::cout << root->getKey() << " " ;
}

int main() {
    std::shared_ptr<AVL_node<int,int>> root;
    root = root->insert(root,2,2);
    root = root->treeBalance(root->find(2));
    root = root->insert(root,1,1);
    root = root->treeBalance(root->find(1));
    root = root->insert(root,5,5);
    root = root->treeBalance(root->find(5));
    root = root->insert(root,6,6);
    root = root->treeBalance(root->find(6));
    root = root->insert(root,7,7);
    root = root->treeBalance(root->find(7));
    root = root->insert(root,10,10);
    root = root->treeBalance(root->find(10));
    root = root->insert(root,3,3);
    root = root->treeBalance(root->find(3));
    root = root->insert(root,8,8);
    root = root->treeBalance(root->find(8));
    root = root->insert(root,9,9);
    root = root->treeBalance(root->find(9));
    root = root->insert(root,15,15);
    root = root->treeBalance(root->find(15));


    root->inOrder(root,printNode);
    std::cout << std::endl ;
    root->preOrder(root,printNode);



    return 0;

}