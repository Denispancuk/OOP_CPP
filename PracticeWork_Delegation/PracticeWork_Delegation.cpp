#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PIB {
    string FirstName;
    string LastName;
    string MiddleName;
public:
    string GetFirstName()const {
        return FirstName;
    }
    string GetLastName()const {
        return LastName;
    }
    string GetMiddleName()const {
        return MiddleName;
    }

    void SetFirstName(string FirstName) {
        this->FirstName = FirstName;
    }
    void SetLastName(string LastName) {
        this->LastName = LastName;
    }
    void SetMiddleName(string MiddleName) {
        this->MiddleName = MiddleName;
    }
    void Init() {
        string FirstName;
        string LastName;
        string MiddleName;
        cout << "Enter a first name: "; cin >> FirstName;
        this->FirstName = FirstName;
        cout << "Enter a last name: "; cin >> LastName;
        this->LastName = LastName;
        cout << "Enter a Middle name: "; cin >> MiddleName;
        this->MiddleName = MiddleName;
    }
};
class Abonent {
    PIB PIB_Abonent;
    long long HomeTelephone;
    long long WorkTelephone;
    long long MobileTelephone;
    string AnyInformation;
public:
    static int CountAbonent;
    Abonent()
    {
        CountAbonent++;
        PIB_Abonent.SetFirstName("None");
        PIB_Abonent.SetLastName("None");
        PIB_Abonent.SetMiddleName("None");
        HomeTelephone = 0;
        WorkTelephone = 0;
        MobileTelephone = 0;
        AnyInformation = "None";
    }
    explicit Abonent(PIB Name) :Abonent()
    {

        PIB_Abonent.SetFirstName(Name.GetFirstName());
        PIB_Abonent.SetLastName(Name.GetLastName());
        PIB_Abonent.SetMiddleName(Name.GetMiddleName());
    }
    Abonent(PIB Name, long long HomeTelephone, long long WorkTelephone, long long MobileTelephone) :Abonent(Name)
    {

        this->HomeTelephone = HomeTelephone;
        this->WorkTelephone = WorkTelephone;
        this->MobileTelephone = MobileTelephone;
    }
    Abonent(PIB Name, long long HomeTelephone, long long WorkTelephone, long long MobileTelephone, string AnyInformation) :Abonent(Name, HomeTelephone, WorkTelephone, MobileTelephone)
    {

        this->AnyInformation = AnyInformation;
    }

    PIB GetPIB() const {
        return PIB_Abonent;
    }
    long long GetHomeTelephone() const {
        return HomeTelephone;
    }
    long long GetWorkTelephone() const {
        return WorkTelephone;
    }
    long long GetMobileTelephone() const {
        return MobileTelephone;
    }
    string GetAnyInformation() const {
        return AnyInformation;
    }
    static int GetCountAbonents() {
        return CountAbonent;
    }
    void SetPIB(string FirstName, string LastName, string MiddleName) {
        PIB_Abonent.SetFirstName(FirstName);
        PIB_Abonent.SetLastName(LastName);
        PIB_Abonent.SetMiddleName(MiddleName);
    }
    void SetHomeTelephone(long long HomeTelephone) {
        this->HomeTelephone = HomeTelephone;
    }
    void SetWorkTelephone(long long WorkTelephone) {
        this->WorkTelephone = WorkTelephone;
    }
    void SetMobileTelephone(long long MobileTelephone) {
        this->MobileTelephone = MobileTelephone;
    }
    void SetAnyInformation(string AnyInformation) {
        this->AnyInformation = AnyInformation;
    }
    void PrintAbonent()const {
        cout << endl;
        cout << "PIB: " << PIB_Abonent.GetFirstName() << "  " << PIB_Abonent.GetLastName() << " " << PIB_Abonent.GetMiddleName() << endl;
        cout << "Home Telephone: " << HomeTelephone << endl;
        cout << "Work Telephone: " << WorkTelephone << endl;
        cout << "Mobile Telephone: " << MobileTelephone << endl;
        cout << "Any information: " << AnyInformation << endl;
    }
    void Init() {
        long long HomeTelephone;
        long long WorkTelephone;
        long long MobileTelephone;
        string AnyInformation;
        PIB_Abonent.Init();
        cout << "Enter a Home Telephone (No +): "; cin >> HomeTelephone;
        this->HomeTelephone = HomeTelephone;
        cout << "Enter a Work Telephone (No +): "; cin >> WorkTelephone;
        this->WorkTelephone = WorkTelephone;
        cout << "Enter a Mobile Telephone (No +): "; cin >> MobileTelephone;
        this->MobileTelephone = MobileTelephone;
        cout << "Enter any information about abonent: "; cin >> AnyInformation;
        this->AnyInformation = AnyInformation;
    }

};
class PhoneBook {
    int Count;
    Abonent* abonents;

public:
    PhoneBook()
    {
        Count = 0;
        abonents = nullptr;
    }
    explicit PhoneBook(int Count) :PhoneBook()
    {
        this->Count = Count;
        abonents = new Abonent[Count];
    }
    PhoneBook(int Count, Abonent* abonents) :PhoneBook(Count)
    {
        for (int i = 0; i < Count; i++) {
            this->abonents[i] = abonents[i];
        }
    }
    void Add(Abonent a) {
        Abonent* temp = new Abonent[Count + 1];
        for (int i = 0; i < Count; i++)
        {
            temp[i] = abonents[i];
        }
        temp[Count] = a;
        delete[]abonents;
        abonents = temp;
        Count++;
    }

