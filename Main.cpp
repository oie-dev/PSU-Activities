#include <iostream>
#include <cstring>
#include <cstdlib>
#include "InfoMngr.h"
using namespace std;

/* Details :
This file is the main file to run a program
use to run 3 diff header file

1. InfoMngr.h
2. List.h
3. Directory.h
*/

int main()
{
	while(true)
	{
		system("cls");
		dislayMenu();
		selectedEntry(userChoice());
	}
	return 0;
}
