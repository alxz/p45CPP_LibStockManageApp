#include "LibStockMgmSys.h"

//Author of the application: Alexey Zapromyotov
//submitted to: Houria Houmel
//Created date: Sep-Oct-Nov-2018
//Description of the application : LibraryStockMgmtSys_FinalProject
//Version number of the application : v2
//This version uses VECTOR(s)


#include<iostream>
#include<string>
#include<iomanip>
#include <fstream>
#include <algorithm>
#include <cctype> 

using namespace std;


// implementation

istream & operator >> (istream & is, PubDate & s)
{
	//cout << "\n\tEnter the book published date: (int numbers)";
	cout << "\n\tDay (DD): \t\t";
	is >> s.day; // getting a book day using input stream 'is'
	cout << "\tMonth (MM): \t\t";
	is >> s.month; //getting month using input stream 'is'
	cout << "\tYear (YYYY): \t\t";
	is >> s.year;  //getting year using input stream 'is'
	return is;
}

ostream & operator << (ostream & os, PubDate & s)
{ // output date format: DD-MM-YY
	os << s.day << "-" << s.month << "-" << s.year;
	return os;
}

istream & operator >> (istream & is, Authors & s)
{
	cout << "\n\tEnter the book author name:";
	cout << "\n\tFirst Name: \t";
	is >> s.firstName; // getting a book Author Fname using input stream 'is'
	cout << "\tLast Name: \t";
	//is.ignore();
	is >> s.lastName; //getting Author LastName using input stream 'is'
	return is;
}

ostream & operator << (ostream & os, Authors & s)
{
	os << s.firstName << ", " << s.lastName;
	return os;
}

void load_data(Book books_arr[], const int size)
{
	//<using Ref> methods
	for (int i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "\n\t Book id: ";
		cin >> books_arr[i].id;
		
		cin.ignore();
		cout << "\t Book ISBN: ";
		getline(cin, books_arr[i].isbn);
		cout << "\t Book title: ";
		getline(cin, books_arr[i].title);

		cout << "\t Author: ";
		cin >> books_arr[i].authorName;

		cout << "\t Published Date:";
		cin >> books_arr[i].pubDate;
		
		cout << "\t Book price: ";
		cin>> books_arr[i].price;
		cout << "\n\t ===== <> ======";
	}
}

void display_data(Book books_arr[], const int size)//using BOOK array
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n\t-----------------------------------------------------------------";
		cout << "\n\tBook id:\t\t" << books_arr[i].id << " ;\t ISBN: " << books_arr[i].isbn
			<< " ;\n\tPublished:\t" << books_arr[i].pubDate << " ;\tPrice: " << books_arr[i].price;
		cout << "\n\tTitle:\t\t" << books_arr[i].title;
		cout << "\n\tAuthor:\t\t" << books_arr[i].authorName;
	}
}

void load_data(vector <Book>* vBook, const int size)
{
	//Using vector
	for (int i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "\n\t Book id: ";
		cin >> vBook->at(i).id;

		cin.ignore();
		cout << "\t Book ISBN: ";
		getline(cin, vBook->at(i).isbn);

		cout << "\t Book title: ";
		getline(cin, vBook->at(i).title);

		cout << "\t Author: ";
		cin >> vBook->at(i).authorName;

		cout << "\t Published Date:";
		cin >> vBook->at(i).pubDate;

		cout << "\t Book price: ";
		cin >> vBook->at(i).price;
		cout << "\n\t ===== <> ======";
	}
}

void display_data(vector <Book>* vBook, const int size)//using BOOK Vector
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n\t-----------------------------------------------------------------";
		cout << "\n\tBook id:\t" << vBook->at(i).id << " ;\t ISBN: " << vBook->at(i).isbn
			<< " ;\n\tPublished:\t" << vBook->at(i).pubDate << " ;\tPrice: " << vBook->at(i).price;
		cout << "\n\tTitle:\t\t" << vBook->at(i).title;
		cout << "\n\tAuthor:\t\t" << vBook->at(i).authorName;
	}
}

