#ifndef AVL_NODE_H
#define AVL_NODE_H
#include <iostream>
#include <memory>
#include <cmath>

#define INVALID_BF 2;

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
        T getInfo();
        S getKey();
        int getHeight();
        std::shared_ptr<AVL_node<T,S>> getFather(); // maybe & 
        std::shared_ptr<AVL_node<T,S>> getLeft_son();
        std::shared_ptr<AVL_node<T,S>> getRight_son();
        int max(int h1, int h2);


    public:
        AVL_node() : BF(0) , info(), key(), height(0), father(nullptr),left_son(nullptr), right_son(nullptr){}; //constructor
        AVL_node(S key, T info) : BF(0) , info(info), key(key), height(0), father(nullptr),left_son(nullptr), right_son(nullptr){} ; //constructor
        ~AVL_node(); //destructor
        AVL_node(const AVL_node&); //copy constructor
        AVL_node& operator=(const AVL_node& other); // avl_node1= avl_node2

        std::shared_ptr<AVL_node<T,S>> insert(std::shared_ptr<AVL_node<T,S>> root,S key,T info); // change other to sharedptr
        std::shared_ptr<AVL_node<T,S>> deleteNode(std::shared_ptr<AVL_node<T,S>> root, S key);
        
        std::shared_ptr<AVL_node<T,S>> find(S key);
        std::shared_ptr<AVL_node<T,S>> leftRotation(std::shared_ptr<AVL_node<T,S>> root);
        std::shared_ptr<AVL_node<T,S>> rightRotation(std::shared_ptr<AVL_node<T,S>> root);
        // void inOrder(AVL_node *root);
        std::shared_ptr<AVL_node<T,S>> treeBalance(std::shared_ptr<AVL_node<T,S>> avl_node);
        void updateHeight();
        void updateBF();
        
};


template <class T, class S>
int AVL_node<T,S>::getBF()
{
    return this->BF;
}

template <class T, class S>
T AVL_node<T,S>::getInfo()
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
    if(this->getLeft_son() != nullptr)
    {
        right_height = this->getRight_son()->getHeight();
    }
    this->getHeight = 1+max(left_height, right_son);
    
}

template <class T, class S>
void AVL_node<T,S>::updateBF(){

    int left_height = -1  ;
    if(this->getLeft_son() != nullptr){
        left_height = this->getLeft_son()->getHeight();
    }
    
    int right_height = -1;
    if(this->getLeft_son() != nullptr)
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
    

    

    if(key < root->get().key)
    {
        root->get().getLeft_son() = insert(root->getLeft_son(), key, info);
        if(root->getLeft_son()->geykey() == key)
        {
            root->getLeft_son().father = root;
        }
    }

     if(key > root->root->getKey() ) //*****may be a bug here, check what Shelly did
    {
        //insert(root.getRight_son(), key, info);
        root->getRight_son() = insert(root->getLeft_son(), key, info);
        if(root->getRight_son()->geyKey() == key)
        {
            root->getRight_son().father = root;
        }

    }

    

    root->updateHeight();
    root->updateBF();
    //root = treeBalance(root); // remove from here and call the function after insert call
    
    

    return root; 


}

template<class T,class S>
std::shared_ptr<AVL_node<T,S>>  AVL_node<T,S>::treeBalance(std::shared_ptr<AVL_node<T,S>> avl_node) // where to get avlnode from?
{
    
    while(avl_node != nullptr)
    {

        int bf = *avl_node.get().getBF;
        if( bf == INVALID_BF )
        {
            if(avl_node->getLeft_son()->getBF() == -1)
            {
                avl_node = leftRotation(avl_node->get().left_son); // LR
            }
            avl_node = rightRotation(avl_node); //LL
        }

        if(bf == -INVALID_BF)
        {
            if(avl_node->getRight_son()->getBF() == 1)
            {
                avl_node = rightRotation(avl_node->get().right_son); // RL
            }
            avl_node = leftRotation(avl_node); //RR
        }
        avl_node= avl_node->father;
    
    }

    /**
     * @brief 
     * addplayer(DS,avl_node,key)
     * {
     *      newroot = insert(DS.playertree, avl_node);
     *      //find the node
     *      DS.playertree = treebalance(newroot ,avl_node);
     *       
     *      DS.playertree->find(key);
     * }
     * 
     * 
     * 
     */

    // avl_node->updateHeight();
    // avl_node->updateBF();

    return avl_node;
            
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
            root_old_father.left_son = new_root;
            
        }
    
        if(root_old_father->getRight_son() == root)
        {
            root_old_father.right_son = new_root;       
        }
        
    }
    new_root.father = root_old_father;
     
    root.father = new_root;
    new_root.left_son = root;
    
    root.right_son = new_root_left_son;
    new_root_left_son.father = root;

    return root;
    
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
            root_old_father.left_son = new_root;
            
        }
    
        if(root_old_father->getRight_son() == root)
        {
            root_old_father.right_son = new_root;       
        }
        
    }


    new_root.father = root_old_father;
     
    root.father = new_root;
    new_root.right_son = root;
    
    root.left_son = new_root_right_son;
    new_root_right_son.father = root;

    return root;
    
}




template<class T,class S>
std::shared_ptr<AVL_node<T,S>> AVL_node<T,S>::find(S key) 
{
   // std::shared_ptr<AVL_node<T,S>> tmp = this; 
    std::shared_ptr<AVL_node<T,S>> tmp(new AVL_node(*this)); // maybe need <T,S>
    
    while(tmp != nullptr)
    {
        if(tmp->get().key == key)
        {
            return tmp;
        }
        if(tmp->get().key < key)
        {
            tmp = tmp->get().right_son;
        }
        else
        {
            tmp = tmp->get().left_son;
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
    std::shared_ptr<AVL_node<T,S>> node_to_delete = root->get().find(key);
   // std::shared_ptr<AVL_node<T,S>> tmp(new AVL_node(*this));

    if(node_to_delete == nullptr)
    {
        return root;
    }
    
    std::shared_ptr<AVL_node<T,S>> tmp = node_to_delete->get().left_son ? node_to_delete->get().left_son :
    node_to_delete->get().right_son ;
    
    if(tmp == nullptr) //no children
    {
        
    } 






    if(node_to_delete->get().left_son == nullptr && node_to_delete->get().right_son == nullptr) // node_to_delete is a leaf
    {
        if(node_to_delete->get().father == nullptr) // we are at root
        { 
            root = nullptr;
            return nullptr;
        }
        else
        {
           // std::shared_ptr<AVL_node<T,S>> node_to_delete_father = node_to_delete->get().father;
            if(node_to_delete->get().father.getLeft_son == node_to_delete)
            {
                node_to_delete->get().father.getLeft_son = nullptr;
            }
            else
            {
                node_to_delete->get().father.getRight_son = nullptr;
            }

        }

    }
    else if(node_to_delete->get().left_son == nullptr || node_to_delete->get().right_son == nullptr)
    {
       
        if(node_to_delete->get().left_son != nullptr)
        {
            if(node_to_delete->get().father == nullptr) // we are at root
            { 
                
                root = node_to_delete->get().left_son;
                root.father = null;
                return root;
            }

            node_to_delete.father = 
            
            
        }
        
        /*
        setfather(avl_node)
        {

        }



        */
        

        

        if(node_to_delete->get().right_son != nullptr)
        {
            if(node_to_delete->get().father == nullptr) // we are at root
            { 
                root = root->get().rigetRight_son();
                root.father = nullptr;
                return root;
            }
            node_to_delete->get().father
        }

    }
    else
    {

    }


        


}


       
        





























#endif
