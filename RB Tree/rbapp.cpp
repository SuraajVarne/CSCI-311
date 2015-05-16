/**
 * @file rbapp.cpp this is a process file where it takes 
						input and calls the rbtree file.
 * 
 * Desc: This is basically where it will take input
			then trim the string according to the 
			requirement and calls the appropriate 
			command.
 * 
 * @author Pritesh Jagani
 * @date 04/18/15
 */
#include "rbapp.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



/************************************************
Function: Main()

Desc: This is the main function of the program
	program starting point.

**************************************************/
int main()
{
	RBapp r;
	r.mainLoop();

	return 0;
}
/************************************************
Function: Constructor

Desc: This constructor will set all the variables values.

**************************************************/
 
RBapp::RBapp()
{
	done=false;
}

/************************************************
Function: MainLoop()

Desc: This function is used to call the processcommand till
	end of file.

**************************************************/
void RBapp::mainLoop()
{
	while(!cin.eof()&& !done)
	processCommand();
}

/************************************************
Function: processCommand()

Desc: This function process the input and 
	based on command it calls the 
	appropriate function.

**************************************************/
void RBapp::processCommand()
{
	string inputString;

	getline(cin, inputString);	//This is used to take input.
        
	//It is used to find the first space in the string                     
	string command = inputString.substr(0, inputString.find(' '));  
	
	if (command.compare("insert")==0)
	{
	processInsert(inputString);
	}
	else if (command.compare("find")==0)
	{
	processFind(inputString);
	}
	else if (command.compare("delete")==0) 
	{
	processDelete(inputString);
	}
	else if (command.compare("print")==0) 
	{
	processPrint();
	}
	else if (command.compare("quit")==0) 
	{
	
	processQuit();
	}
}


/**********************************
Function: processInsert()
Desc: This function is used to take string as input and inserts the node in the tree.
************************************/
void RBapp::processInsert(string& input)
{
	
	input.erase(0, input.find(' ') + 1);		//It will find the first space.
	
	string key = input.substr(0, input.find(' '));	//It will save the key finded after space.

	input.erase(0, input.find(' ') + 1);

	myRBT.rbInsert(key, input);

}
/**********************************
Function: processFind()

Desc: This function finds the node from the tree by given input.
************************************/

void RBapp::processFind(string& input)
{
	vector<const string*> SearchKey;

	//Iterator is used to iterate through the vector.
	vector<const string*>:: iterator iterator;		

	input.erase(0, input.find(' ')+1);

  	string key=input.substr(0, input.find(' '));
	
	input.erase(0, input.find(' ') + 1);
	
	SearchKey=myRBT.rbFind(key);


	for(iterator=SearchKey.begin();iterator<SearchKey.end();iterator++)
	{
		cout<<input<<" "<<*(*iterator)<<endl;
	}
}


/**********************************
Function: processPrint()

Desc: This function is used to find the print the tree.
************************************/
void RBapp::processPrint()
{
	myRBT.rbPrintTree();
}

/**********************************
Function: processDelete()

Desc: This function is used to delete the note from the tree by given input.
************************************/

void RBapp::processDelete(string& input)
{
		input.erase(0, input.find(' ')+1);

      string key=input.substr(0, input.find(' '));

      input.erase(0 , input.find(' ')+1);

      string data=input;

    	myRBT.rbDelete(key,data);
	
}
/**********************************
Function: processQuit()
Desc: This function is used exit from the program.
************************************/
void  RBapp::processQuit()
{
	done =true;
}

