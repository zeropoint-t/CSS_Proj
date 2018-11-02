#ifndef set_h
#define set_h

#include <map>
using namespace std;

template<class T>
bool operator<(const T &d1, const T &d2);

template<class T>
class Set
{
public:
    Set();
    void Add(T& d);
    void PrintItems() const;
private:
    map<T,int> data;
};

#include "Set.cpp"

#endif