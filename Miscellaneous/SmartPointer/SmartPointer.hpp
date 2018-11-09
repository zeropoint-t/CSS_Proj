//
//  SmartPointer.hpp
//  SmartPointer
//
//  Created by Tetsuya Hayashi on 9/19/18.
//  Copyright © 2018 Tetsuya Hayashi. All rights reserved.
//

#ifndef SmartPointer_hpp
#define SmartPointer_hpp

#include <stdio.h>
#include "iostream"

class RC
{
private:
    int count; // Reference count
    
public:
    void AddRef()
    {
        // Increment the reference count
        count++;
    }
    
    int Release()
    {
        // Decrement the reference count and
        // return the reference count.
        return --count;
    }
};

template < typename T > class SmartPointer
{
private:
    T*    pData;       // pointer
    RC*   reference; // Reference count
    
public:
    SmartPointer() : pData(0), reference(0)
    {
        std::cout << "SmartPointer Constructor called at " << this << std::endl;
        reference = new RC();
        reference->AddRef();
    }
    
    SmartPointer(T* pValue) : pData(pValue), reference(0)
    {
        std::cout << "SmartPointer Constructor called at " << this << std::endl;
        reference = new RC();
        reference->AddRef();
    }
    
    SmartPointer(const SmartPointer<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        std::cout << "SmartPointer Copy Constructor called at " << this << std::endl;
        reference->AddRef();
    }
    
    ~SmartPointer()
    {
        if(reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
    }
    
    T& operator* ()
    {
        return *pData;
    }
    
    T* operator-> ()
    {
        return pData;
    }
    
    SmartPointer<T>& operator = (const SmartPointer<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            //before values are copied, objects currently pointed to may need to be released first
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }
            
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};
#endif /* SmartPointer_hpp */
