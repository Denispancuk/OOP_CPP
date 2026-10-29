#pragma once
#include "Point.h"
class Vector
{
	Point* points;
	int countPoint;
public:
	Vector();
	explicit Vector(int countPoint);
	Vector(const Vector& other);
	Vector& operator =(const Vector& other);
	Vector(Vector&& other);
	void PrintAll();
	void Add(Point NewPoint);
	~Vector();
};