void load_data(Book * pf, Book * pl) //using pointers
				// to load data into an Array of Structures
{
	for (Book * idx = pf; idx <= pl; idx++)
	{ //<using Pointers> 
		cin.ignore();
		cout << "\n\t Book id ? ";
		cin >> idx->id;
		cin.ignore();
		cout << "\t Book ISBN: ";
		getline(cin, idx->isbn);
		cout << "\t Book title: ";
		getline(cin, idx->title);
		cout << "\t Author Name: ";
		cin >> idx->authorName;
		cout << "\t Published Date:";
		cin >> idx->pubDate;		
		cout << "\t Book price: ";
		cin >> idx->price;
	}
}

void preload_list_books(Book * pf, Book * pl) //using pointers
{
	int counter = 0;
	int randTitleNum = 0;
	int randAuthNum = 0;
	string suffix = "";
	string listAuthors[5] = { "Stephen Koeng", "Joan Bowling", "Charles Dickeinz", "Ernesto Hedingway", "Tolstoy Petro" };
	string listAuthorsFN[5] = { "Stephen", "Joan", "Charles", "Ernesto", "Petro" };
	string listAuthorsLN[5] = { "Koeng", "Bowling", "Dickeinz", "Hedingway", "Tolstoy" };
	string listTitles[10] = { "The Shinning", "Henry Petter", "Boliwar Twist", "The Old Dude and the Moon", "The Business And The Peace",
	"For Whom the Whistle Sounds", "Soft Times", "A Little Thing", "C Plus Minus and Others", "Under the RatHat"};
	for (Book * idx = pf; idx <= pl; idx++)
	{ //<using Pointers> 
		counter ++;
		//suffix = to_string((0 + rand() % 50) + counter); //randomly generate number
		suffix = to_string(counter + 10) + "-" + to_string(counter + 1000) + "-" + to_string(counter + 100);
		randTitleNum = (0 + rand() % 10);
		idx->id = counter + 100;
		idx->title = listTitles[randTitleNum];
		//to search if same title already existing in the list
		//for (Book * idxIn = pf; idxIn <= pl; idxIn++)
		//{
		//	if (idxIn->title == idx->title)
		//	{
		//		idx->author = idxIn->author;
		//		idx->authorName = idxIn->authorName; //if title the same - make sure the author is the same too
		//	}
		//}
		if (idx->authorName.firstName == "")
		{
			idx->author = listAuthors[(0 + rand() % 5)];//if the author not set yet - set it randomly
			idx->authorName.firstName = listAuthorsFN[(0 + rand() % 5)];//if the author not set yet - set it randomly
			idx->authorName.lastName = listAuthorsLN[(0 + rand() % 5)];//if the author not set yet - set it randomly
		}
		idx->isbn = suffix;
		idx->pubDate.day = (0 + rand() % 28);
		idx->pubDate.month = (0 + rand() % 11);
		idx->pubDate.year = 2008 + ((0 + rand() % 10));
		idx->price = float ((1 + rand() % 9)) * 20.5 ;
	}
}

void preload_list_books(vector <Book>* vBook, const int size) //using Vector
{
	int counter = 0;
	int randTitleNum = 0;
	int randAuthNum = 0;
	string suffix = "";
	string listAuthors[5] = { "Stephen Koeng", "Joan Bowling", "Charles Dickeinz", "Ernesto Hedingway", "Tolstoy Petro" };
	string listAuthorsFN[5] = { "Stephen", "Joan", "Charles", "Ernesto", "Petro" };
	string listAuthorsLN[5] = { "Koeng", "Bowling", "Dickeinz", "Hedingway", "Tolstoy" };
	string listTitles[10] = { "The Shinning", "Henry Petter", "Boliwar Twist", "The Old Dude and the Moon", "The Business And The Peace",
		"For Whom the Whistle Sounds", "Soft Times", "A Little Thing", "C Plus Minus and Others", "Under the RatHat" };
	for (int i = 0; i < size; i++)
	{ 
		counter++;		
		suffix = to_string(counter + 10) + "-" + to_string(counter + 1000) + "-" + to_string(counter + 100);
		randTitleNum = (0 + rand() % 10);
		vBook->at(i).id = counter + 100;
		vBook->at(i).title = listTitles[randTitleNum];
		
		vBook->at(i).author = listAuthors[(0 + rand() % 5)];//if the author not set yet - set it randomly
		vBook->at(i).authorName.firstName = listAuthorsFN[(0 + rand() % 5)];//if the author not set yet - set it randomly
		vBook->at(i).authorName.lastName = listAuthorsLN[(0 + rand() % 5)];//if the author not set yet - set it randomly
		
		vBook->at(i).isbn = suffix;
		vBook->at(i).pubDate.day = (0 + rand() % 28);
		vBook->at(i).pubDate.month = (0 + rand() % 11);
		vBook->at(i).pubDate.year = 2008 + ((0 + rand() % 10));
		vBook->at(i).price = float ((1 + rand() % 9)) * 20.5;
	}
}

