#ifndef AVL_NODE_H
#define AVL_NODE_H
#include <iostream>
#include <memory>
#include <cmath>


#define INVALID_BF 2

template <class T, class S>
class AVL_node
{
private:

    int BF;
    T info;
    S key;
    int height;
    std::shared_ptr<AVL_node<T,S>> father; // maybe delete class
    std::shared_ptr<AVL_node<T,S>> left_son;
    std::shared_ptr<AVL_node<T,S>> right_son;

protected:
    int getBF();

//    S getKey();
    int getHeight();
//    std::shared_ptr<AVL_node<T,S>> getFather(); // maybe &
    std::shared_ptr<AVL_node<T,S>> getLeft_son();
    std::shared_ptr<AVL_node<T,S>> getRight_son();
    int max(int h1, int h2);
    std::shared_ptr<AVL_node<T,S>> getNextInOrderVal();
    void SwapInfoAndKey(std::shared_ptr<AVL_node<T,S>> avl_node);





public:
    AVL_node() : BF(0) , info(), key(), height(0), father(nullptr),left_son(nullptr), right_son(nullptr){}; //constructor
    AVL_node(S& key, T& info) : BF(0) , info(info), key(key), height(0), father(nullptr),left_son(nullptr), right_son(nullptr){} ; //constructor
    ~AVL_node() = default; //destructor
    AVL_node(const AVL_node&); //copy constructor
    AVL_node& operator=(const AVL_node& other); // avl_node1= avl_node2

    std::shared_ptr<AVL_node<T,S>> insert(std::shared_ptr<AVL_node<T,S>> root,S key,T info); // change other to sharedptr
    std::shared_ptr<AVL_node<T,S>> deleteNode(std::shared_ptr<AVL_node<T,S>> root, S key);

    std::shared_ptr<AVL_node<T,S>> find(std::shared_ptr<AVL_node<T,S>> root,S key);
    std::shared_ptr<AVL_node<T,S>> leftRotation(std::shared_ptr<AVL_node<T,S>> root);
    std::shared_ptr<AVL_node<T,S>> rightRotation(std::shared_ptr<AVL_node<T,S>> root);

    std::shared_ptr<AVL_node<T,S>> treeBalance(std::shared_ptr<AVL_node<T,S>> avl_node);
    void updateHeight();
    void updateBF();
    T& getInfo();

    void setInfo(T& new_info);

    S getKey();
    std::shared_ptr<AVL_node<T,S>> getFather(); 


    template<class DoSomething>
    void inOrder(std::shared_ptr<AVL_node<T,S>> root, DoSomething doSomething);

    template<class DoSomething>
    void preOrder(std::shared_ptr<AVL_node<T,S>> root, DoSomething doSomething);

    // template<class DoSomething>
    // void postOrder(std::shared_ptr<AVL_node<T,S>> root, DoSomething doSomething);
    void postOrderAndDestroy(std::shared_ptr<AVL_node<T,S>> root);

    void NodePointSiblingsToNull(const std::shared_ptr<AVL_node<T,S>>& root);

    void updateHeightAndBF();
    // void updateHeightAndBFSearchPath();

    void printBFAndHeight();

    std::shared_ptr<AVL_node<T,S>> deleteNodeHelper(std::shared_ptr<AVL_node<T,S>> node_to_delete, std::shared_ptr<AVL_node<T,S>> root);

    std::shared_ptr<AVL_node<T,S>> clone(const std::shared_ptr<AVL_node<T,S>> root, const std::shared_ptr<AVL_node<T,S>> parent);


};

template <class T, class S>
void AVL_node<T,S>::setInfo(T& new_info)
{
    this->info = new_info;
}

template <class T, class S>
int AVL_node<T,S>::getBF()
{
    return this->BF;
}

template <class T, class S>
T& AVL_node<T,S>::getInfo()
{
    return this->info;
}

