#include <iostream>
#include <string>

using namespace std;

class BaseClass{
    public:
        static BaseClass* const getInstance(){
            if(b == nullptr){
                instantiating = true;
                b = new BaseClass();
                instantiating = false;
            }
            return b;
        }

        virtual void print(){
            cout << "Base Class at " << this << endl;
        }

    private:    
        static BaseClass *b;
        static bool instantiating;

    //constructor needs to be protected and not private
    //so that T class can call it
    protected:
        BaseClass(){
            if(!instantiating){
                throw std::runtime_error("Don't call me!!");
            }
            cout << "base class created at " << this << endl;
        }
};

BaseClass* BaseClass::b = nullptr;
bool BaseClass::instantiating = false;

class ConcreteClass : public BaseClass{
    public:
        ConcreteClass(){
            BaseClass::getInstance();
            cout << "Concrete class created at " << this << endl;
        }
        static ConcreteClass* const getInstance(){
            if(c == nullptr){
                c = new ConcreteClass();
            }
            return c;
        }
        void print() override{
            cout << "Child class at " << this << endl;
        }
    private:
        static ConcreteClass* c;
};

ConcreteClass* ConcreteClass::c = nullptr;

// template<typename T>
// class generic_singleton
// {
// private:
//     static T* _instance;

//     static void _singleton_deleter() { 
//         delete _instance; 
//     } //Function that manages the destruction of the instance at the end of the execution.

// protected:
//     generic_singleton() {}
//     virtual generic_singleton() {} //IMPORTANT: virtual destructor

// public:
//     T& instance() //Never return pointers!!! Be aware of "delete Foo.instance()"
//     {
//         if(!_instance)
//         {
//             _instance = new T;
//             std::atexit( _singleton_deleter ); //Destruction of instance registered at runtime exit (No leak).
//         }

//         return static_cast<T&>( _instance );
//     }
// };

// template<typename T>
// T* generic_singleton<T>::_instance = nullptr;

int main(){

    // const int result_1 = std::atexit(atexit_handler_1);
    // const int result_2 = std::atexit(atexit_handler_2);
 
    // if ((result_1 != 0) or (result_2 != 0)) {
    //     std::cerr << "Registration failed\n";
    //     return EXIT_FAILURE;
    // }
 
    // std::cout << "returning from main\n";
    // return EXIT_SUCCESS;



    cout << endl;
    ConcreteClass* c = ConcreteClass::getInstance();
    c->print();

    BaseClass* b = c;
    b->print();

    BaseClass* a = BaseClass::getInstance();
    a->print();

    ConcreteClass cc;
    cc.print();

}