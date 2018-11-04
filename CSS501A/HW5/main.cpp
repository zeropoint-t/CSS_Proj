
#include <iostream>
#include <cstdlib>
#include <string>
#include "Set.h"
#include "Data.h"
#include "Pikachu.h"

using namespace std;


int main(){

    cout << "*********************************************************" << endl;
    cout << "--Demonstration 1: Key increments in a set--" << endl;
    cout << "*********************************************************" << endl;
    //demo set
    Set<Data<string>> demo1;
    //first templated object
    Data<string> strData1("Hello World");
    //second templated object with the same value
    Data<string> strData2("I love programming");
    demo1.Add(strData1);
    demo1.Add(strData2);
    cout << "--Show 2 separate objects--" << endl;
    demo1.PrintAll();
    cout << endl;

    //Third duplicate object with the same value
    Data<string> strData3("I love programming");
    demo1.Add(strData3);
    cout << "--Show that duplicate objects are incremented--" << endl;
    demo1.PrintAll();

    cout << endl << endl;

    cout << "*********************************************************" << endl;
    cout << "--Demonstration 2: Inserting integer objects into a set--" << endl;
    cout << "*********************************************************" << endl;

    //create random integer values and insert into a custom set
    Set<Data<int>> s;
    for(int i = 0; i < 200; i++){
        int val = rand()%25+1;//i%(rand()%11+1);
        Data<int> intData(val);
        s.Add(intData);
    }

    cout << endl;
    cout << "--Print all items--" << endl;
    s.PrintAll();

    cout << endl;

    //[2 points] A way to display the top 3 keys in the structure
    cout << "--Print top n items--" << endl;
    s.PrintTopN(5);

    cout << endl;

    //[1 Point] A way to obtain the counter for a given key
    cout << "--Find data whose value = 2 --" << endl;
    int val = 2;
    Data<int> int_to_find(val);
    int i_counter = s.GetCounter(int_to_find);
    cout << "Counter for key " << val << " is " << i_counter << endl;


    cout << endl << endl;


    cout << "*********************************************************" << endl;
    cout << "--Demonstration 3: Inserting Pikachu objects into a set--" << endl;
    cout << "*********************************************************" << endl;

    Set<Data<Pikachu>> p;
    for(int i = 1; i <= 100; i++){
        int val = rand()%25+1;//i%(rand()%11+1)*100;
        Pikachu pk(val);
        Data<Pikachu> pikaData(pk);
        p.Add(pikaData);
    }

    cout << endl;
    cout << "--Print all items--" << endl;
    p.PrintAll();

    cout << endl;

    //[2 points] A way to display the top 3 keys in the structure
    cout << "--Print top n items--" << endl;
    p.PrintTopN(5);

    cout << endl;

    //[1 Point] A way to obtain the counter for a given key
    cout << "--Find Picachu whose remaining power is 500 --" << endl;
    int pika_remain_power = 500;
    Data<Pikachu> pikachu_to_find(pika_remain_power);
    int p_counter = p.GetCounter(pikachu_to_find);
    cout << "Counter for Pikachu whose remaining power is " << val << " is " << p_counter << endl;
}