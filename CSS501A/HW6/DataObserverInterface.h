#ifndef DataObserverInterface_h
#define DataObserverInterface_h

#include "DataPacket.h"

// The Abstract Observer
template<class T>
class DataObserverInterface
{
public:
    virtual void update(DataPacket<T>& dp) = 0;
    virtual void display(){
        cout << "I am Data Observer Interface" << endl;
    }
};

#endif