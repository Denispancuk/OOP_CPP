#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
class Coord {
    int CoordX;
    int CoordY;
public:
    Coord()
    {
        CoordX = 0;
        CoordY = 0;
    }
    Coord(int x,int y)
    {
        CoordX = x;
        CoordY = y;
    }
    void SetPos(int x, int y)
    {
        COORD XYZ;
        XYZ.X = x;
        XYZ.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XYZ);
    }
    void SetCoordX(int CoordX) {
        this->CoordX = CoordX;
    };
    void SetCoordY(int CoordY) {
        this->CoordY = CoordY;
    };

    int GetCoordX(){
        return CoordX;
    }
    int GetCoordY(){
        return CoordY;
    }
};
class Rectanglee {
    int Width;
    int Height;
    char symbol;
    Coord XY;
public:
    Rectanglee()
    {
        Width = 0;
        Height = 0;
        symbol = '*';
    }
    Rectanglee(int Width)
    {
        if (Width < 0)
        {
            cout << "Enter a valid width!" << endl;
            return;
        }
        this->Width = Width;
        Height = Width;
        symbol = '*';
    }
    Rectanglee(int Width, int Height)
    {
        if (Width < 0 or Height < 0)
        {
            cout << "Enter a valid parameter!" << endl;
            return;
        }
        this->Width = Width;
        this->Height = Height;
        symbol = '*';
    }
    Rectanglee(int Width, int Height, char symbol)
    {
        if (Width < 0 or Height < 0)
        {
            cout << "Enter a valid parameter!" << endl;
            return;
        }
        this->Width = Width;
        this->Height = Height;
        this->symbol = symbol;
    }
    Rectanglee(int Width, int Height, char symbol, Coord Any)
    {
        if (Width < 0 or Height < 0 or Any.GetCoordX() < 0 or Any.GetCoordY() < 0)
        {
            cout << "Enter a valid parameter!" << endl;
            return;
        }
        this->Width = Width;
        this->Height = Height;
        this->symbol = symbol;
        XY = Any;
    }
    
    void ShowFigure() {
        for (int i = 0; i < Height; i++)
        {
            XY.SetPos(XY.GetCoordX(), XY.GetCoordY() + i);
            for (int j = 0; j < Width; j++)
            {
                cout << symbol << " ";
            }
           
        }
    }
    void ChangeSize(int Width, int Height) {
        if (Width < 0 or Height < 0)
        {
            cout << "Enter a valid parameter!" << endl;
            return;
        }
        this->Width = Width;
        this->Height = Height;
    }
    void ChangeCoord(int x, int y) {
        if (x < 0 or y < 0)
        {
            cout << "Enter a valid parameter!" << endl;
            return;
        }
        XY.SetCoordX(x);
        XY.SetCoordY(y);
    }

};


class Student
{
    string name;
    short age;
    int CountMarks;
    float AverageMark;
    short* Marks = new short[CountMarks];
    void SetAverageMark() {
        int sum = 0;
        for (int i = 0; i < CountMarks; i++)
        {
            sum += Marks[i];
        }
        AverageMark = sum / CountMarks;
    }
public:
    Student()
    {
        name = "No name";
        age = 0;
        CountMarks = 0;
        AverageMark = 0;
        Marks = nullptr;
    }
    Student(string name, short age):Student()
    {
        this->name = name;
        this->age = age;
    }
    void Print() {
        cout << "Name student: " << name << endl;
        cout << "Age student: " << age << endl;
        cout << "Count Rate: " << CountMarks << endl;
        cout << "Average Mark: " << AverageMark << endl;
        cout << "Marks: ";
        for (int i = 0; i < CountMarks; i++)
        {
            cout << Marks[i] << " | ";
        }
        cout << endl;
    }
    void AddMark(short mark) {
        short* temp = new short[CountMarks + 1];
        for (int i = 0; i < CountMarks; i++)
        {
            temp[i] = Marks[i];
        }
        temp[CountMarks] = mark;
        delete[] Marks;
        Marks = temp;
        CountMarks++;
        SetAverageMark();
    }
    void Save() {
        ofstream out("StudentsDatabase.txt", ios_base::app);
        out << name;
        out << ":";
        out << age;
        out << ":";
        out << CountMarks;
        out << ":";
        out << AverageMark;
        out << ":";
        for (int i = 0; i < CountMarks; i++)
        {
            out << Marks[i];
            out << ":";
        }
        out << "|";
        out.close();
    }
    void Load() {
        ifstream in("StudentsDatabase.txt", ios_base::in);

        string name;
        string age;
        string countmarks;
        string Average;
        string Mark;
        int i = 0;
        while (getline(in, name, ':')) {
            this->name = name;
            getline(in, age, ':');
            this->age = stoi(age);
            getline(in, countmarks, ':');
            this->CountMarks = stoi(countmarks);
            getline(in, Average, ':');
            this->AverageMark = stof(Average);
            delete[] Marks;
            Marks = new short[CountMarks];
            for (int i = 0; i < CountMarks; i++) {
                getline(in, Mark, ':');
                Marks[i] = stoi(Mark);
            }

            getline(in, Mark, '|');
            }
            in.close();
        }
    //Getter
    string GetName() {
        return name;
    }

    short GetAge() {
        return age;
    }

    int GetCountMarks() {
        return CountMarks;
    }

    float GetAverageMark() {
        return AverageMark;
    }
    ~Student(){
        delete[] Marks;
    }
};

int main()
{
    // First Task
    Rectanglee rectang(10,11,'&');
    rectang.ShowFigure();
    rectang.ChangeCoord(12, 12);
    rectang.ChangeSize(10, 17);
    rectang.ShowFigure();
    cout << endl;
    // Second Task
    Student student1("Ivan", 23);
    student1.AddMark(11);
    student1.AddMark(9);
    student1.Print();
    cout << endl;
    cout << "Name: " << student1.GetName() << endl;
    cout << "Age: " << student1.GetAge() << endl;
    cout << "Count Marks: " << student1.GetCountMarks() << endl;
    cout << "Average Mark: " << student1.GetAverageMark() << endl;
    student1.Save();
    student1.Load();

}