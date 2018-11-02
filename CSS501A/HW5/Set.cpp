#include "Set.h"
#include <map>

template<class T>
bool operator<(const T &d1, const T &d2){
    return d1.getData() < d2.getData();
}

template<class T>
Set<T>::Set(){}

template<class T>
void Set<T>::Add(T& d){
    if(this->data.find(d) == data.end()){
        this->data[d] = 1;
    }else{
        this->data[d]++;
    }
}

template<class T>
void Set<T>::PrintItems() const{
    for(auto it = data.begin(); it != data.end(); it++){
        cout << "Key: " << it->first.getData() << " Value: " << it->second << endl;
    }
}