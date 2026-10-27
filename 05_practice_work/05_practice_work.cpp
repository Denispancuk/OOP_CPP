#include <iostream>
using namespace std;
class Book {
    string autor;
    string name;
    string publishing_house;
    short year;
    int count_Pages;
public:
    Book()
    {
        this->autor = "No autor";
        this->name = "No name";
        this->publishing_house = "No publishing house";
        this->year = 0;
        this->count_Pages = 0;
    }
    explicit Book(string autor):Book()
    {
        this->autor = autor;
    }
    Book(string autor, string name, string publishing_house, short year, int count_pages)
    {
        this->autor = autor;
        this->name = name;
        this->publishing_house = publishing_house;
        this->year = year;
        this->count_Pages = count_pages;
    }
    void ShowBook()const {
        cout << endl;
        cout << "Autor book: " << autor << endl;
        cout << "Name book: " << name << endl;
        cout << "Publishing house book: " << publishing_house << endl;
        cout << "Year book: " << year << endl;
        cout << "Count pages book: " << count_Pages << endl;
    }
    string GetAuthor() const{
        return autor;
    }
    string GetPublishingHouse() const {
        return publishing_house;
    }
    short GetYear() const{
        return year;
    }
    void InitBook(string autor,
    string name,
    string publishing_house,
    short year,
    int count_Pages) {

        this->autor = autor;
        this->name = name;
        this->publishing_house = publishing_house;
        this->year = year;
        this->count_Pages = count_Pages;

    }
    

};
class Library {
    Book* books;
    int sizeBooks;
public:
    Library()
    {
        sizeBooks = 0;
        books = nullptr;
    }
    explicit Library(int sizeBooks)
    {
        this->sizeBooks = sizeBooks;
        books = new Book[sizeBooks];
    }
    void FindBookAuthors(string Author) const{
        for (int i = 0; i < sizeBooks; i++)
        {
            if (Author == books[i].GetAuthor())
            {
                books[i].ShowBook();
            }
        }
    }
    void FindBookPublishingHouse(string PublishingHouse) const{
        for (int i = 0; i < sizeBooks; i++)
        {
            if (PublishingHouse == books[i].GetPublishingHouse())
            {
                books[i].ShowBook();
            }
        }
    }
    void FindBookYear(short year) const{
        for (int i = 0; i < sizeBooks; i++)
        {
            if (year < books[i].GetYear())
            {
                books[i].ShowBook();
            }
        }
    }

    Book& GetBook(int index)const {
        return books[index];
    }

    ~Library()
    {
        if (books != nullptr)
        {
            delete[] books;
        }
    }
};
int main()
{
    Library myLibrary(4);

    myLibrary.GetBook(0).InitBook("Taras Shevchenko", "Kobzar", "Dnipro", 1995, 450);
    myLibrary.GetBook(1).InitBook("Stephen King", "It", "AST", 2015, 1100);
    myLibrary.GetBook(2).InitBook("Taras Shevchenko", "Haidamaky", "Ababahalamaha", 2020, 150);
    myLibrary.GetBook(3).InitBook("George Orwell", "1984", "Dnipro", 2018, 320);
    cout << "Find by autor:" << endl;
    myLibrary.FindBookAuthors("Taras Shevchenko");
    cout << endl;
    cout << "Find by Publishing house:" << endl;
    myLibrary.FindBookPublishingHouse("Dnipro");
    cout << endl;
    cout << "Find by year:" << endl;
    myLibrary.FindBookYear(2016);




}