void display_data(Book * pf, Book * pl) //using pointers
				// to read data from an Array of Structures
{
	for (Book * idx = pf; idx <= pl; idx++)
	{
		cout << "\n\t-----------------------------------------------------------------";
		cout << "\n\tBook id:\t" << idx->id << " ;\t ISBN: " << idx->isbn 
			<< " ;\n\tPublished:\t" << idx->pubDate << " ;\tPrice: " << idx->price;
		cout << "\n\tTitle:\t\t" << idx->title;
		cout << "\n\tAuthor:\t\t" << idx->authorName; 
	}
}

bool search_book(Book * pf, Book * pl, string searchStr)// to read data from an Array of Structures
{
	short countFound = 0;
	for (Book * idx = pf; idx <= pl; idx++)
	{
		if (idx->isbn == searchStr)
		{
			countFound++;
			cout << "\n\t-------    Book item found  ------------";
			cout << "\n\tBook id:\t" << idx->id << "\t ISBN: " << idx->isbn 
				<< "\n\tPublished:\t" << idx->pubDate << "\tBook price: " << idx->price;
			cout << "\tBook Title:\t\t" << idx->title << endl;
			cout << "\tBook Author:\t\t" << idx->authorName << endl;
			cout << "\t-----------------------------------------------------";
		}		
	}
	cout << "\n\t-----------------------------------------------------";
	if (countFound > 0)
	{
		cout << "\n\t We found these number of books: " << countFound;
		return true;
	}
	else
	{
		cout << "\n\t Sorry, nothing found! Please try again... \n";
		return false;
	}
	return false;
}

//looking for more advanced search:
bool search_book(Book * pf, Book * pl, string searchStr, short searchType)
{
	short countFound = 0;
	for (Book * idx = pf; idx <= pl; idx++)
	{
		switch (searchType)
		{
		case 1:
		{
			string bookISBN = idx->isbn;
			if (to_upper(bookISBN) == to_upper(searchStr))
			{
				countFound++;
				cout << "\n\t-------    Book item found  ------------";
				cout << "\n\tBook id:\t" << idx->id << "\t\t ISBN: " << idx->isbn;
				cout << "\n\tTitle:\t" << idx->title; 
				cout << "\n\tAuthor:\t" << idx->authorName;
				cout << "\n\tPublished:\t" << idx->pubDate << " ;\t Price: " << idx->price << endl;
			}
		}			
			break;
		case 2:
		{
			string bookTitle = idx->title;
			if (to_upper(bookTitle) == to_upper(searchStr))
			{
				countFound++;
				cout << "\n\t-------    Book item found  ------------";
				cout << "\n\tBook id:\t" << idx->id << "\t\t ISBN: " << idx->isbn;
				cout << "\n\tTitle:\t" << idx->title;
				cout << "\n\tAuthor:\t" << idx->authorName;
				cout << "\n\tPublished:\t" << idx->pubDate << " ;\t Price: " << idx->price << endl;
			}
		}
			break;
		case 3:
			break;
		default:
			break;
		} 
		
	}
	cout << "\n\t----------------------<->------------------------";
	if (countFound > 0)
	{
		cout << "\n\tFound books: " << countFound;
		return true;
	}
	else
	{
		cout << "\n\t Sorry, nothing found! Please try again... \n";
	}
	return false;
}

