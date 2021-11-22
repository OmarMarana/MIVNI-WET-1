#ifndef AVL_NODE_H
#define AVL_NODE_H
#include <iostream>


template <class T, class S>
class AVL_node
{
    private:
        
        int BF;
        T info; 
        S key;   
        int height;
        class AVL_node* father; // maybe delete class
        class AVL_node* left_son; 
        class AVL_node* right_son;  
    
    protected:
        static int getBF();
        T getInfo();
        S getKey();
        int getHeight();
        AVL_node* getFather(); // maybe & 
        AVL_node* getLeft_son();
        AVL_node* getRight_son();


    public:
        AVL_node() : BF(0) , info(), key(), height(0), father(nullptr),left_son(nullptr), right_son(nullptr); //constructor
        AVL_node(S key, T info) : BF(0) , info(info), key(key), height(0), father(nullptr),left_son(nullptr), right_son(nullptr) ; //constructor
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

template <class T, class S>
int AVL_node<T,S>::getBF()
{
    return BF;
}

template <class T, class S>
T AVL_node<T,S>::getInfo()
{
    return info;
}

template <class T, class S>
S AVL_node<T,S>::getKey()
{
    return key;
}

template <class T, class S>
int AVL_node<T,S>::getHeight()
{
    return height;
}



template <class T, class S>
AVL_node<T,S>* AVL_node<T,S>::getFather()
{
    return father;
}

template <class T, class S>
AVL_node<T,S>* AVL_node<T,S>::getLeft_son()
{
    return left_son;
}

template <class T, class S>
AVL_node<T,S>* AVL_node<T,S>::getRight_son()
{
    return right_son;
}


template<class T,class S>
AVL_node<T,S>::AVL_node(const AVL_node<T,S>& other) : BF(other.BF) ,info(other.info), key(other.key), height(other.height),
father(other.father), left_son(other.left_son), right_son(other.right_son) {}


















#endif
