// Chad Huntebrinker
// crh92d@umsystem.edu
// 10/22/20
// CS201L Lab 01

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "LibraryBook.h"

using namespace std;

int main() {
	string fileTitle;
	string fileAuthor;
	string fileISBN;
	string theISBN;
	LibraryBook aBook;
	int i;
	bool isHere;
	vector<LibraryBook> bookVector;
	vector<LibraryBook> checkedOutVector;
	ifstream finBook, finISBN;
	ofstream fout;

	finBook.open("books.txt");
	finISBN.open("isbns.txt");
	fout.open("checkedout.txt");

	
	//This while loop reads in the book information from the book file and puts it into a vector.
	while (getline(finBook, fileTitle)) {
		getline(finBook, fileAuthor);
		getline(finBook, fileISBN);
		
		aBook = { fileTitle, fileAuthor, fileISBN };
		bookVector.push_back(aBook);
	}
	//This while loop reads the ISBN number from the ISBN file and compares that number with 
	//the different book's ISBN number to find the correct book.  Once it does, it then changes
	//the status of the book and updates the vector it was stored in.  If it was checked out, it is 
	//now checked in and if it was checked in, it is now checked out.
	while (getline(finISBN, theISBN)) {
		for (i = 0; i < bookVector.size(); ++i) {
			aBook = bookVector.at(i);
			if (theISBN == aBook.getISBN()) {
				if (aBook.isCheckedOut()) {
					aBook.checkIn();
					bookVector.at(i) = aBook;
					break;
				}
				else{
					aBook.checkOut();
					bookVector.at(i) = aBook;
					break;
				}

			}
			
		}
	}

	//This for loop takes all the books from the vector and finds the check out status. If
	//the book is checked out, then it is added to the output file.  If it isn't checked out,
	//the loop moves on to the next book.
	for (i = 0; i < bookVector.size(); ++i) {
		aBook = bookVector.at(i);
		isHere = aBook.isCheckedOut();
		if (isHere) {
			checkedOutVector.push_back(aBook);
		}
	}
	fout << "BOOKS CHECKED OUT" << endl;
	fout << setw(20) << setfill('-') << "" << endl << endl << endl;
	fout << setfill(' ');

	fout << "Title   Author   ISBN" << endl << endl;

	//Outputs the checked out books to the output file
	for (i = 0; i < checkedOutVector.size(); ++i) {
		fout << checkedOutVector.at(i).getTitle() << "		";
		fout << checkedOutVector.at(i).getAuthor() << "		";
		fout << checkedOutVector.at(i).getISBN() << "	";
		fout << endl << endl;
	}

	finBook.close();
	finISBN.close();
	fout.close();

	return 0;
}