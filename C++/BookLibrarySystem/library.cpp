#include <iostream>
#include <vector>

using namespace std;

// generic function to remove from vector at certain position
template <typename T>
void removeFromVec(vector<T>& vec, int index) {
    if (index < vec.size()) {
        vec.erase(vec.begin() + index);
    }
    else {
        cerr << "Index out of bounds" << endl;
    }
}

class Book {

public:

    // Book constructor
    Book(string _title, string _author, int _year) {
        title = _title;
        author = _author;
        year = _year;
    }

    // print info for book
    void printInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }

    const string& getTitle() const {
        return title;
    }

private:

    // Book members
    string title;
    string author;
    int year;
};

class Library {

public:

    vector<Book*> books;

    // no Library constructor needed (no parameters given)

    // Library destructor
    ~Library() {

        // delete books to prevent memory leak
        for (Book* book : books) {
            delete book;
        }

        // clear books list
        books.clear();
    }

    void addBook(Book* book) {
        books.push_back(book);
    }

    void displayBooks() {

        // call printInfo() for every book
        size_t booksLen = books.size();
        for (int i = 0; i < booksLen; i++) {
            cout << "Book " << i + 1 << ":" << endl;
            Book* curBook = books[i];
            curBook->printInfo();
        }
    }

    void deleteBookByTitle(string title) {

        // find book with title and remove it from list
        size_t booksLen = books.size();
        for (int i = 0; i < booksLen; i++) {
            Book* curBook = books[i];
            if (curBook->getTitle() == title) {
                removeFromVec(books, i);
                return;
            }
        }
    }

};

int main() {

    // create library
    Library myLibrary;

    // adding books to library
    myLibrary.addBook(new Book("Murder on the Orient Express", "Agatha Christie", 1934));
    myLibrary.addBook(new Book("Moby Dick", "Herman Melville", 1851));
    myLibrary.addBook(new Book("Pride and Prejudice", "Jane Austen", 1813));

    // display all books
    myLibrary.displayBooks();

    // remove book
    cout << "removing Moby Dick..." << endl;
    myLibrary.deleteBookByTitle("Moby Dick");
    
    // display again
    myLibrary.displayBooks();
}