#include <iostream>
using namespace std;

template<typename T>
class List {
    struct Node {
        T value;
        Node* next;
        Node(T value, Node* next) :value(value), next(next) {}
        Node(T value) :value(value), next(nullptr) {}
    };
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value) {
        Node* newNode = new Node(value, head);
        /*newNode->value = value;
        newNode->next = head;*/
        head = newNode;
    }
    void Print() {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    void AddToTail(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

    }
    void DeleteFromTail() {
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void DeleteHead() {
        Node* current = head;
        if (head == nullptr)return;
        else {
            head = current->next;
            delete current;
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
    List<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.Print();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.DeleteHead();
    l.DeleteHead();
    l.Print();
}
