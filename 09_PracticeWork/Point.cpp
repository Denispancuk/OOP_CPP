#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int value)
{
	x = y = value;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::Print() {
	cout << '[' << x << ';' << y << ']' << endl;
}

Point Point::operator++() {
	x++;
	y++;
	return *this;
}

Point Point::operator--() {
	x--;
	y--;
	return *this;
}

Point Point::operator++(int) {
	x++;
	y++;
	return *this;
}

Point Point::operator--(int) {
	x--;
	y--;
	return *this;
}

Point Point::operator!() {
	x = -x;
	y = -y;
	return*this;
}

bool Point::operator>(const Point& other) {
	return ((this->x + this->y) > (other.x + other.y));

}
bool Point::operator < (const Point& other) {
	return !(*this > other);
}