    void Delete(long long Phone) {
        Abonent* temp = new Abonent[Count - 1];
        bool find = false;
        for (int i = 0; i < Count; i++)
        {
            if ((abonents[i].GetMobileTelephone() == Phone or abonents[i].GetHomeTelephone() == Phone or abonents[i].GetWorkTelephone() == Phone) and !find)
            {
                find = true;
                continue;
            }
            if (find == false)
            {
                temp[i] = abonents[i];
            }
            else {
                temp[i - 1] = abonents[i];
            }
        }
        if (find)
        {
            delete[] abonents;
            abonents = temp;
            Count--;
        }
        else {
            delete[] temp;
        }
    }
    void SearchByName(string name) {
        bool find = false;
        for (int i = 0; i < Count; i++)
        {
            if (abonents[i].GetPIB().GetFirstName() == name)
            {
                abonents[i].PrintAbonent();
                find = true;
                break;
            }
        }
        if (!find)
        {
            cout << "Not found abonent!" << endl;
        }
    }
    void SearchByPhone(long long Phone) {
        bool find = false;
        for (int i = 0; i < Count; i++)
        {
            if (abonents[i].GetMobileTelephone() == Phone or abonents[i].GetHomeTelephone() == Phone or abonents[i].GetWorkTelephone() == Phone)
            {
                abonents[i].PrintAbonent();
                find = true;
                break;
            }
        }
        if (!find)
        {
            cout << "Not found abonent!" << endl;
        }
    }
    void ShowAll() {
        for (int i = 0; i < Count; i++)
        {
            abonents[i].PrintAbonent();
        }
    }
    void Save() {
        ofstream out("AbonentsDatabase.txt");
        out << Count;
        out << ':';
        out << Abonent::GetCountAbonents();
        out << ':';
        for (int i = 0; i < Count; i++)
        {
            out << abonents[i].GetPIB().GetFirstName();
            out << ":";
            out << abonents[i].GetPIB().GetLastName();
            out << ":";
            out << abonents[i].GetPIB().GetMiddleName();
            out << ":";
            out << abonents[i].GetHomeTelephone();
            out << ":";
            out << abonents[i].GetWorkTelephone();
            out << ":";
            out << abonents[i].GetMobileTelephone();
            out << ":";
            out << abonents[i].GetAnyInformation();
            out << ":";
        }
        out << "|";
    }
    void Load() {
        ifstream in("AbonentsDatabase.txt", ios_base::in);
        string Count;
        string CountAbonents;
        string FirstName;
        string LastName;
        string MiddleName;
        string HomeTelephone;
        string WorkTelephone;
        string MobileTelephone;
        string AnyInformation;
        if (getline(in, Count, ':')) {
            delete[] abonents;
            this->Count = stoi(Count);
            abonents = new Abonent[this->Count];
            getline(in, CountAbonents, ':');
            abonents->CountAbonent = stoi(CountAbonents);
            for (int i = 0; i < this->Count; i++)
            {
                getline(in, FirstName, ':');
                getline(in, LastName, ':');
                getline(in, MiddleName, ':');
                abonents[i].SetPIB(FirstName, LastName, MiddleName);
                getline(in, HomeTelephone, ':');
                abonents[i].SetHomeTelephone(stoll(HomeTelephone));
                getline(in, WorkTelephone, ':');
                abonents[i].SetWorkTelephone(stoll(WorkTelephone));
                getline(in, MobileTelephone, ':');
                abonents[i].SetMobileTelephone(stoll(MobileTelephone));
                getline(in, AnyInformation, ':');
                abonents[i].SetAnyInformation(AnyInformation);

            }
            getline(in, AnyInformation, '|');
        }
        in.close();
    }
    ~PhoneBook()
    {
        delete[] abonents;
    }

};
int Abonent::CountAbonent = 0;

int main()
{
    Abonent a;

    a.SetPIB("Ivan", "Petrenko", "Igorovich");
    a.SetHomeTelephone(123456);
    a.SetWorkTelephone(654321);
    a.SetMobileTelephone(987654);
    a.SetAnyInformation("Friend");

    cout << a.GetPIB().GetFirstName() << endl;
    cout << a.GetPIB().GetLastName() << endl;
    cout << a.GetPIB().GetMiddleName() << endl;
    cout << a.GetHomeTelephone() << endl;
    cout << a.GetWorkTelephone() << endl;
    cout << a.GetMobileTelephone() << endl;
    cout << a.GetAnyInformation() << endl;
    cout << Abonent::GetCountAbonents() << endl;

    a.PrintAbonent();

    Abonent b(a.GetPIB());

    Abonent c(a.GetPIB(), 111, 222, 333);

    Abonent d(a.GetPIB(), 444, 555, 666, "Colleague");

    b.PrintAbonent();
    c.PrintAbonent();
    d.PrintAbonent();

    Abonent e;
    e.Init();

    PhoneBook book;

    book.Add(a);
    book.Add(b);
    book.Add(c);
    book.Add(d);

    book.ShowAll();

    book.SearchByName("Ivan");
    book.SearchByPhone(987654);

    book.Save();

    PhoneBook book2;
    book2.Load();

    book2.ShowAll();

    book.Delete(987654);

    book.ShowAll();

}