bool search_book_vector(vector<Book>* vBook, string searchStr, short searchType)
{
	short countFound = 0;
	for (int i = 0; i < vBook->size(); i++)
	{
		switch (searchType)
		{
		case 1: // if we are searching by ISBN
		{
			string bookISBN = vBook->at(i).isbn;
			if (to_upper(bookISBN) == to_upper(searchStr))
			{
				countFound++;
				cout << "\n\t-------    Book item found  ------------";
				cout << "\n\tBook id:\t" << vBook->at(i).id << "\t\t ISBN: " << vBook->at(i).isbn;
				cout << "\n\tTitle:\t" << vBook->at(i).title;
				cout << "\n\tAuthor:\t" << vBook->at(i).authorName;
				cout << "\n\tPublished:\t" << vBook->at(i).pubDate << " ;\t Price: " << vBook->at(i).price << endl;
			}
		}
		break;
		case 2: // if we are searching by Book Title
		{
			string bookTitle = vBook->at(i).title;
			if (to_upper(bookTitle) == to_upper(searchStr))
			{
				countFound++;
				cout << "\n\t-------    Book item found  ------------";
				cout << "\n\tBook id:\t" << vBook->at(i).id << "\t\t ISBN: " << vBook->at(i).isbn;
				cout << "\n\tTitle:\t" << vBook->at(i).title;
				cout << "\n\tAuthor:\t" << vBook->at(i).authorName;
				cout << "\n\tPublished:\t" << vBook->at(i).pubDate << " ;\t Price: " << vBook->at(i).price << endl;
			}
		}
		break;
		case 3:  // Reserved for something else to search
			break;
		default:
			break;
		}

	}
	cout << "\n\t----------------------<->------------------------";
	if (countFound > 0)
	{
		cout << "\n\tFound books: " << countFound;
		return true;
	}
	else
	{
		cout << "\n\t Sorry, nothing found! Please try again... \n";
	}
	return false;
}

// using pointers - read/write
void write_books_into_file(const char* FILENAME , Book * pf, Book * pl) 
{
	ofstream output_file(FILENAME, ios::out);

	for (Book * idx = pf; idx <= pl; idx++)
	{
		output_file << idx->id << "|";
		output_file << idx->isbn << "|";
		output_file << idx->authorName.firstName << "|";
		output_file << idx->authorName.lastName << "|";
		output_file << idx->title << "|";
		output_file << idx->pubDate.day << "|";
		output_file << idx->pubDate.month << "|";
		output_file << idx->pubDate.year << "|";
		output_file << idx->price << "|\n";
	}
	output_file.close();
}

void read_books_from_file(const char* FILENAME, Book * pf, Book * pl)
{
	ifstream input_file(FILENAME, ios::in);
	string temp;
	if (input_file.good())
	{
		for (Book * idx = pf; idx <= pl; idx++)
		{
			getline(input_file, temp, '|');
			idx->id = stoi(temp);
			getline(input_file, idx->isbn, '|');
			getline(input_file, idx->authorName.firstName, '|');
			getline(input_file, idx->authorName.lastName, '|');
			getline(input_file, idx->title, '|');
			getline(input_file, temp, '|');
			idx->pubDate.day = stoi(temp);
			getline(input_file, temp, '|');
			idx->pubDate.month = stoi(temp);
			getline(input_file, temp, '|');
			idx->pubDate.year = stoi(temp);
			getline(input_file, temp, '\n');
			idx->price = stof(temp);
		}
	}
	input_file.close();
}

