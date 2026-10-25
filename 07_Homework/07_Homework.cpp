#include <iostream>
using namespace std;
class Array {
    long* arr;
    int size;
public:
    Array() {
        arr = nullptr;
        size = 0;
    }
    Array(int size) {
        this->size = size;
        arr = new long[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(Array& arr) {
        this->size = arr.size;
        this->arr = new long[size];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr.arr[i];
        }
    }
    void InitMasive() {
        int choice;
        long num;
        cout << "Enter method to init masive:\n1.Random\n2.From keyboard\nYou choice[1-2]: "; cin >> choice;
        if (choice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % 50 + 1;
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Enter a " << i << "number: "; cin >> num;
                arr[i] = num;
            }
        }
    }
    void ShowMasive() {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void AddElementToMasive(long num) {
        int choice;
        cout << "Enter method to add element to masive:\n1.To end\n2.To start\n3.To index\nEnter your choice[1-3]: "; cin >> choice;
        if (choice == 1)
        {
            long* temp = new long[size + 1];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            temp[size] = num;
            delete[] arr;
            arr = temp;
            size++;
        }
        else if (choice == 2)
        {
            long* temp = new long[size + 1];
            for (int i = 0; i < size; i++)
            {
                temp[i + 1] = arr[i];
            }
            temp[0] = num;
            delete[] arr;
            arr = temp;
            size++;
        }
        else if (choice == 3)
        {
            int pos;
            cout << "Enter index to add element: "; cin >> pos;
            long* temp = new long[size + 1];
            for (int i = 0; i < pos; i++)
            {
                temp[i] = arr[i];
            }
            temp[pos] = num;
            for (int i = pos; i < size; i++)
            {
                temp[i + 1] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size++;
        }
        else {
            cout << "Wrong choice" << endl;
        }
    }
    void DelElementMasive() {
        int choice;
        int Value;
        cout << "Enter method to delete element masive:\n1.To Value\n2.To index\nEnter your choice[1-2]: "; cin >> choice;
        if (choice == 1)
        {
            bool find = false;
            cout << "Enter a value: "; cin >> Value;
            long* temp = new long[size - 1];
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == Value and find == false)
                {
                    find = true;
                    continue;
                }
                if (find == false)
                {
                    temp[i] = arr[i];
                }
                else if (find == true)
                {
                    temp[i - 1] = arr[i];
                }
            }
            if (find == true)
            {
                delete[] arr;
                arr = temp;
                size--;
            }
            else {
                delete[] temp;
                cout << "Value not found" << endl;
            }
        }
        else if (choice == 2)
        {
            int pos;
            cout << "Enter index to delete element: "; cin >> pos;
            if (pos >= size)
            {
                cout << "Wrong index" << endl;
                return;
            }
            else {
                long* temp = new long[size - 1];
                bool flag = false;
                for (int i = 0; i < size; i++)
                {
                    if (i == pos)
                    {
                        flag = true;
                        continue;
                    }
                    if (!flag)
                    {
                        temp[i] = arr[i];
                    }
                    else {
                        temp[i - 1] = arr[i];
                    }
                }
                delete[] arr;
                arr = temp;
                size--;
            }
        }
    }
    long GetMax() {
        long max = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        return max;
    }
    long GetMin() {
        long min = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        return min;
    }
    long GetAverage() {
        long sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum / size;
    }
    void BubbleSort()
    {
        int temp;
        int choice;
        cout << "Enter variant sort:\n1.Asc\n2.Desc\nEnter your choice[1-2]: "; cin >> choice;
        if (choice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = size - 1; j > i; j--)
                {
                    if (arr[j - 1] > arr[j]) {
                        temp = arr[j - 1];
                        arr[j - 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = size - 1; j > i; j--)
                {
                    if (arr[j - 1] < arr[j]) {
                        temp = arr[j - 1];
                        arr[j - 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }

    }
    void operator ()(int num) {
        for (int i = 0; i < size; i++)
        {
            arr[i] += num;
        }
    }
    long& operator [](short index) {
        if (index < 0 or index >= size)
        {
            return arr[0];
        }
        else {
            for (int i = 0; i < size; i++)
            {
                if (i == index)
                {
                    return arr[i];
                }
            }
        }
    }
    ~Array() {
        delete[] arr;
    }

};
int main()
{
    srand(time(0));
    Array arr(10);
    arr.InitMasive();
    //arr.AddElementToMasive(101);
    /*arr.ShowMasive();
    cout << endl;
    arr.ShowMasive();
    cout << endl;
    arr.BubbleSort();
    arr.DelElementMasive();
    arr.ShowMasive();*/
    /*cout << endl;
    cout << "Max: " << arr.GetMax() << endl;
    cout << "Min: " << arr.GetMin() << endl;
    cout << "Average: " << arr.GetAverage() << endl;*/
    arr.ShowMasive();
    cout << endl << endl;
    arr(10);
    arr.ShowMasive();
    cout << endl;
    cout << arr[5];
}