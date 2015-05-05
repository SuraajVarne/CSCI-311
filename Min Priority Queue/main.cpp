#include <vector>
#include <string>
#include <iostream>
#include "MinPriority.h"
using namespace std;

int main()
{
	string command,value;
	int key;
	cout<<"Enter command";
	cin>>command;

	MinPriority Min;

	while(command!="q")
	{

	if(command=="a")
	{
		cout<<"Enter String:";
		cin>>value;
		cout<<"Enter Value:";
		cin>>key;
		Min.insert(value,key);


	}
	else if(command=="d")
	{
		cout<<"Enter String:";
		cin>>command;
		cout<<"Enter Value:";
		cin>>key;

		bool temp=Min.isMember(command);

		if(temp==true)
		{
			cout<<"Value Find :) ";
			Min.decreasekeyM(command,key);
		}

	}
	else if(command=="x")
	{
		string extractnode=Min.extractmin();
		cout<<"Node :"<<extractnode<<endl;
	}
	else if(command=="p")
	{
		Min.print();
	}

	else
	{
		exit(0);
	}
	cout<<"Enter command";
	cin>>command;

	}
}