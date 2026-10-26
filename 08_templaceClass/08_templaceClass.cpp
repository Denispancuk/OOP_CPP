#include <iostream>
using namespace std;
int GetMax(int arr[], int size) {
    int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
//class Point{};
//template<typename T_coll, typename T_value>
//class MyClass {
//	T_coll* collection;
//	int size;
//	T_value value;
//public:
//	MyClass()
//	{
//		collection = nullptr;
//		size = 0;
//	}
//	MyClass(T_coll* collection, T_value value):collection(collection),value(value)
//	{
//
//	}
//	void SetCollection(int* coll) {
//		collection = coll;
//	}
//	void SetValue(T_value value) {
//		this->value = value;
//	}
//	void Print() {
//		for (int i = 0; i < size; i++)
//		{
//			cout << collection[i] << " ";
//		}
//		cout << endl;
//		cout << value;
//	}
//	~MyClass()
//	{
//		if (collection != nullptr)
//		{
//			delete[]collection;
//		}
//	}
//
//};
//template<typename T_coord>
//class Point {
//	T_coord x;
//	T_coord y;
//public:
//#pragma region Constructors
//	Point()
//	{
//		x = y = 0;
//	}
//	Point(T_coord value)
//	{
//		x = y = value;
//	}
//	Point(T_coord x, T_coord y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//#pragma endregion
//	void Print()const
//	{
//		cout << "X : " << x << ". Y : " << y << endl;
//	}
//	void SetNewCoords(int newX, int newY) {
//		this->x = newX;
//		this->y = newY;
//	}
//};


int main()
{
	/*const int size = 3;
	int arr[size] = { 1,2,3 };
	cout << "Max: " << GetMax(arr,size);*/

	/*long* long_arr = new long[5];
	for (int i = 0; i < 5; i++)
	{
		long_arr[i] = i + 1;
		cout << long_arr[i] << " ";
	}
	cout << endl;
	char* char_arr = new char[5];
	for (int i = 0; i < 5; i++)
	{
		char_arr[i] = 'a' + i;
		cout << char_arr[i] << " ";
	}
	cout << endl; 

	MyClass<long,string> cl1(long_arr, "Class with long arr");
	MyClass<char,string> cl2(char_arr, "Class with char arr");*/

}
