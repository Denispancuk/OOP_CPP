#include <iostream>
using namespace std;
class Point {
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    explicit Point(int Value)
    {
        x = y = Value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()const {
        cout << "X: " << x << " | Y: " << y << endl;
    }
#pragma region Математичні оператори
    Point operator +(const Point& Other) const
    {
        Point res(this->x + Other.x, this->y + Other.y);
        return res;
    }
    Point operator -(const Point& Other) const
    {
        Point res(this->x - Other.x, this->y - Other.y);
        return res;
    }
    Point operator *(const Point& Other) const
    {
        Point res(this->x * Other.x, this->y * Other.y);
        return res;
    }
    Point operator /(const Point& Other)const
    {
        Point res(this->x / Other.x, this->y / Other.y);
        return res;
    }
#pragma endregion
#pragma region Binary Operators
    Point operator += (const Point& Other) {
        this->x += Other.x;
        this->y += Other.y;
        return *this;
    }
    Point operator = (const Point& Other) {
        this->x = Other.x;
        this->y = Other.y;
        return *this;
    }

#pragma endregion


#pragma region Uno Operators
    Point operator - ()const {
        return Point (-x, -y);
        
    }
    Point operator ++() {
        ++this->x;
        ++this->y;
        return *this;
    }
    Point operator --() {
        --this->x;
        --this->y;
        return *this;
    }
    Point operator ++(int) {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator --(int) {
        this->x--;
        this->y--;
        return *this;
    }
#pragma endregion

#pragma region Logic operators
    bool operator > (const Point& other) const{
        return ((this->x + this->y) > (other.x + other.y));

    }
    bool operator < (const Point& other)const {
        return ((this->x + this->y) < (other.x + other.y));

    }
    bool operator >= (const Point& other)const
    {
        return ((this->x + this->y) >= (other.x + other.y));

    }
    

    bool operator == (const Point& other) const{
        return (this->x == other.x && this->y == other.y);

    }
    bool operator != (const Point& other)const {
        /*return (this->x != other.x || this->y != other.y);*/

        return !(*this == other);
    }

#pragma endregion
    int getX() const{
        return x;
    }
    int getY() const{
        return x;
    }
    int setX(int NewX){
        this->x = NewX;
    }
    int setY(int NewY){
        this->y = NewY;
    }
    friend bool operator <= (const Point& left, const Point& right);
    friend ostream& operator << (ostream& out, const Point& point);
    friend istream& operator >>(istream& in, Point& point);
    
    //Overloads operators
    /*void operator [symbol operator]()*/



};

bool operator <= (const Point& left, const Point& right) {
    return ((left.x + left.y) <= (right.x + right.y));
}
ostream& operator << (ostream& out, const Point& point) {
    out << "[" << point.x << ";" << point.y << "]";
    return out;
}
istream& operator >>(istream& in, Point& point) {
    in >> point.x;
    in >> point.y;
    return in;
}


void Clear() { system("cls"); }

class Book {
    string author;
    string name;
    string publish;
    int year;
    int pages;

public:
    Book() {
        this->author = "No author";
        this->name = "No name";
        this->publish = "No publisher";
        this->year = 0;
        this->pages = 0;
    }
    Book(string author, string name, string publish, int year, int pages) {
        this->author = author;
        this->name = name;
        this->publish = publish;
        this->year = year;
        this->pages = pages;
    }
    Book(const Book& other) {
        this->author = other.author;
        this->name = other.name;
        this->publish = other.publish;
        this->year = other.year;
        this->pages = other.pages;
    }
    explicit Book(int year) {
        this->author = "No author";
        this->name = "No name";
        this->publish = "No publisher";
        this->year = year;
        this->pages = 0;
    }

    void Print()const {
        cout << "Author: " << author << '\n';
        cout << "Name: " << name << '\n';
        cout << "Publish: " << publish << '\n';
        cout << "Year: " << year << '\n';
        cout << "Pages: " << pages << '\n';
    }
    string getAuthor()const {
        return author;
    }
    string getPublis()const {
        return publish;
    }
    int getYear()const {
        return year;
    }
    
};

class Library {
    Book* books;
    int countBooks;

public:
    Library() {
        books = nullptr;
        countBooks = 0;
    }
    ~Library() {
        if (countBooks != 0) delete[] books;
    }
    Book operator[](int index) {
        if (index >= 0 && index < countBooks)
            return books[index];
    }
    void PrintAll() {
        for (int i = 0; i < countBooks; i++) {
            books[i].Print();
            cout << '\n';
        }
    }

    void PrintAuthor(string author)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getAuthor() == author) books[i].Print();
    }
    void PrintPublish(string publish)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getPublis() == publish) books[i].Print();
    }
    void PrintYear(int year)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getYear() > year) books[i].Print();
    }

    void addBook(Book book) {
        Book* temp = new Book[countBooks + 1];

        for (int i = 0; i < countBooks; i++) {
            temp[i] = books[i];
        }

        temp[countBooks] = book;

        delete[] books;
        books = temp;
        countBooks++;
    }
    
};

ostream& operator << (ostream& out, const Book& book) {
    out << book.getAuthor() << endl;
    return out;
}
int main()
{
    Library lib;



    lib.addBook(Book("Author2", "Book2", "Publisher2", 2000, 200));
    lib.addBook(Book("Author3", "Book3", "Publisher3", 3000, 300));
    lib.addBook(Book("Author4", "Book4", "Publisher4", 4000, 400));
    lib.addBook(Book("Author5", "Book5", "Publisher5", 5000, 500));
    lib.addBook(Book("Author6", "Book6", "Publisher6", 6000, 600));


    cout << "All books:\n\n";
    lib.PrintAll();
   
    cin.get();
    Clear();
}
