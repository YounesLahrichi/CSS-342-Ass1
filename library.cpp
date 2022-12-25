//
// Created by Younes Lahrichi on 10/05/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
using namespace std;
#include <iostream>

// constructor with default name
Library::Library(const string &Name) {
  //itializing the name of my library and setting the number of books to 0
  libName = Name;
  numberOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
  for (int i = 0; i < numberOfBooks; i++){
    //checking if the book is in the library
    if (BookName == Libr[i]){
      cout << BookName << " is already in the library." << endl;
      return true;
    }
  }
  return false;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
  // checks if the library is empty, if it is it adds the book to the first index of the array
  if (numberOfBooks == 0) {
    Libr[0] = BookName;
    numberOfBooks += 1;
    return true;
  }
  //if the library isnt empty then it checks if the book is in the library or not
  //if it is in the library it returns false and tells the user that the book is already in the library
  //if it doesnt find the book in the library it will add it into the next available index
  else {
    for (int i = 0; i < numberOfBooks; i++){
      if (Libr[i] == BookName){
        cout << "Sorry, cannot add " << BookName << " it is already in the library." << endl;
        return false;
      }
      else if(i + 1 == numberOfBooks){
        Libr[numberOfBooks] = BookName;
        numberOfBooks += 1;
        return true;
      }
    }
    return false;
  }
  // Library full return false
  return false;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
  //checks if the book is in the library
  //returns true if it is and removes it from the library
  for (int i = 0; i < numberOfBooks; i++){
    if (BookName == Libr[i]){
      Libr[i] = Libr[numberOfBooks];
      Libr[numberOfBooks] = "";
      return true;
    }
  }
  //if its not in the library itll get here and tell the user that it is not in the library
  cout << "Sorry, " << BookName << " is not in the library" << endl;
  return false;
}

// list all books that are currently in the library
void Library::listAllBooks() const {
  for(int i = 0; i < numberOfBooks; i++){
    cout << Libr[i] << endl;
  
  }
}

//returns all of the books that are currently in the library
ostream &operator<<(ostream &Out, const Library &Lib) {
  for (int i = 0; i < Lib.numberOfBooks; i++){
    Out << Lib.Libr[i] << endl;
  return Out;
  }
  return Out;
}
