#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Vagon {
    int NumberVagon;
    short CountPlace;
    short CountPassanger;

    void ShowVagon() {
        cout << "Number Vagon: " << NumberVagon << endl;
        cout << "Count Place: " << CountPlace << endl;
        cout << "Count Passanger: " << CountPassanger << endl << endl;
    }
    void Add1Passanger() {
        CountPassanger++;
    }
    //setter
    void SetNumberVagon() {
        int NumberVagon;
        cout << "Enter number vagon: "; cin >> NumberVagon;
        this->NumberVagon = NumberVagon;
    }
    void SetCountPlace() {
        short CountPlace;
        cout << "Enter Count Place: "; cin >> CountPlace;
        this->CountPlace = CountPlace;
    }
    void SetCountPassanger() {
        short CountPassanger;
        cout << "Enter Count Passanger: "; cin >> CountPassanger;
        this->CountPassanger = CountPassanger;
    }

    void SetNumberVagon2(int NumberVagon) {
        this->NumberVagon = NumberVagon;
    }
    void SetCountPlace2(short CountPlace) {
        this->CountPlace = CountPlace;
    }
    void SetCountPassanger2(short CountPassanger) {
        this->CountPassanger = CountPassanger;
    }
};
class Train {
    int SizeVagons;
    Vagon* vagon;
public:
    Train()
    {
        SizeVagons = 0;
        vagon = nullptr;
    }
    Train(int SizeVagons)
    {
        this->SizeVagons = SizeVagons;
        if (SizeVagons > 0) {
            vagon = new Vagon[SizeVagons];
        }
        else {
            vagon = nullptr;
        }
    }
    Train(int SizeVagons, Vagon* vagon)
    {
        this->SizeVagons = SizeVagons;
        this->vagon = vagon;

    }
    Train(Train & vagon)
    {
        this->SizeVagons = vagon.SizeVagons;
        this->vagon = new Vagon[SizeVagons];
        for (int i = 0; i < SizeVagons; i++)
        {
            this->vagon[i] = vagon.vagon[i];
        }
    }
    void Show() {
        for (int i = 0; i < SizeVagons; i++)
        {
            vagon[i].ShowVagon();
        }
    }
    void Add1People(int pos) {
        vagon[pos - 1].Add1Passanger();
    }
    void InitAll() {
        for (int i = 0; i < SizeVagons; i++)
        {
            vagon[i].SetNumberVagon();
            vagon[i].SetCountPlace();
            vagon[i].SetCountPassanger();
        }
    }
    void AddVagon() {
        Vagon* temp = new Vagon[SizeVagons + 1];
            for (int i = 0; i < SizeVagons; i++)
            {
                temp[i] = vagon[i];
            }
            temp[SizeVagons].SetNumberVagon();
            temp[SizeVagons].SetCountPlace();
            temp[SizeVagons].SetCountPassanger();
            delete[] vagon;
            vagon = temp;
            SizeVagons++;

    }
    void Save() {
        ofstream out("VagonsDatabase.txt");
        out << SizeVagons;
        out << ':';
        for (int i = 0; i < SizeVagons; i++)
        {
            out << vagon[i].NumberVagon;
            out << ":";
            out << vagon[i].CountPlace;
            out << ":";
            out << vagon[i].CountPassanger;
            out << ":";
        }
        out << "|";
        
    }
    void Load() {
        ifstream in("VagonsDatabase.txt", ios_base::in);
        string CountVagons;
        string NumberVagon;
        string CountPlace;
        string CountPassanger;
        if (getline(in, CountVagons, ':')) {
            delete[] vagon;  
            SizeVagons = stoi(CountVagons);
            vagon = new Vagon[stoi(CountVagons)];
            for (int i = 0; i < stoi(CountVagons); i++)
            {
                getline(in, NumberVagon, ':');
                vagon[i].SetNumberVagon2(stoi(NumberVagon));
                getline(in, CountPlace, ':');
                vagon[i].SetCountPlace2(stoi(CountPlace));
                getline(in, CountPassanger, ':');
                vagon[i].SetCountPassanger2(stoi(CountPassanger));
            }
            getline(in, CountPassanger, '|');
        }
        in.close();
    }
    ~Train(){
        delete[] vagon;
    }
};
int main()
{
    Train train(2);
    train.InitAll();
    train.Add1People(2);
    train.AddVagon();
    train.Show();
    Train train2(train);
    cout << endl;
    train2.Show();
    train.Save();
    train.Load();
}