template <class T, class S>
S AVL_node<T,S>::getKey()
{
    return this->key;
}

template <class T, class S>
int AVL_node<T,S>::getHeight()
{
    return this->height;
}

template <class T, class S>
int AVL_node<T,S>::max(int h1, int h2){
    if(h1 < h2){
        return h2;
    }
    return h1;
}
template <class T, class S>
void AVL_node<T,S>::updateHeight(){

    int left_height = -1  ;
    if(this->getLeft_son() != nullptr){
        left_height = this->getLeft_son()->getHeight();
    }

    int right_height = -1;
    if(this->getRight_son() != nullptr)
    {
        right_height = this->getRight_son()->getHeight();
    }
    this->height = 1+max(left_height, right_height);

}

template <class T, class S>
void AVL_node<T,S>::updateBF(){

    int left_height = -1  ;
    if(this->getLeft_son() != nullptr){
        left_height = this->getLeft_son()->getHeight();
    }

    int right_height = -1;
    if(this->getRight_son() != nullptr)
    {
        right_height = this->getRight_son()->getHeight();
    }
    this->BF = left_height - right_height;
}



template <class T, class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::getFather()
{
    return this->father;
}

template <class T, class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::getLeft_son()
{
    return left_son;
}

template <class T, class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::getRight_son()
{
    return right_son;
}


template<class T,class S>
AVL_node<T,S>::AVL_node(const AVL_node<T,S>& other) : BF(other.BF) ,info(other.info), key(other.key), height(other.height),
                                                      father(other.father), left_son(other.left_son), right_son(other.right_son) {} // copy constructor



template<class T,class S>
AVL_node<T,S>& AVL_node<T,S>::operator=(const AVL_node<T,S>& other)
{
    BF = other.BF;
    info = other.info;
    key = other.key;
    height = other.height;
    father = other.father;
    left_son = other.left_son;
    right_son=other.right_son;






    return *this;
}



template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::insert(std::shared_ptr< AVL_node<T,S> > root,S key,T info)
{
    if(root == nullptr)
    {
        // std::shared_ptr<AVL_node<T,S>> root(new AVL_node(key,info)); // make ptr with new if there is problems
        std::shared_ptr<AVL_node<T,S>> root = (std::make_shared<AVL_node>(key,info));

        return root;

        //(*root)(key,info);
    }
    if(key < root->key)
    {
        root->left_son = insert(root->getLeft_son(), key, info);
        if(root->getLeft_son()->key == key)
        {
            root->left_son->father = root;
        }
    }

    if(key > root->key) //*****may be a bug here, check what Shelly did
    {
        //insert(root.getRight_son(), key, info);
        root->right_son = insert(root->getRight_son(), key, info);
        if(root->right_son->key == key)
        {
            root->right_son->father = root;
        }
    }
//    root->updateHeight();
//    root->updateBF();
    //root = treeBalance(root); // remove from here and call the function after insert call



    return root;


}

template<class T,class S>
std::shared_ptr<AVL_node<T,S>>  AVL_node<T,S>::treeBalance(std::shared_ptr<AVL_node<T,S>> avl_node) // where to get avlnode from?
{
//    avl_node->updateHeight();
//    avl_node->updateBF();
    if(avl_node->father)
    {
        avl_node->father->updateHeight();
        avl_node->father->updateBF();
        if(avl_node->father->father)
        {
            avl_node->father->father->updateHeight();
            avl_node->father->father->updateBF();
        }
    }

    std::shared_ptr<AVL_node<T,S>> tmp = avl_node;
    while(avl_node != nullptr)
    {
        avl_node->updateHeightAndBF();   ///change function's name
        int bf = avl_node->BF;
        if( bf == INVALID_BF )
        {
            if(avl_node->getLeft_son()->getBF() == -1)
            {
                std::shared_ptr<AVL_node<T,S>> trash = leftRotation(avl_node->left_son); // LR
            }
            avl_node = rightRotation(avl_node); //LL
        }

        if(bf == -INVALID_BF)
        {
            if(avl_node->getRight_son()->getBF() == 1)
            {
                std::shared_ptr<AVL_node<T,S>> trash = rightRotation(avl_node->right_son); // RL
            }
            avl_node = leftRotation(avl_node); //RR
        }
        avl_node->updateHeightAndBF();
        tmp = avl_node;
        avl_node= avl_node->father;

    }

    return tmp;

}

