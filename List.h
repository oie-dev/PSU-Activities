#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Directory.h"
using namespace std;

//structure
struct Node
{
	char firstname[50], middlename[50], lastname[50], address[100], contact[20];
	int age;
	struct Node *next;
};

//class
class MyList
{
	private:
		
		//Instantiation, Structure, & Variable
		MyDirectory dir;
		CustomMethod myMethod;
		struct Node *head = NULL;
		struct Node *temp = NULL;
		struct Node *trav = NULL;
		int length;
		char buff[100];
		
		//Changes Saved directly to txt file
		/*Implement in Choices #
		2. Insert 
		4. Delete
		7. Edit */
		void SavedChanges()
		{
			if (head!=NULL)
			{
				dir.clearData();
				trav = head;
				while(trav != NULL)
				{
					//save to file "data.txt"
					dir.save(trav->firstname, trav->middlename, trav->lastname, trav->address, trav->age, trav->contact);
					trav = trav->next;
				}
			}
		}
		
		
	public:
		
		//Constructor
		MyList()
		{
			//Get the size from txt file
		    int size = dir.size();
		    
			//Copy the data to dynamic array from txt file (Directory.h)
		    string *fname = dir.retrieveData(1);
		    string *mname = dir.retrieveData(2);
		    string *lname = dir.retrieveData(3);
		    string *address = dir.retrieveData(4);
		    string *ages = dir.retrieveData(5);
		    string *contacts = dir.retrieveData(6);
		    
		    //Populate List values from txt file
		    for (int i=0; i<size; i++)
		    {
		    	//Allocate memory for temp
		        temp = (struct Node *)malloc(sizeof(struct Node));
		        
		        //Define if still have a memory
		        if (temp != NULL)
		        {
		        	//Copy the data to struct->data from the copied dynamic array
		            strcpy(temp->firstname, fname[i].c_str());
		            strcpy(temp->middlename, mname[i].c_str());
		            strcpy(temp->lastname, lname[i].c_str());
		            strcpy(temp->address, address[i].c_str());
		            temp->age = atoi(ages[i].c_str());
		            strcpy(temp->contact, contacts[i].c_str());
		            temp->next = NULL;
		
		            //Define if there's no list head
					if (head == NULL)
		            {
		                head = temp; // Assign value for head
		                trav = head; // Update trav if head is NULL
		            }
		            //If there's already list head 
					//then assign to the head->next
		            else
		            {
		                while (trav->next != NULL) trav = trav->next;
		                trav->next = temp; // Link the new node to the existing list
		            }
		            
		            //Increment size of the list
		            length++;
		        }
		        else
		        {
		            cout << "Memory Full...";
		            break; // Break the loop if memory is full
		        }
		    }
		}
		
		//1. Add new entry
		void add()
		{	
			//Allocate memory for temp
			temp = (struct Node*)malloc(sizeof(struct Node));
			
			//Copy the data to dynamic array from txt file (Directory.h)
			if (temp != NULL)
			{
				system("cls");
				cout<<" ____ ____ ____ " <<endl;
				cout<<"/  _ ||   ||   |" <<endl;
				cout<<"|  _ || | || | |" <<endl;
				cout<<"|_| |||___/|___/" <<endl <<endl;
				cout<<"< Add New Entry >\n\n";
				
				//Get user input and add into List
				cout<<"First name  : "; cin.getline(temp->firstname, sizeof(temp->firstname));
				cout<<"Middle name : "; cin.getline(temp->middlename, sizeof(temp->middlename));
				cout<<"Last name   : "; cin.getline(temp->lastname, sizeof(temp->lastname));
				cout<<"Address     : "; cin.getline(temp->address, sizeof(temp->address));
				cout<<"Age         : "; cin.getline(buff, sizeof(buff)); 
				int age = atoi(buff); temp->age = age;
				cout<<"Contact #   : "; cin.getline(temp->contact, sizeof(temp->contact));
				
				//Set next container as null
				temp->next=NULL;
				
				//Define if there's no list head
				//then assign head by temp
				if (head==NULL) head=temp;
				else
				{
					//traverse list
					for (trav=head; trav->next != NULL; trav=trav->next);
					trav->next=temp;
				}
				cout<<"\nAdded Successfully...";
				
				//Increment size of the list
				length++;
				
				//save into file named "data.txt" (Directory.h)
				dir.save(temp->firstname, temp->middlename, temp->lastname, temp->address, temp->age, temp->contact);
			}
			else cout<<"Memory Full...";
		}
		
