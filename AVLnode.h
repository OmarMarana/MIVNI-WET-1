#ifndef AVL_NODE_H
#define AVL_NODE_H
#include <iostream>


template <class T, class S>
class AVL_node
{
    private:
        
        int BF;
        T *info;
        S key;
        int height;
        class AVL_node* father;
        class AVL_node* left_son;
        class AVL_node* right_son;
    
    public:
    AVL_node() : BF(0) , info(nullptr), key(), height(0), father(nullptr),left_son(nullptr), right_son(nullptr) ; //constructor
    AVL_node(S key, T *info) : BF(0) , info(info), key(key), height(0), father(nullptr),left_son(nullptr), right_son(nullptr) ; //constructor
    ~AVL_node(); //destructor
    AVL_node(const AVL_node&); //copy constructor
    AVL_node& operator=(const AVL_node& other); // avl_node1= avl_node2

    AVL_node& insert(S key,T info);
    AVL_node& delete( S key);
    AVL_node& find(S key);
    AVL_node& leftRotation(AVL_node *root,);
    AVL_node& rightrotation(AVL_node *root);
    void inOrder(AVL_node *root);
    AVL_node& treeBalance(AVL_node *root)

    

};

#endif
