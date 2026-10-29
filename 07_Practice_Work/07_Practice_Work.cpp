#include <iostream>
using namespace std;
class Airplane {
    string model;
    string type;
    int CountPassanger;
    int MaxCountPassanger;
public:
    Airplane()
    {
        model = "None";
        type = "None";
        CountPassanger = 0;
        MaxCountPassanger = 0;
    }
    Airplane(string model, string type, int CountPassanger, int MaxCountPassanger)
    {
        this->model = model;
        this->type = type;
        this->CountPassanger = CountPassanger;
        this->MaxCountPassanger = MaxCountPassanger;
    }
    Airplane operator ()(int countP) {
        if ((countP >= 0) and (CountPassanger + countP) <= MaxCountPassanger)
        {
            CountPassanger += countP;
        }
        return*this;
    }


    friend bool operator ==(const Airplane& left, const Airplane& right);
    friend bool operator > (const Airplane& left, const Airplane& right);
    Airplane operator ++() {
        if ((CountPassanger + 1) <= MaxCountPassanger)
        {
            this->CountPassanger++;
        } 
        return *this;
    }
    Airplane operator --() {
        this->CountPassanger--;
        return *this;
    }
    int GetPassangers(){
        return CountPassanger;
    }
};
bool operator ==(const Airplane& left, const Airplane& right) {
    return (left.type == right.type);
}
bool operator > (const Airplane& left, const Airplane& right) {
    return (left.MaxCountPassanger > right.MaxCountPassanger);
}
int main()
{
    Airplane a1("Boeing 737", "Passenger", 100, 200);
    Airplane a2("Airbus A320", "Passenger", 150, 180);

    cout << (a1 == a2) << endl;
    cout << (a1 > a2) << endl;
    cout << "Passengers: " << a1.GetPassangers() << endl;
    ++a1;
    cout << "Passengers: " << a1.GetPassangers() << endl;

    --a1;
    cout << "Passengers: " << a1.GetPassangers() << endl;
    a1(20);
    cout << "Passengers: " << a1.GetPassangers() << endl;
}
