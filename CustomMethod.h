#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

class CustomMethod
{
	public:
		
		//Extend string in maximum length
		string newLength(string str, int max)
		{
			int len = str.size();
			int diff = max-len;
			
			//add whitespace to end til reach maximum
			for (int i=0; i<diff; i++) str += " ";
			return str;
		}
		
		//Convert integer into string
		string IntToString(int x)
		{
		    ostringstream temp;
		    temp<<x;
		    return temp.str();
		}
		
		//Split values by % character
		string splitValue(string str, int x)
		{
			int num=0;
			string val;
			
			//loop til the end of str length
			for (int i=0; str.length(); i++)
			{
				//check if character is equal to the separator (%)
				if (str[i] == '%')
				{
					num++;
					if (num != x) val = ""; //clear value from prev collecting of character
				}
				if (num == x) break;
				if (str[i] != '%') val += str[i]; //keep on collecting character if not separator (%)
			}
			return val;
		}
		
};
