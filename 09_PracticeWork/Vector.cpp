#include "Vector.h"

Vector::Vector()
{
	points = nullptr;
	countPoint = 0;
}

Vector::Vector(int countPoint)
{
	this->countPoint = countPoint;
	points = new Point[countPoint];
}

Vector::Vector(const Vector& other)
{
	this->countPoint = other.countPoint;
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i];
	}
}

Vector& Vector::operator=(const Vector& other) {
	this->countPoint = other.countPoint;
	if (points != nullptr)
	{
		delete[] points;
	}
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i];
	}
	return *this;
}

Vector::Vector(Vector&& other)
{
	this->countPoint = other.countPoint;
	this->points = other.points;
	other.points = nullptr;
}

void Vector::PrintAll() {
	for (int i = 0; i < countPoint; i++)
	{
		points[i].Print();
		cout << endl;
	}
}

void Vector::Add(Point NewPoint) {
	Point* temp = new Point[countPoint + 1];
	for (int i = 0; i < countPoint; i++)
	{
		temp[i] = points[i];
	}
	temp[countPoint] = NewPoint;
	if (points != nullptr)
	{
		delete[]points;
	}
	points = temp;
	countPoint++;
}

Vector::~Vector()
{
	if (points != nullptr)
	{
		delete[] points;
	}
}
