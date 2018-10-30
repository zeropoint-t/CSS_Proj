
#include <string>
#include <iostream>

class Cat{
    public:
        Cat();
        Cat(int wt);

        bool operator>(const Cat& cat);
    private:
        int weight;
};

Cat::Cat(){}

Cat::Cat(int wt){
    this->weight = wt;
}

bool Cat::operator>(const Cat& cat){
    if(this->weight > cat.weight){
        return true;
    }

    return false;
}

template<class T>
class GenericClass{
    public:
        GenericClass(T val1, T val2);
        T findMax();
    private:
        T d1;
        T d2;
};

template<class T>
GenericClass<T>::GenericClass(T val1, T val2){
    this->d1 = val1;
    this->d2 = val2;
}

template<class T>
T GenericClass<T>::findMax(){
    return d1 > d2 ? d1 : d2;
}

using namespace std;

int main(){
    int intNum = 0;
    string strNum = "56213";
    int lg = strNum.size();
    for(int i = 0; i < lg; i++){
        cout << (int)strNum[i]-'0' << endl;
        intNum = (intNum * 10) + (int)strNum[i]-'0';
    }

    cout << intNum << endl;

    Cat cat1(10);
    Cat cat2(20);

    GenericClass<Cat> maxCat(cat1, cat2);
    Cat biggerCat = maxCat.findMax();

    GenericClass<double> maxDouble(10.5, 10.2);
    double biggerNumber = maxDouble.findMax();
}