#include <iostream>
#include <string>

using namespace std;

class LibraryBook {
public:
	//Constructors
	LibraryBook();
	LibraryBook(string userTitle, string userAuthor, string ISBN);
	
	//Get the information of the book
	string getTitle();
	string getAuthor();
	string getISBN();
	
	//Change the checkout status of a book
	void checkOut();
	void checkIn();
	
	//Returns the checkout status of the book
	bool isCheckedOut();

private:
	string bookTitle;
	string bookAuthor;
	string bookISBN;
	bool checkedOut;


};
