#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point();
	Point(int value);
	Point(int x, int y);
	void Print();
#pragma region Operators
	Point operator++();
	Point operator--();
	Point operator++(int);
	Point operator--(int);
	Point operator!();
	bool operator > (const Point& other);
	bool operator < (const Point& other);
#pragma endregion


};