		//2. Insert an entry
		void insert()
		{
			//Allocate memory for temp
			temp = (struct Node*)malloc(sizeof(struct Node));
			
			//Copy the data to dynamic array from txt file (Directory.h)
			if (temp != NULL)
			{
				system("cls");
				cout<<" __ _____  ____ ____ ____ ______" <<endl;
				cout<<"| ||   | |/ ___|| __|| _ ||_   _|" <<endl;
				cout<<"| || | | ||___ || __||   /  | |" <<endl;
				cout<<"|_||_|___||____/|___||_|_|  |_|" <<endl <<endl;
				cout<<"< INSERT AN ENTRY >\n\n";
				cout<<"[Enter number between 1-" <<length+1 <<"] \n>>> ";
				cin.getline(buff, sizeof(buff)); //Get user input item number
				
				int itemNo = atoi(buff); //convert user input to integer
				if (itemNo==0) cout<<"\nInvalid Input...";
				else
				{
					if (itemNo <= (length+1)) //define if itemNumber is not over the size limit
					{
						//Get user input and insert into List
						cout<<"\nFirst name  : "; cin.getline(temp->firstname, sizeof(temp->firstname));
						cout<<"Middle name : "; cin.getline(temp->middlename, sizeof(temp->middlename));
						cout<<"Last name   : "; cin.getline(temp->lastname, sizeof(temp->lastname));
						cout<<"Address     : "; cin.getline(temp->address, sizeof(temp->address));
						cout<<"Age         : "; cin.getline(buff, sizeof(buff)); 
						int age = atoi(buff); temp->age = age;
						cout<<"Contact #   : "; cin.getline(temp->contact, sizeof(temp->contact));
						
						
						//Define if itemNumber is the head
						if (itemNo == 1)
						{
							//Make user input values as head
							temp->next = head;
							head = temp;
						}
						else //if itemNumber is not the head
						{
							int ctr=1;
							//traverse list 'til reach itemNumber
							for(trav=head; trav!=NULL; trav=trav->next, ctr++)
							{
								//define itemNumber 
								if (ctr==itemNo-1)
								{
									//insert values into item number
									temp->next = trav->next;
									trav->next = temp;
									break;
								}
							}
						}
						
						//Increment size of the list
						length++;
						cout<<"\nInsertion Successfully...";
						SavedChanges(); //Make the changes saved at txt file
					}
					else cout<<"\nInvalid Number...";
				}
			}
			else cout<<"Memory Full...";
		}
		
		//3. Display list
		void display()
		{
			int ch=1;
			while(true)
			{
				system("cls");
				cout<<"___  ___ ____ _______  ____  _  ____ ____ __    ____ __ __" <<endl;
				cout<<"| |  | |/ ___||_   _|  |   || |/ ___|| _ || |  /  _ || || |" <<endl;
				cout<<"| |_ | ||___ |  | |    | | || ||___ || __|| |__|  _ | |  | " <<endl;
				cout<<"|___||_||____/  |_|    |___/|_||____/|_|  |___||_| || |__| " <<endl <<endl;
				if (ch==1) display_AtoZ();
				else if (ch==2) display_num();
				else break;
				
				cout<<"\n\n[1] Alphabetical Order \n[2] Sort by Entry Number \n[0] Back \n\n>>> ";
				cin.getline(buff, sizeof(buff));
				ch = atoi(buff);
			}
		}
		
