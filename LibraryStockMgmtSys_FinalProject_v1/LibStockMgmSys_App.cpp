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
#include <vector>
using namespace std;

int main()
{
	const char* FILENAME = "bookslist.txt";
		
	Book * booksFromConsole = NULL;
	Book * booksFromFile = NULL;

	int max, inputMethod;
	short menuItem;
	system("cls");
	drawWelcomeScr(); //Show welcome screen first
	//main menu	
	max = setMaxNumberOfBooks(); // Max number of books
	// we will use pointer to the memory location to point to the array of Book
	std::vector <Book> bookNewV(max); // using vector
	std::vector <Book> bookOldV(0); // using vector

	Book * books_arr = new Book[max]; //here: * books_arr contains an address of the memory
	Book * ptr_first = &books_arr[0]; // using dymaic array
	Book * ptr_last = &books_arr[max - 1]; // using dymaic array

	

	Book * oldbooks_arr = new Book[max]; //here: * books_arr contains an address of the memory
	Book * ptrOld_first = &oldbooks_arr[0]; // using dymaic array
	Book * ptrOld_last = &oldbooks_arr[max - 1]; // using dymaic array

	cout << "\n\t-----------------------------------------------------";
	inputMethod = chooseInputMethod();
	switch (inputMethod)
	{
	case 1:
		//preload_list_books(ptr_first, ptr_last); // using dymaic array
		preload_list_books(&bookNewV, max); // using vector
		break;
	case 2:
		//load_data(ptr_first, ptr_last); //here we passing the first element address array, 
										//and the last element address of the array!
		//display_data(ptr_first, ptr_last);
		load_data(&bookNewV, max); //load data using vector
		cout << "\n\n\tPress any key to continue...";
		system("pause");
		break;
	default:
		break;
	}
	cout << "\n\t-----------------------------------------------------";
	do
	{
		drawMainMenu();

		cout << "\n\tPlease select a menu option: \t";
		menuItem = isMenuItemNumber(0, 9);
		cout << "\n\tSelected item: " << menuItem;
		switch (menuItem)
		{
		case 0: //disaply data from books vactor (or array)
		{
			cout << "\n\n\t ========== Output: ============\n";
			//display_data(ptr_first, ptr_last); // using dymaic array
			display_data(&bookNewV, max); // using vector
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 1: //Search by Title
		{
			string searchStr = "";
			bool searchResult = false;
			cin.ignore();
			cout << "\n\tPlease enter the book title: ";
			getline(cin, searchStr);
			//searchResult = search_book(ptr_first, ptr_last, searchStr, 2);// using dymaic array
			searchResult = search_book_vector(&bookNewV, searchStr, 2); // // using vector
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 2: //Search by ISBN
		{
			string searchStr = "";
			bool searchResult = false;
			cin.ignore();
			cout << "\n\tPlease enter the ISBN number: ";
			getline(cin, searchStr);
			//searchResult = search_book(ptr_first, ptr_last, searchStr, 1); // using dymaic array
			searchResult = search_book_vector(&bookNewV, searchStr, 1); // // using vector
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 3: //sort books by author and title
		{
			//sortByTitle(ptr_first, ptr_last);
			//sortByTitleAndAuthor(ptr_first, ptr_last);
			sortByTitle(&bookNewV); //using vector
			sortByTitleAndAuthor(&bookNewV); //using vector
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 4: //sort books by price
		{
			//sortByPrice(ptr_first, ptr_last);
			sortByPrice(&bookNewV);
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 5:
		{
			//copy_oldBooks(ptr_first, ptr_last, ptrOld_first, ptrOld_last, 2014);
			copy_oldBooks_vector(&bookNewV, &bookOldV, 2014); //using vector
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 6:
		{
			//display_oldBooks(ptrOld_first, ptrOld_last, 2014);
			display_oldBooks(&bookOldV);
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 7:
		{
			cout << "\n\n\tWritting the books list into the file...";
			//write_books_into_file(FILENAME, ptr_first, ptr_last);
			write_books_into_file(FILENAME, &bookNewV); //Writting data using vector <Book>
			cout << "\n\n\tWritting completed...";
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 8:
		{
			cout << "\n\n\tReading the books list from the file...";
			//read_books_from_file(FILENAME, ptr_first, ptr_last);
			read_books_from_file(FILENAME, &bookNewV); //Reading data using vector <Book>
			cout << "\n\n\t==== Here is the list we read from file: =====";
			//display_data(ptr_first, ptr_last); //using arrays
			display_data(&bookNewV, max); // using vector
			cout << "\n\n\tPress any key to continue...";
			system("pause");
		}
		break;
		case 9:
			cout << "\n\tExitting application...";
		default:
			break;
		}
	} while (menuItem != 9);

	cout << "\n\t =========== END OF PROGRAM =========== \n\t";
	system("pause");
	return 0;

}