// using vectors - read/write
void write_books_into_file(const char* FILENAME, vector <Book>* vBook)
{
	ofstream output_file(FILENAME, ios::out);

	for (int i=0; i < vBook->size(); i++)
	{
		output_file << vBook->at(i).id << "|";
		output_file << vBook->at(i).isbn << "|";
		output_file << vBook->at(i).authorName.firstName << "|";
		output_file << vBook->at(i).authorName.lastName << "|";
		output_file << vBook->at(i).title << "|";
		output_file << vBook->at(i).pubDate.day << "|";
		output_file << vBook->at(i).pubDate.month << "|";
		output_file << vBook->at(i).pubDate.year << "|";
		output_file << vBook->at(i).price << "|\n";
	}
	output_file.close();
}

void read_books_from_file(const char* FILENAME, vector <Book>* vBook)
{
	ifstream input_file(FILENAME, ios::in);
	string temp;
	if (input_file.good())
	{
		for (int i = 0; i < vBook->size(); i++)
		{
			getline(input_file, temp, '|');
			vBook->at(i).id = stoi(temp);
			getline(input_file, vBook->at(i).isbn, '|');
			getline(input_file, vBook->at(i).authorName.firstName, '|');
			getline(input_file, vBook->at(i).authorName.lastName, '|');
			getline(input_file, vBook->at(i).title, '|');
			getline(input_file, temp, '|');
			vBook->at(i).pubDate.day = stoi(temp);
			getline(input_file, temp, '|');
			vBook->at(i).pubDate.month = stoi(temp);
			getline(input_file, temp, '|');
			vBook->at(i).pubDate.year = stoi(temp);
			getline(input_file, temp, '\n');
			vBook->at(i).price = stof(temp);
		}
	}
	input_file.close();
}

void drawWelcomeScr()
{
	cout << "\n\tLaSalle College Library Stock Management System";
	cout << "\n\tproject by Alexey Zapromyotov. Ver 1.7 Fall2018\n";
	cout << "\n\tPart 1: Creating a late binding array with the books..";
	cout << "\n\tPart 2: Read/Writting the books list to the file..\n";
}

int setMaxNumberOfBooks()
{
	int max = 0;
	cout << "\n\tInput the max number of books to enter to the system: ";
	cin >> max;
	return max;
}

int chooseInputMethod()
{
	int inputMethod;
	cout << "\n\n\t Please choose how to create the list of the books:";
	cout << "\n\t1. Generate the book attributes (Title, Author, Year, Price, ISBN)";
	cout << "\n\t2. Enter each book attributes manually ";
	cout << "\n\n\t\tEnter the number: ";
	cin >> inputMethod;

	return inputMethod;
}
void drawMainMenu()
{
	cout << "\n\t\tPlease choose activity:";
	cout << "\n\t\t0. Display all books from the library";
	cout << "\n\t\t1. Search a book by Title";
	cout << "\n\t\t2. Search a book by ISBN";
	cout << "\n\t\t3. Sort books by title and author\'s last name";
	cout << "\n\t\t4. Sort books by price (descending)";
	cout << "\n\t\t5. Copy the oldest book (year 2014 and less)";
	cout << "\n\t\t6. Show old books (year 2014 and less)";
	cout << "\n\n\t\t7. Save Data to the file (bookslist.txt)";
	cout << "\n\t\t8. Read Data from the file (bookslist.txt)";
	cout << "\n\n\t\t9. Exit application.\n";
}

short isMenuItemNumber(short minN, short maxN)
{
	string menuItem = "";
	int menuNum = 0;
	bool isInRange = false;
	do
	{
		cin >> menuItem;
		if (!isValidNumString(menuItem,1))
		{
			cout << "\n\tIncorrect input!\n\tPlease try again: \t";
			menuItem = "";
			menuNum = 0;
			isInRange = false;
		}
		else
		{
			menuNum = stoi(menuItem);
			if (menuNum <minN || menuNum > maxN)
			{
				cout << "\n\tThe number is not in range!\n\tPlease try again: \t";
				isInRange = false;
			}
			else
			{
				isInRange = true;
			}
		}		
	} while (!isInRange);
	return menuNum;
}

