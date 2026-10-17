#include <iostream>
using namespace std;

class Human {
    string name;
    int age;
    float weight;
public:
    static int CountHumans;
    Human()
    {
        name = "no name";
        age = 0;
        weight = 0;
    }
    Human(string name):Human()
    {
        this->name = name;
        //age = 0;
        //weight = 0;
    }
    Human(string name, int age) :Human(name)
    {
        //this->name = name;
        this->age = age;
        //weight = 0;
    }
    
    Human(string name, int age, float weight) :Human(name,age)
    {
        //this->name = name;
        //this->age = age;
        this->weight = weight;
    }
    void Print() {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Weight:" << weight << endl;
        cout << endl;
    }
};


int main()
{
    Human h1;
    h1.Print();

    
}