template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::leftRotation(std::shared_ptr<AVL_node<T,S>> root)
{
    std::shared_ptr<AVL_node<T,S>> root_old_father = root->getFather(); // check if father is equal to NULL
    std::shared_ptr<AVL_node<T,S>> new_root = root->getRight_son();
    std::shared_ptr<AVL_node<T,S>> new_root_left_son = new_root->getLeft_son();     // chaged from root->getFather() to

    if(root_old_father != nullptr)
    {

        if(root_old_father->getLeft_son() == root)
        {
            root_old_father->left_son = new_root;

        }

        if(root_old_father->getRight_son() == root)
        {
            root_old_father->right_son = new_root;
        }

    }
    new_root->father = root_old_father;

    root->father = new_root;
    new_root->left_son = root;

    root->right_son = new_root_left_son;
    if(new_root_left_son != nullptr){
        new_root_left_son->father = root;
        // root->right_son = nullptr;
    }
    return new_root;

}

template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::rightRotation(std::shared_ptr<AVL_node<T,S>> root)
{
    std::shared_ptr<AVL_node<T,S>> root_old_father = root->getFather();
    std::shared_ptr<AVL_node<T,S>> new_root = root->getLeft_son();
    std::shared_ptr<AVL_node<T,S>> new_root_right_son = new_root->getRight_son();

    if(root_old_father != nullptr)
    {

        if(root_old_father->getLeft_son() == root)
        {
            root_old_father->left_son = new_root;

        }

        if(root_old_father->getRight_son() == root)
        {
            root_old_father->right_son = new_root;
        }

    }


    new_root->father = root_old_father;

    root->father = new_root;
    new_root->right_son = root;

    root->left_son = new_root_right_son;
    if(new_root_right_son != nullptr)
    {
        new_root_right_son->father = root;
    }

    return new_root;

}




template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::find(std::shared_ptr<AVL_node<T,S>> root,S key)
{
    // std::shared_ptr<AVL_node<T,S>> tmp = this;
//    std::shared_ptr<AVL_node<T,S>> tmp = (std::make_shared<AVL_node>(*this));
     std::shared_ptr<AVL_node<T,S>> tmp = root;
    // std::shared_ptr<AVL_node<T,S>> tmp(std::make_shared<AVL_node>(*this)); // maybe need <T,S>

    while(tmp != nullptr)
    {
        if(tmp->key == key)
        {
            return tmp;
        }
        if(tmp->key < key)
        {
            tmp = tmp->right_son;
        }
        else
        {
            tmp = tmp->left_son;
        }

    }
    return nullptr;

}

template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::deleteNode(std::shared_ptr<AVL_node<T,S>> root, S key)
{
    if(!root)
    {
        return nullptr;
    }
    std::shared_ptr<AVL_node<T,S>> node_to_delete = root->find(root ,key);
    // std::shared_ptr<AVL_node<T,S>> tmp(new AVL_node(*this));

    if(node_to_delete == nullptr)
    {
        return root;
    }

    if(node_to_delete->left_son == NULL ||node_to_delete->right_son == NULL)
    {

        return deleteNodeHelper(node_to_delete,root);

    }
    else
    {
        std::shared_ptr<AVL_node<T,S>> NextInOrderVal = node_to_delete->getNextInOrderVal();
        // node_to_delete->SwapInfoAndKey(getNextInOrderVal(node_to_delete));
        node_to_delete->SwapInfoAndKey(NextInOrderVal);
       // if(NextInOrderVal->right_son == nullptr || NextInOrderVal->left_son)
      //  {
            return deleteNodeHelper(NextInOrderVal,root);
      //  }

      //  std::cout << node_to_delete->key << " " << node_to_delete->info << std::endl;
      //  std::cout << node_to_delete->getNextInOrderVal()->key << " " << node_to_delete->getNextInOrderVal()->info << std::endl;
       // return deleteNode(root,key);
    }

    return root; // not supposed to get here bcus all option are taken care of

}