short getMenuSelection(short minNum, short maxNum)
{
	short numSelected = minNum;
	bool numInRange = false;
	char chr;
	do
	{
		while ((chr = _getch()) != 13)
		{
			switch (chr)
			{
			case '0':
				cout << chr;
				numSelected = 0;
					break;
			case '1':
				cout << chr;
				numSelected = 1;
				break;
			case '2':
				cout << chr;
				numSelected = 2;
				break;
			case '3':
				cout << chr;
				numSelected = 3;
				break;
			case '4':
				cout << chr;
				numSelected = 4;
				break;
			case '5':
				cout << chr;
				numSelected = 5;
				break;
			case '6':
				cout << chr;
				numSelected = 6;
				break;
			case '7':
				cout << chr;
				numSelected = 7;
				break;
			case '8':
				cout << chr;
				numSelected = 8;
				break;
			case '9':
				cout << chr;
				numSelected = 9;
				break;
			default:
				break;
			}
		}
		if (numSelected >= minNum && numSelected <= maxNum)
		{
			numInRange = true;
		}
		else
		{
			cout << "\n\tNumber is not in the menue range!\nPlease trye again!\n\t";
			numInRange = false;
		}
	} while (!numInRange);


	return numSelected;
}

// to validate if input data is numeric string - receive string, max length and maximum value
bool isValidNumString(string input, short len) {
	bool valid = true;
	if (input == "") valid = false;
	if ((len > 0) && (input.length() != len)) valid = false;
	for (short i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) valid = false;
	}
	return valid;
};


std::string& to_lower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), static_cast<int(*)(int)>(std::tolower));
	return str;
}

std::string& to_upper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), static_cast<int(*)(int)>(std::toupper));
	return str;
}

void sortByTitle(Book * pf, Book * pl) {
	//Book *test = (pl - 1);
	Book tempBook;
	for (Book * idxOut = pf; idxOut <= pl; idxOut++) {
		for (Book * idxIn = pf; idxIn <= (pl - 1); idxIn++) {
			if (idxOut->title.compare(idxIn->title)<0) //to compare in alphabetical order
			{
				tempBook = *idxIn;
				*idxIn = *idxOut;
				*idxOut = tempBook;
			}
		}
	}
}

bool compareTitleAlphabet(const Book &a, const Book &b) // this is to compare titles by alphabet
{
	return a.title < b.title;
}

void sortByTitle(vector <Book>* vBook) {
	sort(vBook->begin(), vBook->end(), compareTitleAlphabet);
	//for (std::vector <Book>::iterator it = vBook->begin(); it != vBook->end(); ++it)
	//{
	//	//it->title
	//}
}


void sortByTitleAndAuthor(Book * pf, Book * pl) {
	//Book *test = (pl - 1);
	Book tempBook;
	for (Book * idxOut = pf; idxOut <= pl; idxOut++) {
		for (Book * idxIn = pf; idxIn <= (pl - 1); idxIn++) {
			if (idxOut->title == idxIn->title)
			{
				if (idxOut->authorName.lastName.compare(idxIn->authorName.lastName) < 0) //to compare in alphabetical order
				{
					tempBook = *idxIn;
					*idxIn = *idxOut;
					*idxOut = tempBook;
				}
			}			
		}
	}
}

bool compareAuthorAlphabet(const Book &a, const Book &b) // this is to compare Authors Last Names by alphabet
{
	return a.authorName.lastName < b.authorName.lastName;
}

void sortByTitleAndAuthor(vector <Book>* vBook) {
	//Book *test = (pl - 1);
	Book tempBook;
	for (int i = 0; i < vBook->size(); i++) {
		for (int j = 0; j < vBook->size() - 1; j++) 
		{
			if (vBook->at(i).title == vBook->at(j).title)
			{
				if (vBook->at(i).authorName.lastName.compare(vBook->at(j).authorName.lastName) < 0) //to compare in alphabetical order
				{
					tempBook = vBook->at(j);
					vBook->at(j) = vBook->at(i);
					vBook->at(i) = tempBook;
				}
			}
		}
	}
}

