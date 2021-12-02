#include "library1.h"
#include "PlayerManager.h"

void *Init()
{
    PlayerManager* DS = new PlayerManager();
    return (void*) DS;
}

StatusType AddGroup(void *DS, int GroupID)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMAddGroup(GroupID);
}


void Quit(void** DS)
{
    
    
    if(DS== nullptr || *DS== nullptr){
        return;
    }
    delete ((PlayerManager*)(*DS));
    *DS= nullptr;

}