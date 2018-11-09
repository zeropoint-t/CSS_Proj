
#ifndef DisplayDataPacketInterface_h
#define DisplayDataPacketInterface_h

#include "DataPacket.h"

// The Abstract Observer
template<class T>
class DisplayDataPacketInterface
{
public:
    virtual void display() = 0;
};

#endif