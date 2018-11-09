
#ifndef DataManagerInterface_h
#define DataManagerInterface_h

#include <list>
#include "DataObserverInterface.h"

// The Abstract Subject
template<class T>
class DataManagerInterface
{
public:
    virtual void registerObserver(DataObserverInterface<T>* ob) = 0;
    virtual void removeObserver(DataObserverInterface<T>* ob) = 0;
    virtual void notifyObserver() = 0;

private:
    list<DataObserverInterface<T>* > m_obs;
};

#endif