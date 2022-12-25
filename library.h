//
// Created by Younes Lahrichi on 10/05/21   .
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {

  int findBook(const string& name) const;
  
  // display all books in library
  friend ostream &operator<<(ostream &Out, const Library &Lib);

public:
  // constructor with default name
  explicit Library(const string &Name);

  // destructor
  virtual ~Library();

  // add a new book
  // return true if successful, false if
  // book already in library
  bool addBook(const string &BookName);

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  // list all books
  void listAllBooks() const;

  // true if book found in library
  bool isInLibrary(const string &BookName) const;

private:
  //maximum number for the array length
  static const int MAX = 100;
  //int to keep track of the number of books in the library at a time
  int numberOfBooks;
  //intializing the array for my library
  string Libr[MAX];
  //string for holding the name of my library
  string libName;
  
};

#endif  // ASS1_LIBRARY_H