		// Display list through entry number
		void display_num()
		{
			if (head!=NULL)
			{
				cout<<"#\t" <<myMethod.newLength("Firstname", 20) <<"\t" <<myMethod.newLength("Middlename", 20) <<"\t" <<myMethod.newLength("Lastname", 20) <<"\t" <<myMethod.newLength("Age", 3) <<"\t" <<myMethod.newLength("Contact", 11) <<"\t" <<"Address" <<endl;
				cout<<"\n---------------------------------------------------------------------------------------------------------------------------------\n";
				
				int i = 1;
				string data = "";
				trav = head; //assign trav value as head
				while(trav != NULL)
				{
					cout<<endl;
					cout<<i <<"\t";
					//myMethod.newLength(string, fixNum) is use to make a fix length for string,
					//It will add whitespace at the end of text
					//Frm CustomMethod.h - CustomMethod.class
					cout<<myMethod.newLength(trav->firstname, 20) <<"\t";
					cout<<myMethod.newLength(trav->middlename, 20) <<"\t";
					cout<<myMethod.newLength(trav->lastname, 20)<<"\t";
					cout<<myMethod.newLength(myMethod.IntToString(trav->age), 3) <<"\t";
					cout<<myMethod.newLength(trav->contact, 10) <<"\t";
					cout<<trav->address <<endl;
					
					trav = trav->next;
					i++;
				}
				cout<<"\n---------------------------------------------------------------------------------------------------------------------------------\n";
			}
			else cout<<"Empty list...\n";
		}
		
		// Display list in alphabetical order
		void display_AtoZ()
		{
			if (head!=NULL)
			{
				cout<<myMethod.newLength("Lastname", 20) <<"\t" <<myMethod.newLength("Firstname", 20) <<"\t" <<myMethod.newLength("Middlename", 20) <<"\t" <<myMethod.newLength("Age", 3) <<"\t" <<myMethod.newLength("Contact", 11) <<"\t" <<"Address" <<endl;
				cout<<"\n---------------------------------------------------------------------------------------------------------------------------------\n";
				
				int i=0, max=dir.size();
				string list[max];
				string temp;
				trav = head;
				while(trav != NULL)
				{
					//Assign value for list arry - concatenated with diff information
					list[i] = myMethod.newLength(trav->lastname, 20) + "\t"
					+ myMethod.newLength(trav->firstname, 20) + "\t"
					+ myMethod.newLength(trav->middlename, 20) + "\t"
					+ myMethod.newLength(myMethod.IntToString(trav->age), 3) + "\t"
					+ myMethod.newLength(trav->contact, 10) + "\t"
					+ trav->address;
					trav = trav->next;
					i++;
				}
				
				//Bubble Sort - Sorting alphabetically
				for (int i=0; i<max-1; i++)
				{
					for (int j=0; j<max-i-1; j++)
					{
						if (list[j] > list[j+1])
						{
							//swap list[j] and list[j+1]
							temp = list[j];
							list[j] = list[j+1];
							list[j+1] = temp;
						}
					}
				}
				
				//Display
				for (int i=0; i<max; i++) cout<<endl <<list[i] <<endl;
				cout<<"\n---------------------------------------------------------------------------------------------------------------------------------\n";
			}
			else cout<<"Empty list...\n";
		}
		
		//4. Delete
		void remove()
		{
			if (head != NULL)
			{
				system("cls");
				cout<<"_____ ____ ___  ____ ______ ____ " <<endl;
				cout<<"|    || __|| |  | __||_   _|| __|" <<endl;
				cout<<"| |  || __|| |_ | __|  | |  | __|" <<endl;
				cout<<"|____/|___||___||___|  |_|  |___|" <<endl <<endl;
				cout<<"< DELETE AN ENTRY >\n\n";
				cout<<"[ Enter Lastname ]\n>>> ";
				cin.getline(buff, sizeof(buff));
				cout<<endl;
				
				//add 2 temp holder
				struct Node *previous = NULL;
				struct Node *current = head;
				
				//check if not empty
				while(current != NULL)
				{
					//check if input value is equal to any lastname from the list
					if (strcmp(buff, current->lastname)==0)
					{
						if (previous == NULL) head = current->next;
						else previous->next = current->next;
						
						cout<<current->lastname <<", " <<current->firstname <<", " <<current->middlename <<" Removed!";
						free(current);
						length--;
						SavedChanges();
						break;
					}
					previous = current;
					current = current->next;
				}
				if (current == NULL) cout<<"No entry found...";
			}
			else cout<<"Empty list...\n";
		}
		
