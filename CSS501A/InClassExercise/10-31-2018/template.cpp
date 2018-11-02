#include "template.h"

template<class T>
Foo<T>::Foo(T t){
    this->subject = t;
}

template<class T>
T& Foo<T>::bar(){
    return subject;
}