#include <iostream>
#include <string>
#include "LibraryBook.h"

using namespace std;

//Default constructor.
LibraryBook::LibraryBook() {
	bookTitle = "  ";
	bookAuthor = "  ";
	bookISBN = "  ";
	checkedOut = false;
}

//Constructor with parameters.
LibraryBook::LibraryBook(string userTitle, string userAuthor, string ISBN) {
	bookTitle = userTitle;
	bookAuthor = userAuthor;
	bookISBN = ISBN;
	checkedOut = false;
}

//Return the book's title.
string LibraryBook::getTitle(){ 
	return bookTitle; 
}

//Return the book's author.
string LibraryBook::getAuthor() { 
	return bookAuthor; 
}

//Return the book's ISBN number.
string LibraryBook::getISBN() { 
	return bookISBN;
}

//Change the check out status to checked out (or true).
void LibraryBook::checkOut() {
	checkedOut = true;
}

//Change the check out status to checked in (or false).
void LibraryBook::checkIn() {
	checkedOut = false;
}

//Returns the check out status of the book.
bool LibraryBook::isCheckedOut() {
	return checkedOut;
}