		//5. Search
		void search()
		{
			if (head!=NULL)
			{
				system("cls");
				cout<<" ____ ____  ____ ____ _____ __  __" <<endl;
				cout<<"/ ___|| __|/  _ || _ ||  __|| |_| |" <<endl;
				cout<<"|___ || __||  _ ||   /| |__ |  _  |" <<endl;
				cout<<"|____/|___||_| |||_|_||____||_| |_|" <<endl <<endl;
				cout<<"< SEARCH AN ENTRY >\n\n";
				cout<<"Enter Lastname \n>>> ";
				cin.getline(buff, sizeof(buff));
				cout<<endl;
				
				trav = head;
				while (trav != NULL)
				{
					//Check if user input value is equal to any lastname from the list
					//Then, display if it find the very first item while traversing
					if (strcmp(buff, trav->lastname)==0)
					{
						cout<<"Firstname   : " <<trav->firstname <<endl;
						cout<<"Middlename  : " <<trav->middlename <<endl;
						cout<<"Lastname    : " <<trav->lastname <<endl;
						cout<<"Address     : " <<trav->address <<endl;
						cout<<"Age         : " <<trav->age <<" yo" <<endl;
						cout<<"Contact #   : " <<trav->contact <<endl;
						break;
					}
					trav = trav->next;
				}
				if (trav == NULL) cout<<"No entry found...";
			}
			else cout<<"Empty list...\n";
		}
		
		//6. Find
		void find()
		{
			if (head!=NULL)
			{
				system("cls");
				cout<<"_____ __ _____ _____ " <<endl;
				cout<<"| __|| ||   | ||    | " <<endl;
				cout<<"| __|| || | | ||  | | " <<endl;
				cout<<"|_|  |_||_|___||____/" <<endl <<endl;
				cout<<" < FIND ENTRIES > \n\n";
				cout<<"[Enter : Lastname, Middlename, Firstname, Address or Contact Number] \n>>> ";
				cin.getline(buff, sizeof(buff));
				cout<<endl;
				
				bool isFind;
				string str = buff;
				if (str.length() > 1)
				{
					trav = head;
					while (trav != NULL)
					{
						//Check if input value is equal in any of fnames, mnames, lnames, address, & contacts
						//then it will display all entries equally to the input value
						if (strcmp(buff, trav->firstname)==0 || strcmp(buff, trav->middlename)==0 || strcmp(buff, trav->lastname)==0 || strcmp(buff, trav->address)==0 || strcmp(buff, trav->contact)==0)
						{
							cout<<"Firstname   : " <<trav->firstname <<endl;
							cout<<"Middlename  : " <<trav->middlename <<endl;
							cout<<"Lastname    : " <<trav->lastname <<endl;
							cout<<"Address     : " <<trav->address <<endl;
							cout<<"Age         : " <<trav->age <<" yo" <<endl;
							cout<<"Contact #   : " <<trav->contact <<endl;
							cout<<endl;
							isFind = true;
						}
						trav = trav->next;
					}
				}
				if (!isFind) cout<<"No entry found...";
			}
			else cout<<"Empty list...\n";
		}
		
