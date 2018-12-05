

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person{
public:
    Person(){
        this->name = "Default";
    }
    Person(string name){
        // cout << "Person constructor called" << endl;
        this->name = name;
        // cout << this->name << endl;
    }
    virtual ~Person(){
        cout << "Person Destroyed at " << this << endl;
    }
    string getName(){
        return this->name;
    }
protected:

private:
    string name;
};

class Student : virtual public Person{
public:
    Student(string name):Person(name){
        cout << "Student constructor called" << endl;
    }
    ~Student() override{
        cout << "Student Destroyed at " << this << endl;
    }
    void displayStudent(){
        cout << "Hey I am a student!! at " << this << endl;
    }
protected:

private:

};

class Instructor : virtual public Person{
public:
    Instructor(string name):Person(name){
        cout << "Instructor constructor called" << endl;
    }
    ~Instructor() override{
        cout << "Instructor Destroyed at " << this << endl;
    }
    void displayInstructor(){
        cout << "Hey I am a Instructor!! at " << this << endl;
    }
protected:

private:

};

class Superman : public Student, public Instructor{
    public:
        Superman(string name):Student(name),Instructor(name){
            cout << " " << endl;
        }
    private:
};

class TestClass{
    public:
    TestClass(){
        ps = new Person[2];
    }
    void Test(){
        Student p1("Tetsuya");
        Student p2("Hahashi");
        Student p3("Erin");
        p2 = p3;
        ps[0] = p1;
        ps[1] = p2;
    }
    private:
        Person* ps;
};


int main(){
    vector<Person*> persons;
    persons.push_back(new Student("Tetsuya"));
    persons.push_back(new Instructor("Erin"));
    persons.push_back(new Superman("Hayashi"));
    for(auto it = persons.begin(); it != persons.end(); it++){
        if (Student* s = dynamic_cast<Student*>(*it)){
            s->displayStudent();
        }

        if (Instructor* i = dynamic_cast<Instructor*>(*it)){
            i->displayInstructor();
        }
    }

    cout << endl;
}