// Ascending sort. Arranging data from the normal low to high sequence; for example, 
// from A to Z or from 0 to 9. Contrast with descending sort.
void sortByPrice(Book * pf, Book * pl) {
	//Book *test = (pl - 1);
	Book tempBook;
	for (Book * idxOut = pf; idxOut <= pl; idxOut++) {
		for (Book * idxIn = pf; idxIn <= (pl - 1); idxIn++) {
			if (idxOut->price > idxIn->price) //to compare in alphabetical order
			{
				tempBook = *idxIn;
				*idxIn = *idxOut;
				*idxOut = tempBook;
			}
		}
	}
}

bool comparePrices(const Book &a, const Book &b) // this is to compare Prices desc
{
	return a.price > b.price;
}

void sortByPrice(vector <Book>* vBook) //using vector and sort funcrion from STL
{
	sort(vBook->begin(), vBook->end(), comparePrices);
}

void display_oldBooks(Book * pf, Book * pl, int yearSince) //using pointers
										// to read data from an Array of Structures
{
	for (Book * idx = pf; idx <= pl; idx++)
	{
		if (idx->id != 0)
		{
			cout << "\n\t----------------------------------------------";
			cout << "\n\tBook id:\t" << idx->id << " ;\t ISBN: " << idx->isbn
				<< " ;\n\tPublished: \t" << idx->pubDate << " ;\tPrice: " << idx->price;
			cout << "\n\tBook Title:\t\t" << idx->title;
			cout << "\n\tBook Author:\t\t" << idx->authorName;
		}
	}
}

void copy_oldBooks(Book * pf, Book * pl, Book * pfOld, Book * plOld, int yearSince) // using dynamic array
{
	int countOldBook = 0;
	Book * idxOld = pfOld; //set pointer for oldBooks array to the first element
	for (Book * idx = pf; idx <= pl; idx++) //Loop through the book_array
	{
		if (idx->pubDate.year <= yearSince) //if the book year is old enough than....
		{
			countOldBook++;
			idxOld->id = idx->id;
			idxOld->authorName = idx->authorName;
			idxOld->isbn = idx->isbn;
			idxOld->price = idx->price;
			idxOld->pubDate = idx->pubDate;
			idxOld->title = idx->title;
			idxOld++; //move to the next slot in the Old books array
		}
	}
	cout << "\n\n\tFound " << countOldBook << " books older than " << yearSince;
}

// using vectors: 
void copy_oldBooks_vector(vector<Book>* vBookNew, vector<Book>* vBookOld, int yearSince) // using dynamic array
{
	int countOldBook = 0;
	for (int i = 0; i < vBookNew->size(); i++) {
		if (vBookNew->at(i).pubDate.year <= yearSince) //if the book year is old enough than....
		{
			//vBookOld->at(countOldBook).id =(vBookNew->at(i).id);
			//vBookOld->at(countOldBook).authorName = (vBookNew->at(i).authorName);
			//vBookOld->at(countOldBook).isbn = (vBookNew->at(i).isbn);
			//vBookOld->at(countOldBook).price = (vBookNew->at(i).price);
			//vBookOld->at(countOldBook).pubDate = (vBookNew->at(i).pubDate);
			//vBookOld->at(countOldBook).title = (vBookNew->at(i).title);
			vBookOld->push_back(vBookNew->at(i));
			countOldBook++;
		}
	}
	cout << "\n\n\tFound " << countOldBook << " books older than " << yearSince;
}

void display_oldBooks(vector <Book>* vBook) //using pointers
														   // to read data from an Array of Structures
{
	cout << "\n\t----------------------------------------------";
	cout << "\n\n\tFound " << vBook->size() << " books: \n ";
	cout << "\n\t----------------------------------------------";
	for (int i = 0; i < vBook->size(); i++)
	{
		cout << "\n\t----------------------------------------------";
		cout << "\n\tBook id:\t" << vBook->at(i).id << " ;\t ISBN: " << vBook->at(i).isbn
			<< " ;\n\tPublished: \t" << vBook->at(i).pubDate << " ;\tPrice: " << vBook->at(i).price;
		cout << "\n\tBook Title:\t" << vBook->at(i).title;
		cout << "\n\tBook Author:\t" << vBook->at(i).authorName;
	}
}
/*
//comments
*/