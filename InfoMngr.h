#include <iostream>
#include <cstring>
#include <cstdlib>
#include "List.h"
using namespace std;

/*Class Instantiation
use to call 2 diff classes named
1. MyDirectory.class -> from "Directory.h"
2. MyList.class -> from "List.h"
*/
MyDirectory dir;
MyList mylist;


//Display menu for users choices
void dislayMenu()
{
	cout<<"_________ ____ _______ ___ ___ " <<endl;
	cout<<"|   |   || ___||   | ||  | | |" <<endl;
	cout<<"| | | | || ___|| | | ||  |_| |" <<endl;
	cout<<"|_|___|_||____||_|___||______|" <<endl <<endl;
	cout<<"<  Information Management  >\n\n";
	cout<<"[A] Add new entry" <<endl;
	cout<<"[B] Insert an entry" <<endl;
	cout<<"[C] Display list" <<endl;
	cout<<"[D] Delete an entry" <<endl;
	cout<<"[E] Edit" <<endl;
	cout<<"[F] Find entries" <<endl;
	cout<<"[G] Search an entry" <<endl;
	cout<<"[H] Size of list" <<endl;
	cout<<"[I] First entry of the list" <<endl;
	cout<<"[J] Last entry of the list" <<endl;
	cout<<"[R] Remove all entries" <<endl;
	cout<<"[X] Exit Application" <<endl;
}


//Make user input their choice
char userChoice()
{
	string input;
	cout<<"\n>>> ";
	getline(cin, input);
	
	if (input.length() > 1)
	{
		cout<<"Invalid Input... \n\n";
		system("pause");
		system("cls");
		dislayMenu();
		userChoice();
	}
	return toupper(input[0]);
}


//Define user selected choice
void selectedEntry(char choice)
{
	bool isPause = true;
	switch(choice)
	{
		case 'A': mylist.add(); break;
		case 'B': mylist.insert(); break;
		case 'C': mylist.display(); isPause=false; break;
		case 'D': mylist.remove(); break;
		case 'E': mylist.edit(); break;
		case 'F': mylist.find(); break;
		case 'G': mylist.search(); break;
		case 'H': mylist.size(); break;
		case 'I': mylist.first(); break;
		case 'J': mylist.last(); break;
		case 'R': isPause=mylist.reset(); break;
		case 'X':
			cout<<"Application Exit...";
			isPause=false;
			exit(true);
			break;
		default: cout<<"Invalid Input..."; break;
	}
	cout<<endl <<endl;
	if (isPause) system("pause");
}
