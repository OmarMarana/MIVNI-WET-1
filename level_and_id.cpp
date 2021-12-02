//
// Created by omarm on 02/12/2021.
//

#include "level_and_id.h"

bool LevelAndId::operator>(const LevelAndId& other) const
{

    /*
    if its not less than and not equal then it must be larger than
    assuming the < and == are defined properly;
    */
    if( (*this < other ) == false && (*this == other ) == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LevelAndId::operator<(const LevelAndId& other) const
{
    //LI1 < LI2?
    //this < other? true if this.id > other.id
    if(this->Level == other.Level)
    {
        if(this->Id > other.Id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //if levels arent equal then ids are irrelevant
    return this->Level < other.Level;
}

bool LevelAndId::operator==(const LevelAndId& other) const
{
    return ( (this->Id == other.Id) && (this->Level == other.Level) );
}

int LevelAndId::getLevel() const
{
    return Level;
}
int LevelAndId::getId() const
{
    return Id;
}
