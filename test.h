#include <iostream>
#include <memory>

//template <class T>
class A
{
    
    int  val;

//    int find(std::shared_ptr< A<T> > a);
     int find(std::shared_ptr< A > a);
};


template <class T>
//int find(std::shared_ptr< A<T> > a)
 int find(std::shared_ptr< A > a)
{
     a->


}

