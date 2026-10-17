#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Point {
    int X;
    int Y;
    int Z;
public:
    void InitPoints() {
        cout << "Enter X: "; cin >> X;
        cout << "Enter Y: "; cin >> Y;
        cout << "Enter Z: "; cin >> Z;
    }
    void ShowPoints() {
        cout << "X: " << X << endl;
        cout << "Y: " << Y << endl;
        cout << "Z: " << Z << endl;
    }
    //setter
    void SetX(int X) {
        this->X = X;
    }
    void SetY(int Y) {
        this->Y = Y;
    }
    void SetZ(int Z) {
        this->Z= Z;
    }
    //getter
    int GetX(int X) {
        return X;
    }
    int GetY(int Y) {
        return Y;
    }
    int GetZ(int Z) {
        return Z;
    }
};

class FML {
    string FirstName;
    string LastName;
    string MiddleName;
public:
    void InitData() {
        cout << "Enter First Name: "; cin >> FirstName;
        cout << "Enter Last Name: "; cin >> LastName;
        cout << "Enter Middle Name: "; cin >> MiddleName;
    }
    void ShowAllName() {
        cout << "First name: " << FirstName << endl;
        cout << "Last name: " << LastName << endl;
        cout << "Middle name: " << MiddleName << endl;
    }
    //setter
    void SetFirstName(string FirstName) {
        this->FirstName = FirstName;
    }
    void SetLastName(string LastName) {
        this->LastName = LastName;
    }
    void SetMiddleName(string MiddleName) {
        this->MiddleName = MiddleName;
    }
    //getter
    string GetFirstName() {
        return FirstName;
    }
    string GetLastName() {
        return LastName;
    }
    string GetMiddleName() {
        return MiddleName;
    }
};

class BirthdayData {
    short Day;
    short Month;
    short Year;
public:
    void InitBirthday() {
        cout << "Enter Day: "; cin >> Day;
        cout << "Enter Month: "; cin >> Month;
        cout << "Enter Year: "; cin >> Year;
    }
    void ShowBirthday() {
        cout << "Birthday data: " << Day << '/' << Month << '/' << Year << endl;
    }
    //setter
    void SetDay(short Day) {
        this->Day = Day;
    }
    void SetMonth(short Month) {
        this->Month = Month;
    }
    void SetYear(short Year) {
        this->Year = Year;
    }
    //Getter
    short GetBirthdayDay() {
        return Day;
    }
    short GetBirthdayMonth() {
        return Month;
    }
    short GetBirthdayYear() {
        return Year;
    }
};

