
#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
    int* marks;
    int countMarks;
public:
    Student()
    {
        this->name = "No name";
        this->age = 0;
        this->marks = nullptr;
        this->countMarks = 0;

    }
    Student(string name, int age)
    {
        this->name = "No name";
        this->age = 0;
    }
    Student(const Student &other)
    {
        this->name = other.name;
        this->age = other.age;
        this->marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++)
        {
            this->marks[i] = other.marks[i];
        }
        this->countMarks = other.countMarks;
    }
    void AddMark(int mark) {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        if (marks != nullptr)
        {
            delete[] marks;
        }
        marks = temp;
        countMarks++;
    }
    void Print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Count Marks: " << countMarks << endl;
        cout << "Marks: " << countMarks;
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }
    }
    ~Student() {
            delete[] marks;
    }
};
int main()
{
    Student st;

    Student student("Ivan", 18);
    student.Print();

    Student copy = Student(student);
}
