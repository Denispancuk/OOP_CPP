#include <iostream>
#include <initializer_list>
using namespace std;

template<typename T>
class Array
{
    T* arr;
    int size;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    explicit Array(int size)
    {
        this->size = size;
        arr = new T[size]{};
    }

    Array(initializer_list<T> list)
    {
        this->size = list.size();
        arr = new T[size];

        int i = 0;
        for (T elem : list)
        {
            arr[i] = elem;
            i++;
        }
    }


    void Fill(initializer_list<T> list);
    void Print();
    T GetMax();
    T GetMin();
    void BubbleSort();
    int BinarySearch(T key);
    void Change(int index, T NewEl);

    ~Array()
    {
        delete[] arr;
    }
};

int main()
{
    

    Array<int> arr2({ 521, 7, 8, 101, 6, 2, 12, 8, 23, 88, 99, 1111});
    Array<string> arr3({"hello","world","phon"});
    arr3.BubbleSort();
    arr2.Print();
    cout << "Max: " << arr2.GetMax() << endl;
    cout << "Min: " << arr2.GetMin() << endl;
    cout << endl;
    arr2.BubbleSort();
    arr2.Print();
    cout << arr2.BinarySearch(23) << endl;
    cout << arr3.BinarySearch("world") << endl;
    arr2.Change(0, 1212);
    arr2.Print();

}

template<typename T>
inline void Array<T>::Fill(initializer_list<T> list)
{
    if (arr != nullptr)
        delete[] arr;

    size = list.size();
    arr = new T[size];

    int i = 0;
    for (T elem : list)
    {
        arr[i] = elem;
        i++;
    }
}

template<typename T>
inline void Array<T>::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
inline T Array<T>::GetMax()
{
    T max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

template<typename T>
inline T Array<T>::GetMin()
{
    T min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

template<typename T>
inline void Array<T>::BubbleSort()
{
    T temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<typename T>
inline int Array<T>::BinarySearch(T key)
{
    int B = 0, E = size - 1;
    while (true)
    {
        int p = (B + E) / 2;
        if (key > arr[p])
        {
            B = p + 1;
        }
        else if (key < arr[p])
        {
            E = p - 1;
        }
        else if (key == arr[p])
            return p;
        if (B > E) return -1;
    }
}

template<typename T>
inline void Array<T>::Change(int index, T NewEl) {
    if (index >= 0 and index < size)
    {
        arr[index] = NewEl;
    }
}