class Student {
    FML fml;
    BirthdayData Birthday;
    long long ContactTelephone;
    string City;
    string Country;
    string NameEducationInstitution;
    string CityEducationInstitution;
    string CountryEducationInstitution;
    short NumberGroup;
public:
    void InitAll() {
        fml.InitData();
        Birthday.InitBirthday();
        cout << "Enter Contact Telephone(no +): "; cin >> ContactTelephone;
        cout << "Enter City: "; cin >> City;
        cout << "Enter Country: "; cin >> Country;
        cout << "Enter Name Education Institution: "; cin >> NameEducationInstitution;
        cout << "Enter City Education Institution: "; cin >> CityEducationInstitution;
        cout << "Enter Country Education Institution: "; cin >> CountryEducationInstitution;
        cout << "Enter Number Group: "; cin >> NumberGroup;

    }
    void ShowALL() {
        fml.ShowAllName();
        Birthday.ShowBirthday();
        cout << "Contact Telephone: " << ContactTelephone << endl;
        cout << "City: " << City << endl;
        cout << "Country: " << Country << endl;
        cout << "Name Education Institution: " << NameEducationInstitution << endl;
        cout << "City Education Institution: " << CityEducationInstitution << endl;
        cout << "Country Education Institution: " << CountryEducationInstitution << endl;
        cout << "Number Group: " << NumberGroup << endl;
    }
    //setter
    void SetFML(string FirstName, string LastName, string MiddleName) {
        fml.SetFirstName(FirstName);
        fml.SetLastName(LastName);
        fml.SetMiddleName(MiddleName);
    }
    void SetBirthdayData(short day, short month, short year) {
        Birthday.SetDay(day);
        Birthday.SetMonth(month);
        Birthday.SetYear(year);
    }
    void SetContactTelephone(long long ContactTelephone) {
        this->ContactTelephone = ContactTelephone;
    }
    void SetCity(string City) {
        this->City = City;
    }
    void SetCountry(string Country) {
        this->Country = Country;
    }
    void SetNameEducationInstitution(string NameEducationInstitution) {
        this->NameEducationInstitution = NameEducationInstitution;
    }
    void SetCityEducationInstitution(string CityEducationInstitution) {
        this->CityEducationInstitution = CityEducationInstitution;
    }
    void SetCountryEducationInstitution(string CountryEducationInstitution) {
        this->CountryEducationInstitution = CountryEducationInstitution;
    }
    void SetNumberGroup(short NumberGroup) {
        this->NumberGroup = NumberGroup;
    }
    //Getter
    void GetFML() {
        cout << "First Name: " << fml.GetFirstName() << endl;
        cout << "Last Name: " << fml.GetLastName() << endl;
        cout << "Middle Name: " << fml.GetMiddleName() << endl;
    }
    void GetBirthdayData() {
        cout << "Birthday day: " << Birthday.GetBirthdayDay() << endl;
        cout << "Birthday month: " << Birthday.GetBirthdayMonth() << endl;
        cout << "Birthday Year: " << Birthday.GetBirthdayYear() << endl;
    }
    long long GetContactTelephone() {
        return ContactTelephone;
    }
    string GetCity() {
        return City;
    }
    string GetCountry() {
        return Country;
    }
    string GetNameEducationInstitution() {
        return NameEducationInstitution;
    }
    string GetCityEducationInstitution() {
        return CityEducationInstitution;
    }
    string GetCountryEducationInstitution() {
        return CountryEducationInstitution;
    }
    short GetNumberGroup() {
        return NumberGroup;
    }
    void SaveToFile()
    {
        ofstream out("StudentsDatabase.txt", ios_base::app);
        out << fml.GetFirstName();
        out << ":";
        out << fml.GetLastName();
        out << ":";
        out << fml.GetMiddleName();
        out << ":";
        out << Birthday.GetBirthdayDay();
        out << ":";
        out << Birthday.GetBirthdayMonth();
        out << ":";
        out << Birthday.GetBirthdayYear();
        out << ":";
        out << GetContactTelephone();
        out << ":";
        out << GetCity();
        out << ":";
        out << GetCountry();
        out << ":";
        out << GetNameEducationInstitution();
        out << ":";
        out << GetCityEducationInstitution();
        out << ":";
        out << GetCountryEducationInstitution();
        out << ":";
        out << GetNumberGroup();
        out << "|";
        out.close();
    }
    void ReadFromFile() {
        ifstream in("StudentsDatabase.txt", ios_base::in);
        

            string firstName, lastName, middleName;
            string day, month, year;
            string telephone, city, country;
            string eduName, eduCity, eduCountry, groupNumber;
            while (getline(in, firstName, ':')) {
            fml.SetFirstName(firstName);
            getline(in, lastName, ':');
            fml.SetLastName(lastName);
            getline(in, middleName, ':');
            fml.SetMiddleName(middleName);
            getline(in, day, ':');
            Birthday.SetDay(stoi(day));
            getline(in, month, ':');
            Birthday.SetMonth(stoi(month));
            getline(in, year, ':');
            Birthday.SetYear(stoi(year));
            getline(in, telephone, ':');
            this->ContactTelephone = stoll(telephone);
            getline(in, city, ':');
            this->City = city;
            getline(in, country, ':');
            this->Country = country;
            getline(in, eduName, ':');
            this->NameEducationInstitution = eduName;
            getline(in, eduCity, ':');
            this->CityEducationInstitution = eduCity;
            getline(in, eduCountry, ':');
            this->CountryEducationInstitution = eduCountry;
            getline(in, groupNumber, '|');
            this->NumberGroup = stoi(groupNumber);
        }
        

        in.close(); 
    }


};

int main()
{
    //First task
    Point XYZ;
    XYZ.InitPoints();
    XYZ.ShowPoints();
    XYZ.SetX(100);
    XYZ.SetY(200);
    XYZ.SetZ(300);
    cout << endl;
    cout << "X: " << XYZ.GetX(100) << endl;
    cout << "Y: " << XYZ.GetY(200) << endl;
    cout << "Z: " << XYZ.GetZ(300) << endl;
    //Second task
    Student student1;
    student1.InitAll();
    student1.ShowALL();
    cout << endl;
    student1.SetFML("Petro", "Ivanov", "Igorovich");
    student1.SetBirthdayData(11, 12, 2000);
    student1.SetContactTelephone(3801231231);
    student1.SetCity("Rivne");
    student1.SetCountry("Ukraine");
    student1.SetNameEducationInstitution("RFC NUBIP EDU");
    student1.SetCityEducationInstitution("Rivne");
    student1.SetCountryEducationInstitution("Ukraine");
    student1.SetCountryEducationInstitution("Ukraine");
    student1.SetNumberGroup(11);

    student1.GetFML();
    student1.GetBirthdayData();
    cout << student1.GetContactTelephone() << endl;
    cout << student1.GetCity() << endl;
    cout << student1.GetCountry() << endl;
    cout << student1.GetNameEducationInstitution() << endl;
    cout << student1.GetCityEducationInstitution() << endl;
    cout << student1.GetCountryEducationInstitution() << endl;
    cout << student1.GetNumberGroup() << endl;
    student1.SaveToFile();
    student1.ReadFromFile();
    
}