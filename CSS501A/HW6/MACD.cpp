
#include "MACD.h"

template<class T>
MACD<T>::MACD(int32_t p1, int32_t p2):period1(p1),period2(p2),EMA<T>(p1),SMA<T>(p2)  {
}

template<class T>
MACD<T>::~MACD(){
}

template<class T>
void MACD<T>::update(DataPacket<T>& dp){

    SMA<T>::update(dp);
    EMA<T>::update(dp);

    this->sma_value = SMA<T>::value;
    this->ema_value = EMA<T>::value;
    this->hist_value = this->ema_value - this->sma_value;

    cout << "Hist Value: " << this->hist_value << endl;
}