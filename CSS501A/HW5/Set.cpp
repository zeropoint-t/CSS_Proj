#include "Set.h"
#include <map>

using namespace std;

//std::map requires comparer method to sort keys
template<class T>
bool operator<(const T &d1, const T &d2){
    return d1.getData() < d2.getData();
}

template<class T>
Set<T>::Set(){}

template<class T>
void Set<T>::Add(T& d){
    if(this->m.find(d) == m.end()){
        //new in map, start increment from 1
        this->m[d] = 1;
    }else{
        //duplicate in map, increment the counter
        this->m[d]++;
    }
}

template<class T>
int Set<T>::GetCounter(T& d){
    return this->m[d];
}

/*
Print all items
*/
template<class T>
void Set<T>::PrintAll() const{
    int cnt = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        cout << "Key: " << it->first.getData() << "   - Counter: " << it->second << endl;
    }
}
/*
Print top n items ordered by access count in descending order
*/
template<class T>
void Set<T>::PrintTopN(int top) const{
    //use multipmap to sort counters as keys
    multimap<int,T> topN;
    //insert counter as a key, and T as value
    for(auto it = m.begin(); it != m.end(); it++){
        int counter = (*it).second;//num of times the same object was attempted to be added
        T obj((*it).first);//an object of type T
        topN.insert(make_pair(counter, obj));
    }
    //display top n items from the highest counter
    for(auto it = topN.rbegin(); it != topN.rend(); it++){
        if(top-- > 0){
            cout << "Object: " << ((*it).second).getData() << "   - Count: " << (*it).first << endl;
        }else{
            break;
        }
    }
}