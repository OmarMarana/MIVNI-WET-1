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

    PlayerManager pm1;
    pm1.PMAddGroup(1);
    pm1.PMAddGroup(2);
    pm1.PMAddGroup(3);
    pm1.PMAddGroup(4);
    pm1.PMAddGroup(5);


    pm1.PMAddPlayer(1,1,1);
    pm1.PMAddPlayer(2,1,2);
    pm1.PMAddPlayer(3,2,3);
    pm1.PMAddPlayer(4,3,4);
    pm1.PMAddPlayer(5,4,5);
    pm1.PMAddPlayer(6,5,6);

    pm1.PMIncreaseLevel(2,7);

    pm1.PMReplaceGroup(1, 2);
    pm1.PMReplaceGroup(2, 3);

    pm1.PMIncreaseLevel(1,10);

    pm1.PMRemovePlayer(1);

    pm1.PMReplaceGroup(3, 4);



    return 0;

}