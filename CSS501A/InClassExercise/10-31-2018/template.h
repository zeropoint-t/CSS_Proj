#ifndef template_h
#define template_h

template<typename T>
class Foo
{
public:
    Foo(T t);
     T& bar();
private:
     T subject;
};

#include "template.cpp"

#endif