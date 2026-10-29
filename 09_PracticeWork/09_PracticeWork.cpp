#include "Point.h"
#include "Vector.h"
void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main()
{
    Point p1(2, 3);
    Point p2(5, 5);

    SetPos(1, 1);
    p1.Print();

    SetPos(1, 2);
    (++p1).Print();

    SetPos(1, 3);
    (p1++).Print();

    SetPos(1, 4);
    (--p1).Print();

    SetPos(1, 5);
    (!p1).Print();

    SetPos(10, 1);
    cout << (p1 > p2) << endl;

    SetPos(10, 2);
    cout << (p1 < p2) << endl;

    Vector v1;
    v1.Add(p1);
    v1.Add(p2);

    SetPos(20, 1);
    v1.PrintAll();

    Vector v2(v1);

    SetPos(30, 1);
    v2.PrintAll();

    Vector v3;
    v3 = v1;

    SetPos(40, 1);
    v3.PrintAll();
}