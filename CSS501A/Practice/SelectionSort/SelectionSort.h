

#ifndef SelectionSort_h
#define SelectionSort_h

#include <iostream>
#include <string>

using namespace std;

template<class T>
class SelectionSort{
    private:
        T* items;

        void swap(T* items, int maxIdx, int lastIdx){
            T lastItem = items[lastIdx];
            items[lastIdx] = items[maxIdx];
            items[maxIdx] = lastItem;
        }

        int findMaxIdx(const T* items, const int lastIdx) const{
            int maxIdx = 0;
            int curIdx = 0;
            for(int i = 1; i <= lastIdx; i++){
                if(items[i] > items[maxIdx]){
                    maxIdx = i;
                }
            }
            return maxIdx;
        }

    public:
        SelectionSort(T* items){
            this->items = items;
        };

        void Sort(T* items, int size){
            int lastIdx = size-1;
            for(int i = lastIdx; i >= 1; i--){
               int maxIdx = findMaxIdx(items, i);
               swap(items,maxIdx,i);
            }
        }

        void Display(T* items, int size) const{
            for(int i = 0; i < size; i++){
                cout << items[i] << endl;
            }
        }
};

#endif