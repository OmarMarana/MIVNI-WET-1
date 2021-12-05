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

StatusType AddPlayer(void *DS, int PlayerID, int GroupID, int Level)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMAddPlayer(PlayerID,GroupID,Level);
}


StatusType RemovePlayer(void *DS, int PlayerID)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMRemovePlayer(PlayerID);
}

StatusType ReplaceGroup(void *DS, int GroupID, int ReplacementID)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMReplaceGroup(GroupID,ReplacementID);

}


StatusType IncreaseLevel(void *DS, int PlayerID, int LevelIncrease)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMIncreaseLevel(PlayerID,LevelIncrease );
}

StatusType GetHighestLevel(void *DS, int GroupID, int *PlayerID)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMGetHighestLevel(GroupID,PlayerID);
}


StatusType GetAllPlayersByLevel(void *DS, int GroupID, int **Players, int *numOfPlayers)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMGetAllPlayersByLevel(GroupID, Players, numOfPlayers );
}

StatusType GetGroupsHighestLevel(void *DS, int numOfGroups, int **Players)
{
    if(DS == nullptr)
    {
        return INVALID_INPUT;
    }
    return ((PlayerManager*)DS)->PMGetGroupsHighestLevel(numOfGroups, Players);
}


void Quit(void** DS)
{
    // check if DS is null
    if(DS== nullptr || *DS== nullptr){
        return;
    }
    delete ((PlayerManager*)(*DS));
    *DS= nullptr;

}