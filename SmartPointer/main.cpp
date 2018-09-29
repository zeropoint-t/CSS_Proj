//
//  main.cpp
//  SmartPointer
//
//  Created by Tetsuya Hayashi on 9/15/18.
//  Copyright © 2018 Tetsuya Hayashi. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

class Person
{
    int age;
    string pName;
    
public:
    Person(): pName(0),age(0)
    {
    }
    Person(string pName, int age): pName(pName), age(age)
    {
    }
    ~Person()
    {
    }
    
    void Display()
    {
        //printf("Name = %s Age = %d \n", pName, age);
        cout << "Name = " << pName << " " << "Age = " << age << endl;
    }
    void Shout()
    {
        cout << "Ooooooooooooooooo" << endl;
        //printf("Ooooooooooooooooo");
    }
};



int main(int argc, const char * argv[]) {
    
    Person p1("Tetsuya", 38);
    Person p2("Erin", 30);
    
    LinkedList<Person> ll;

    bool success = ll.Insert(1, p1);

    success = ll.Insert(2, p2);

    ll.Clear();
    
    
//    SmartPointer<Person> p(new Person("Scott", 25));
//    std::cout << &p << std::endl;
//    p->Display();
//    {
//        SmartPointer<Person> q = p;
//        std::cout << &q << std::endl;
//        q->Display();
//        // Destructor of q will be called here..
//
//        SmartPointer<Person> r;
//        std::cout << &r << std::endl;
//        r = p;
//        r->Display();
//        // Destructor of r will be called here..
//    }
//    p->Display();
////     Destructor of p will be called here
////     and person pointer will be deleted
    
    cout << "Program is ending!!" << endl;
    
    return 0;
}
