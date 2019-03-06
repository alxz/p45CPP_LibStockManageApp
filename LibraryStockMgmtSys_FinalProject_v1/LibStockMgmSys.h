//#ifndef LIBSTOCKMGMSYS_H  
//#define LIBSTOCKMGMSYS_H

//Author of the application: Alexey Zapromyotov
//submitted to: Houria Houmel
//Created date: Sep-Oct-Nov-2018
//Description of the application : LibraryStockMgmtSys_FinalProject
//Version number of the application : v2
//This version uses VECTOR(s)

#include<iostream>
#include<string>
#include<iomanip>
#include <conio.h>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

struct PubDate
{ // this is what we use to keep DATE: DAY MONTH YEAR
	int day; int month; int year;
};

struct Authors
{ // This structure for Authors
	string firstName; string lastName;
};

struct Book
{ //This structure is required for books
	int id = 0;
	string isbn = "";
	string title = "";
	string author = "";
	Authors authorName;
	float price = 0.0f;
	PubDate pubDate;

	string getFullDate()
	{
		return to_string(pubDate.day) + "/" + to_string(pubDate.month) + "/" + to_string(pubDate.year);
	}

	string getFullName()
	{
		return authorName.firstName + ", " + authorName.lastName;
	}
};

ostream & operator << (ostream &, PubDate &);
istream & operator >>(istream &, PubDate &);

void preload_list_books(Book *, Book *);
void sortByTitle(Book * pf, Book * pl);
void sortByPrice(Book * pf, Book * pl);
void sortByTitleAndAuthor(Book * pf, Book * pl);

//using reference
void load_data(Book[], const int);
void display_data(Book[], const int);
//using pointers
void load_data(Book *, Book *); // Receiving 2 pointers to Books
void display_data(Book *, Book *);
void display_oldBooks(Book *, Book *, int); // using pointers

//using vector <Book> to load and display data:
void load_data(vector <Book>*, const int); //using vector <Book>
void display_data(vector <Book>*, const int); //using vector <Book>
void preload_list_books(vector <Book>*, const int); //using vector <Book>
void display_oldBooks(vector <Book>*); // using vector
void copy_oldBooks_vector(vector <Book>*, vector <Book>*, int);//vectors for New and Old books
bool search_book_vector(vector <Book>*, string, short); // search by ISBN or book Title using vector
														// Use 1=ISBN,2=Title,3=Both
void sortByTitle(vector <Book>*); //using vector <Book>
void sortByPrice(vector <Book>*); //using vector <Book> and sort funcrion from STL
void sortByTitleAndAuthor(vector <Book>*); //using vector <Book>
void write_books_into_file(const char*, vector <Book>*); //Writting data using vector <Book>
void read_books_from_file(const char*, vector <Book>*); //Reading data using vector <Book>


void copy_oldBooks(Book *, Book *, Book *, Book *, int);//ptrfirst,ptrlast for books array
														//ptrfirst,ptrlast for oldbooks array

bool search_book(Book *, Book *, string); //to search a book(s)
bool search_book(Book *, Book *, string, short); //to search a book(s) by ISBN or Title
												// Use 1=ISBN,2=Title,3=Both

void write_books_into_file(const char*, Book *, Book *);
void read_books_from_file(const char*, Book *, Book *);

void drawMainMenu(); //to draw main menu items only
void drawWelcomeScr(); //to draw welcome-Screen only
int chooseInputMethod(); //to select how books should be entered to the system
int setMaxNumberOfBooks(); //to set the max number of books in the library

short getMenuSelection(short , short ); //return selected menu item in short

short isMenuItemNumber(short, short); //to check if selected item is number
bool isValidNumString(string, short); //to validate if it is a numeric string of required length

string& to_lower(string& str); //this is required to use to_lower function
string& to_upper(string& str); //this is required to use to_upper function
//#endif //LIBSTOCKMGMSYS_H //#pragma once