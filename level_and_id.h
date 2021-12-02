//
// Created by omarm on 02/12/2021.
//

#ifndef MIVNI_LEVEL_AND_ID_H
#define MIVNI_LEVEL_AND_ID_H
class LevelAndId
{
private:
    int Level;
    int Id;
    friend class player;

public:
    LevelAndId(int Level, int Id) : Level(Level) , Id(Id){};
    LevelAndId() =default;
    ~LevelAndId() =default;
    LevelAndId(const LevelAndId&) =default;
    LevelAndId& operator=(const LevelAndId& other) = default;

   int getId() const;
   int getLevel() const;


   bool operator==(const LevelAndId& other) const ;     // check how to declare as friend
   bool operator<(const LevelAndId& other) const ;
   bool operator>(const LevelAndId& other) const ;



};



#endif //MIVNI_LEVEL_AND_ID_H
