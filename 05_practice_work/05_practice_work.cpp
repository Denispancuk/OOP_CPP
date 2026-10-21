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
        cout << "Publishing house book: " << name << endl;
        cout << "Year book: " << year << endl;
        cout << "Count pages book: " << count_Pages << endl;
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
};
int main()
{
    
}
