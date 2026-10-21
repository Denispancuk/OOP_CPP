#include <iostream>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    void SetDate(int day) {
        this->day = day;
    }
    void Print()const {
        cout << "Date: " << day << '/' << month << '/' << year << endl;
    }
    int getDay() {
        day += 10;
        return day;
    }
    int getDay()const {
        return day;
    }
};
class Account {
private:
    double sum;
    const double rate;
public:
    Account(double sum, double rate):rate(rate)
    {
        this->sum = sum;
    }
    double GetRate()const {
        return rate;
    }
    double GetSum()const {
        return sum;
    }
    double GetIncome()const {
        return sum*rate/100;
    }
    double setSum() {
        sum += GetIncome();
        return sum;
    }
};

class Array {
    int* arr;
    int size;
public:
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }
    ~Array(){
        if (arr != nullptr)
        {
            delete[] arr;
        }
        
    }
    int getSize()const {
        return size;
    }
    int getValue(int index) {
        return arr[index];
    }
    void setValue(int num, int index) {
        arr[index] = num;
    }
    void display(int index)const {
        cout << arr[index] << " ";
    }
};

void PrintArray(const Array& arr) {
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
}
void Print(string name) {

}
int main()
{
    int size = 4;
    Array arr(size);
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.setValue(size - i, i);
    }
    PrintArray(arr);
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    /*PrintArray(8);*/
    //Account account1(2000, 5);
    //const Account account2(5000, 8);
    //cout << account1.GetRate() << endl;
    //cout << account2.GetRate() << endl;

    //cout << account1.GetSum() << endl;
    //cout << account2.GetSum() << endl;

    //cout << account1.GetIncome() << endl;
    //cout << account2.GetIncome() << endl;

    //cout << account1.setSum() << endl;
    //cout << account2.setSum() << endl;


    //const int size = 5;
    //const int months[3]{ 31,31,28 };
    //

    //Date HolidaysDate{ 25,10,2026 };
    //HolidaysDate.Print();
    //HolidaysDate.day = 31;
    //HolidaysDate.Print();

    //const Date independencyDay{ 24,8,2027 };
    //
    ///*independencyDay.Print();
    //independencyDay.day = 25;
    //independencyDay.Print();*/

}
