#include <iostream>
using namespace std;
struct FullName {
    string FirstName;
    string LastName;
    string MiddleName;

};
class Worker {
    FullName Name;
    string Position;
    short YearStartJob;
    int Salary;
public:
    Worker()
    {
        Name = { "NoFirstName","NoLastName","NoMiddleName" };
        Position = "No Position";
        YearStartJob = 0;
        Salary = 0;
    }
    Worker(FullName Name,string Position,short YearStartJob,int Salary)
    {
        this->Name = Name;
        this->Position = Position;
        this->YearStartJob = YearStartJob;
        this->Salary = Salary;
    }
    void ShowWorker() const {
        cout << "\nName: " << Name.FirstName << " | " << Name.LastName << " | " << Name.MiddleName << endl;
        cout << "Position: " << Position << endl;
        cout << "Year Starting Job: " << YearStartJob << endl;
        cout << "Salary: " << Salary << endl;
    }
    short GetYear() const{
        return YearStartJob;
    }
    int GetSalary() const{
        return Salary;
    }
    string GetPosition() const{
        return Position;
    }
    void InitWorker(FullName Name, string Position, short YearStartJob, int Salary) {
        this->Name = Name;
        this->Position = Position;
        this->YearStartJob = YearStartJob;
        this->Salary = Salary;
    }
};
class Workers {
    int SizeWorkers;
    Worker* AllWorkers;
public:
    Workers()
    {
        SizeWorkers = 0;
        AllWorkers = nullptr;
    }
    explicit Workers(int SizeWorkers)
    {
        this->SizeWorkers = SizeWorkers;
        AllWorkers = new Worker[SizeWorkers];
    }
    void SearchWorkerByYear(short year) const{
        for (int i = 0; i < SizeWorkers; i++)
        {
            if (2026-AllWorkers[i].GetYear() > year)
            {
                AllWorkers[i].ShowWorker();
            }
        }
        
    }
    void SearchWorkerBySalary(int salary) const{
        for (int i = 0; i < SizeWorkers; i++)
        {
            if (AllWorkers[i].GetSalary() > salary)
            {
                AllWorkers[i].ShowWorker();
            }
        }
        
    }
    void SearchWorkerByPosition(string Position) const{
        for (int i = 0; i < SizeWorkers; i++)
        {
            if (AllWorkers[i].GetPosition() == Position)
            {
                AllWorkers[i].ShowWorker();
            }
        }
        
    }
    Worker& GetWorker(int index)const {
        return AllWorkers[index];
    }
    ~Workers(){
        if (AllWorkers != nullptr)
        {
            delete[] AllWorkers;
        }
    }
};
int main()
{
    Workers company(4);

    company.GetWorker(0).InitWorker({ "Ivan", "Ivanov", "Ivanovych" }, "Developer", 2020, 2500);
    company.GetWorker(1).InitWorker({ "Petro", "Petrov", "Petrovych" }, "Manager", 2018, 1800);
    company.GetWorker(2).InitWorker({ "Anna", "Sydorenko", "Dmitrivna" }, "Developer", 2024, 3000);
    company.GetWorker(3).InitWorker({ "Olga", "Kovalenko", "Petrivna" }, "Designer", 2015, 2200);

    cout << "Find by year:" << endl;
    company.SearchWorkerByYear(5);

    cout << "\nFind by salary:" << endl;
    company.SearchWorkerBySalary(2000);

    cout << "\nFind by position:" << endl;
    company.SearchWorkerByPosition("Developer");
}