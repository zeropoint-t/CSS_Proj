#ifndef DataManager_h
#define DataManager_h

#include "DataManagerInterface.h"

template<class T>
class DataManager : public DataManagerInterface{
    public:
    void registerObserver(DataObserverInterface<T>* ob);
    void removeObserver(DataObserverInterface<T>* ob);
    void notifyObserver();
};

#endif