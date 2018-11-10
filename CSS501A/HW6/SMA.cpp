#include "SMA.h"

//copy constructor
template<class T>
SMA<T>::SMA(const SMA<T>& sma){
    setPeriod(sma.period);
}

template<class T>
SMA<T>::SMA(int32_t p){
    setPeriod(p);
    values = new DataPacket<T>*[this->period]{ nullptr };
}

template<class T>
SMA<T>::~SMA(){
    for(int i = 0; i < this->period; i++){
        if(values[i] != nullptr)
            delete values[i];
    }
    delete[] values;
}


template<class T>
int32_t SMA<T>::getPeriod(){
    return this->period;
}

template<class T>
void SMA<T>::setPeriod(int32_t p){
    if(p <= 0 || p > 30){
        throw std::out_of_range("SMA: period out of range exception");
    }

    this->period = p;
}

template<class T>
void SMA<T>::update(DataPacket<T>& dp){
    add(dp);
}

template<class T>
void SMA<T>::add(DataPacket<T>& dp){
    int ind = curIndex++ % this->period;
    //release object before replacing
    if(values[ind] != nullptr)
        delete values[ind];
    //assign new object
    values[ind] = new DataPacket<T>(dp);
    calculate();
}

template<class T>
void SMA<T>::calculate(){
    //calculate simple moving average
    T total;
    for(int i = 0; i < this->period; i++){
        if(values[i] != nullptr)
            total+=values[i]->close;
    }
    this->value = total / this->period;
    cout << "SMA: " << this->value << endl;
}