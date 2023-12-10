#include <iostream>
#include <cstdlib>
#include <fstream>
#include "CustomMethod.h"
using namespace std;

class MyDirectory
{
	private:
		CustomMethod myMethod;
		
	public:
		
		//Clear all the contents of the txt file
		void clearData()
		{
			//open file and then it clear texts
			ofstream file("data.txt");
			file.clear();
			file.close();
		}
		
		//Add new values at the end of the list
		void save(string fname, string mname, string lname, string adrs, int age, string cont)
		{
			//Retrieve from txt file
			string line, content;
			ifstream file1("data.txt"); //open file then 
			while(getline(file1, line)) //assign into content variable
				content += line + "\n";
			file1.close();
			
			//Save to txt file
			string data = content; //assign the content of the data var from the txt file
			ofstream file2("data.txt");
			if (file2.is_open())
			{
				//concat infos into data var then split with %
				data += lname + "%";
				data += fname + "%";
				data += mname + "%";
				data += adrs + "%";
				data += myMethod.IntToString(age) + "%";
				data += cont + "%\n";
				file2<<data; //make the content of file as all the data frm .txt file
			}
			else file2.close();
		}
		
		//Retrieve data then assign and return via array
		string* retrieveData(int num)
		{
			//create arrys
			string *fnames = new string[size()];
			string *mnames = new string[size()];
			string *lnames = new string[size()];
			string *address = new string[size()];
			string *ages = new string[size()];
			string *contacts = new string[size()];
			string line;
			int i=0;
			
			//open txt file and get contents line by line
			ifstream file("data.txt");
			while(getline(file, line))
			{
				//splitValue method used to return array of info
				fnames[i] = myMethod.splitValue(line, 2);
				mnames[i] = myMethod.splitValue(line, 3);
				lnames[i] = myMethod.splitValue(line, 1);
				address[i] = myMethod.splitValue(line, 4);
				ages[i] = myMethod.splitValue(line, 5);
				contacts[i] = myMethod.splitValue(line, 6);
				i++;
			}
			file.close();
			
			//return array values
			if (num==1) return fnames;
			else if (num==2) return mnames;
			else if (num==3) return lnames;
			else if (num==4) return address;
			else if (num==5) return ages;
			else if (num==6) return contacts;
			else return fnames;
		}
		
		//Get the size via txt file
		int size()
		{
			int counter;
			string line;
			ifstream file("data.txt"); //open txt file
			while(getline(file, line)) //count size line by line
				counter++;
			return counter;
		}
		
		//display contents directly from txt file
		void display()
		{
			string line, content;
			ifstream file("data.txt");
			while(getline(file, line))
				content += myMethod.splitValue(line, 1) + ", " + 
				myMethod.splitValue(line, 2) + " " + 
				myMethod.splitValue(line, 3) + " - " + 
				myMethod.splitValue(line, 5) + "yo " + 
				myMethod.splitValue(line, 4) + " " +
				myMethod.splitValue(line, 6) + "\n";
			cout<<content<<endl<<endl;
			file.close();
		}
		
};

