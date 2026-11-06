#include <iostream>
using namespace std;
template<typename T>
class List {
    struct Node {
        Node* prev;
        T value;
        Node* next;
        Node():prev(nullptr),value(0), next(nullptr){}
        Node(Node * p, T v, Node * n):prev(p),value(v), next(n){}

    };
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = tail = nullptr;
    }
    bool IsEmpty() {
        return (head == nullptr and tail == nullptr);
    }

    void AddToHead(T value){
        Node* newNode = new Node(nullptr,value, head);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }
    void DeleteFromHead(){}
    void AddToTail(T value)
    {

        Node* newNode = new Node(tail, value, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;

    }
    void DeleteFromTail(){
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        
    }
    void Print() {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << current->value << " ";
        }
    }
    ~List() {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
};
int main()
{
    /*List<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.Print();*/

}