template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::getNextInOrderVal()
{
    std::shared_ptr<AVL_node<T,S>> tmp = this->right_son;
    while(tmp->left_son !=nullptr)
    {
        tmp = tmp->left_son;

    }

    return tmp;

}

template<class T,class S>
void AVL_node<T,S>::SwapInfoAndKey(std::shared_ptr<AVL_node<T,S>> avl_node)
{
    S tmp_key = this->key;
    T tmp_info = this->info;

    this->key = avl_node->key;
    this->info = avl_node->info;

    avl_node->key = tmp_key;
    avl_node->info = tmp_info;

//    std::cout << this->key << " " << this->info << std::endl;
//    std::cout << avl_node->key << " " << avl_node->info << std::endl;
}

template<class T,class S>
template<class DoSomething>
void AVL_node<T,S>::inOrder(std::shared_ptr<AVL_node<T,S>> root, DoSomething doSomething)
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root->left_son, doSomething);
    doSomething(root);
    inOrder(root->right_son, doSomething);
}

template<class T,class S>
void AVL_node<T,S>::updateHeightAndBF()
{
    if(this->left_son != nullptr)
    {
        this->left_son->updateHeight();
        this->left_son->updateBF();
    }
    if(this->right_son != nullptr)
    {
        this->right_son->updateHeight();
        this->right_son->updateBF();
    }

    this->updateHeight();
    this->updateBF();

    //  this->printBFAndHeight();

}


template<class T,class S>
template<class DoSomething>
void AVL_node<T,S>::preOrder(std::shared_ptr<AVL_node<T,S>> root, DoSomething doSomething)
{
    if(root == nullptr) return;

    doSomething(root);
    preOrder(root->left_son,doSomething);
    preOrder(root->right_son, doSomething);

}

// template<class T,class S>
// void  AVL_node<T,S>::updateHeightAndBFSearchPath()
// {
//     std::shared_ptr<AVL_node<T,S>> tmp = (std::make_shared<AVL_node>(*this));
//     //    std::shared_ptr<AVL_node<T,S>> root = (std::make_shared<AVL_node>(key,info));
//     while(tmp)
//     {
//         tmp->updateHeight();
//         tmp->updateBF();
//         tmp = tmp->father;
//     }
// }

template<class T,class S>
// template<class DoSomething>
// void AVL_node<T,S>::postOrder(std::shared_ptr<AVL_node<T,S>> root, DoSomething doSomething)
void AVL_node<T,S>::postOrderAndDestroy(std::shared_ptr<AVL_node<T,S>> root)
{
    if(root == nullptr) return;


    // postOrder(root->left_son,doSomething);
    // postOrder(root->right_son, doSomething);

    postOrderAndDestroy(root->left_son);
    postOrderAndDestroy(root->right_son);

    root->NodePointSiblingsToNull(root);


}


template<class T,class S>
void AVL_node<T,S>::NodePointSiblingsToNull(const std::shared_ptr<AVL_node<T,S>>& root)
{
    root->left_son = NULL;
    root->right_son= NULL;
    root->father = NULL;
}


template<class T,class S>
void AVL_node<T,S>::printBFAndHeight()
{
    std::cout << this->BF<<" " << this->height << std::endl;
    std::cout << " **************** " << std::endl;
}


