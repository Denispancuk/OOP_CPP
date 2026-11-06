#include <iostream>
using namespace std;
template<typename T>
class List {
    struct Node {
        Node* prev;
        T value;
        Node* next;
        Node() :prev(nullptr), value(0), next(nullptr) {}
        Node(Node* p, T v, Node* n) :prev(p), value(v), next(n) {}

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

    void AddToHead(T value) {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }
    void DeleteFromHead() {}
    void AddToTail(T value)
    {

        Node* newNode = new Node(tail, value, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

    }
    void DeleteFromTail() {
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
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value;
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

class Train {
public:
    struct Vagon {
        int NumberVagon;
        int CountOfPlaces;
        int CountOfPassanger;
        friend ostream& operator << (ostream& out, const Vagon& vagon)
        {
            out << "Number Vagon: " << vagon.NumberVagon << "\nCount Of Places: " << vagon.CountOfPlaces << "\nCount Of Passanger: " << vagon.CountOfPassanger << endl << endl;
            return out;
        }
    };
private:
    string model;
    List<Vagon> vagons;
    int countVagons;
public:
    Train():model("None"), countVagons(0){}
    Train(string model,int countVagons = 0):model(model), countVagons(countVagons){}
    void Show() {
        for (int i = 0; i < countVagons; i++)
        {
            vagons.Print();
        }
    }
    void AddVagonToHead(const Vagon& vagon) {
        vagons.AddToHead(vagon);
        countVagons++;
    }
    void AddVagonToTail(const Vagon& vagon) {
        vagons.AddToTail(vagon);
        countVagons++;
    }
    void DeleteVagonToTail() {
        vagons.DeleteFromTail();
        if (countVagons > 0) countVagons--;
    }

};
int main()
{
    Train myTrain("Intercity+");

    // Виправлено: тип вказано як Train::Vagon
    Train::Vagon v1;
    v1.NumberVagon = 1;
    v1.CountOfPlaces = 60;
    v1.CountOfPassanger = 45;

    // Виправлено: тип вказано як Train::Vagon
    Train::Vagon v2 = { 2, 50, 50 };

    // Додавання вагонів до поїзда
    myTrain.AddVagonToTail(v1);
    myTrain.AddVagonToTail(v2);

    // Перевірка виводу
    myTrain.Show();

    return 0;
}