		//7. Edit
		void edit()
		{
			if (head != NULL)
			{
				system("cls");
				cout<<"____ _____ __ ______" <<endl;
				cout<<"| __||    || ||_   _|" <<endl;
				cout<<"| __|| |  || |  | |" <<endl;
				cout<<"|___||____/|_|  |_|" <<endl <<endl;
				cout<<"< EDIT AN ENTRY > \n\n";
				cout<<"Enter Lastname\n>>> ";
				cin.getline(buff, sizeof(buff));
				cout<<endl;
				
				bool noEntry = true;
				trav = head;
				while(trav != NULL) 
				{
					//compare input value in list of lastnames
					if (strcmp(buff, trav->lastname)==0)
					{
						cout<<"First name  : "; cin.getline(trav->firstname, sizeof(trav->firstname));
						cout<<"Middle name : "; cin.getline(trav->middlename, sizeof(trav->middlename));
						cout<<"Last name   : "; cin.getline(trav->lastname, sizeof(trav->lastname));
						cout<<"Address     : "; cin.getline(trav->address, sizeof(trav->address));
						cout<<"Age         : "; cin.getline(buff, sizeof(buff)); 
						int age = atoi(buff); trav->age = age;
						cout<<"Contact #   : "; cin.getline(trav->contact, sizeof(trav->contact));
						
						cout<<"\nUpdated Successfully...";
						noEntry = false;
						SavedChanges();
						break;
					}
					trav = trav->next;
				}
				if (noEntry) cout<<"No entry found...";
			}
			else cout<<"Empty list...\n";
		}
		
		//8. Reset
		bool reset()
		{
			if (head != NULL)
			{
				system("cls");
				cout<<"____ ____  ____ ____ ______" <<endl;
				cout<<"| _ || __|/ ___|| __||_   _|" <<endl;
				cout<<"|   /| __||___ || __|  | |" <<endl;
				cout<<"|_|_|| __||____/|___|  |_|" <<endl <<endl;
				cout<<"< RESET LIST >" <<endl <<endl;
				cout<<"Are you sure you want to remove all entries? \n[Y/N] >>> ";
				string input;
				getline(cin, input);
				
				if (input=="Y" || input=="y")
				{
					while (head != NULL)
			        {
			            temp = head; //assign temp as head
			            head = head->next; //assign new head value as gets the ptr next
			            free(temp); //deallocate temp
			        }
			        
			        //Reset is successful
			        length = 0;
			        dir.clearData();
			        cout<<"\nList has been reset." << endl;
			        return true;
				}
			}
			else cout<<"Empty list...\n";
			return false;
		}
		
		//9. Size
		void size()
		{
			if (head != NULL)
			{
				system("cls");
				string strEntry = length>1 ? "entries" : "entry";
				cout<<"< LIST SIZE > \n" <<endl;
				cout<<"Total number of " <<strEntry <<" : " <<length ;
			}
			else cout<<"Empty list...\n";
		}
		
		//10. First Entry
		void first()
		{
			if (head != NULL)
			{
				system("cls");
				cout<<"< FIRST ENTRY >\n\n";
				cout<<"Firstname   : " <<head->firstname <<endl;
				cout<<"Middlename  : " <<head->middlename <<endl;
				cout<<"Lastname    : " <<head->lastname <<endl;
				cout<<"Address     : " <<head->address <<endl;
				cout<<"Age         : " <<head->age <<" yo" <<endl;
				cout<<"Contact #   : " <<head->contact <<endl;
			}
			else cout<<"Empty list...\n";
		}
		
		//11. Last Entry
		void last()
		{
			if (head != NULL)
			{
				
				trav = head; //traverse til reach null in ptr next
				while(trav->next != NULL) trav=trav->next;
				
				system("cls");
				cout<<"< LAST ENTRY >\n\n";
				cout<<"Firstname   : " <<trav->firstname <<endl;
				cout<<"Middlename  : " <<trav->middlename <<endl;
				cout<<"Lastname    : " <<trav->lastname <<endl;
				cout<<"Address     : " <<trav->address <<endl;
				cout<<"Age         : " <<trav->age <<" yo" <<endl;
				cout<<"Contact #   : " <<trav->contact <<endl;
			}
			else cout<<"Empty list...\n";
		}
		
		//Destructor
		~MyList()
		{
			//deallocate memory
			free(head);
			free(trav);
			free(temp);
		}
		
};