template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::deleteNodeHelper(std::shared_ptr<AVL_node<T,S>> node_to_delete, std::shared_ptr<AVL_node<T,S>> root)
{
    //std::shared_ptr<AVL_node<T,S>> func(node_to_delete->right, node_to_delete->left)
    std::shared_ptr<AVL_node<T,S>> tmp = node_to_delete->left_son ? node_to_delete->left_son :
                                         node_to_delete->right_son ;

    std::shared_ptr<AVL_node<T,S>> node_to_delete_father = node_to_delete->father;
    if(tmp == nullptr) //no children
    {
        if(node_to_delete->father == nullptr) // we are at root
        {
            root = nullptr;
            return nullptr;
        }
        else  //leaf
        {
            //std::shared_ptr<AVL_node<T,S>> node_to_delete_father = node_to_delete->get().father;
            if(node_to_delete->father->left_son == node_to_delete)
            {
                node_to_delete->father->left_son = nullptr;
            }
            else
            {
                node_to_delete->father->right_son = nullptr;
            }


            node_to_delete->father = nullptr;


            // node_to_delete_father->updateHeightAndBFSearchPath();
            root = node_to_delete_father->treeBalance(node_to_delete_father);
            // update height and bf for all nodes in the searching path and treeBalance
            return root;
        }
    }
    else if(node_to_delete->left_son != nullptr)  //one child case (left son)
    {
        //std::shared_ptr<AVL_node<T,S>> node_to_delete_father = node_to_delete->get().father;
        if(node_to_delete->father == nullptr) // we are at root
        {

            root = node_to_delete->left_son;
            root->father = nullptr;
            node_to_delete->left_son = nullptr;
            return root;  //child height and bf doesnt change
        }
        if(node_to_delete->father->left_son == node_to_delete)
        {
            node_to_delete->father->left_son = node_to_delete->left_son;
        }
        else
        {
            node_to_delete->father->right_son = node_to_delete->left_son;
        }
        node_to_delete->left_son->father =  node_to_delete->father;
        node_to_delete->left_son = nullptr;
        node_to_delete->father = nullptr;

        // node_to_delete_father->updateHeightAndBFSearchPath();
        root = node_to_delete_father->treeBalance(node_to_delete_father);
        // update height and bf for all nodes in the searching path and treeBalance
        return root;

    }
    else if(node_to_delete->right_son != nullptr)  //one child case (right son)
    {
        if(node_to_delete->father == nullptr) // we are at root
        {
            root = root->right_son;
            root->father = nullptr;
            node_to_delete->right_son = nullptr;
            return root; //child height and bf doesnt change
        }


        if(node_to_delete->father->left_son == node_to_delete)
        {
            node_to_delete->father->left_son = node_to_delete->right_son;
        }
        else
        {
            node_to_delete->father->right_son = node_to_delete->right_son;
        }
        node_to_delete->right_son->father =  node_to_delete->father;
        node_to_delete->right_son = nullptr;
        node_to_delete->father = nullptr;


//        node_to_delete->father->right_son = node_to_delete->right_son;
//        node_to_delete->right_son->father =  node_to_delete->father;
//        node_to_delete->right_son = nullptr;
//        node_to_delete->father = nullptr;


        // node_to_delete_father->updateHeightAndBFSearchPath();
        root = node_to_delete_father->treeBalance(node_to_delete_father);
        // update height and bf for all nodes in the searching path and treeBalance
        return root;
    }

    return root;
}

template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::clone(const std::shared_ptr<AVL_node<T,S>> root
, const std::shared_ptr<AVL_node<T,S>> parent)
{

    if(root == nullptr)
    {
        return nullptr;
    }

    std::shared_ptr<AVL_node<T,S>> temp = (std::make_shared<AVL_node>(*root));
    temp->key  = root->key;
    temp->info = root->info;
    temp->father = parent;
    temp->left_son = clone(root->left_son,temp);
    temp->right_son = clone(root->right_son, temp);
    return temp;
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
