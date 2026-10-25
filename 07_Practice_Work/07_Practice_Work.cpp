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
        if ((countP >= 0) or (CountPassanger + countP) <= MaxCountPassanger)
        {
            CountPassanger += countP;
        }
    }




    friend bool operator ==(const Airplane& left, const Airplane& right);
    friend bool operator > (const Airplane& left, const Airplane& right);
};
bool operator ==(const Airplane& left, const Airplane& right) {
    return (left.type == right.type);
}
bool operator > (const Airplane& left, const Airplane& right) {
    return (left.MaxCountPassanger > right.MaxCountPassanger);
}
int main()
{
    
}
