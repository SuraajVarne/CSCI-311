/**
 * @file Doublylinkedlist.cpp   Implemenation of all function for playlist/music.
 * 
 * @brief
 *    Implementation of all the function for music, appending a song in the list,
 *    removing a song, printing the song's name, etc.
 * @author Pritesh Jagani
 * @date 1/27/15
 */

#include<iostream>
#include<string>
#include "playlist.h"
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/***************************************************

Node() is the empty constructor to initialise the nodes

****************************************************/
Doublylinkedlist::Node::Node()
{
	prev=NULL;
	next=NULL;
	data= new string();

}


/***************************************************

Node() is the parameterised constructor to initialise the data and nodes.

****************************************************/
Doublylinkedlist::Node::Node(string &song)
{
	prev=NULL;
	next=NULL;
	data = new string();
	(*data).assign(song);
}

/***************************************************

~Node() is the destructor to free the memory by deleting the data

****************************************************/
Doublylinkedlist::Node::~Node()
{
	delete data;
}

/***************************************************

Doublylinkedlist() is the empty constructor to initialise the nodes

****************************************************/
Doublylinkedlist::Doublylinkedlist()
{
	head=NULL;
	tail=NULL;
	current=NULL;
}

/***************************************************

Doublylinkedlist() is the empty constructor to initialise the nodes

****************************************************/
Doublylinkedlist::~Doublylinkedlist()
{
	Node *tempnode;
	while(head!=NULL)
	{
		tempnode=head;
		head=head->next;
       		delete tempnode;
	}
    
}

/***************************************************

Empty(): This method is used to find whether list is empty or not

****************************************************/
bool Doublylinkedlist::empty()
{
	if(head==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/***************************************************

Begin(): This method is used to set the current node to begining.

****************************************************/
void Doublylinkedlist::begin()
{
	if(!empty())
	{
		current=head;
	}
}

/***************************************************

end(): This method is used to set the current node to the end

****************************************************/
void Doublylinkedlist::end()
{
	if(!empty())
	{
		current=tail;
	}
}

/***************************************************

next(): This method is used to move the current position to the next song,
	if one exists, otherwise the current song is unchanged.

****************************************************/

bool Doublylinkedlist::next()
{
	if(!empty())
	{	
		if(current->next!=NULL)
		{
		  current=current->next;
		  return true;
		}
	}
	return false;
	
}
	
/***************************************************

prev(): This method is used to move the current position to the previous song,
	if one exists, otherwise the current song is unchanged.

****************************************************/


bool Doublylinkedlist::prev()
{
	if(!empty())
	{
		if(current->prev!=NULL)
		{
		  current=current->prev;
		  return true;	
		}
	}
	return false;
		
	
}
/***************************************************

find(): This method is used to find the song given by user. 

****************************************************/
bool Doublylinkedlist::find(string &song)
{
	string str= song;
	Node *temp;
	temp= head;
	bool flag=false;
	if(!empty())
	{
		while(temp!=NULL)
		{
			if(*temp->data==str)
			{
			  flag= true;
			  current=temp;
			  break;
			}
			else
			{
			  temp=temp->next;
			}
		
		}
	}
	return flag;
	
}

/***************************************************

append(): This method is used to add the song to end of the list.

****************************************************/
void Doublylinkedlist::append(string &song)
{

	string str= song;
	Node *tempnode= new Node();
	tempnode= new Node(str);
	
	if(head==NULL)
	{
		head= tempnode;
		tail= tempnode;
		current= head;
	
	}
	else
	{
		tail->next=tempnode;
		tempnode->prev=tail;
		tail=tail->next;
		current=tail;
	}
}


/***************************************************

insertafter(): This method is used to add the song after a particular song in the list.

****************************************************/
void Doublylinkedlist::insertAfter(string &song)
{

	string str= song;
	Node *tempnode= new Node();
	tempnode = new Node(str);
	Node *tempCurrent= current;
	
	if(empty())
	{
		tail=tempnode;
		head=tempnode;
		current=head;
	}
	else
	{
		if(current->next==NULL)
		{
			current->next=tempnode;
			tempnode->prev=current;
			current=current->next;
			tail=current;
		}
		else
		{
			tempCurrent=tempCurrent->next;
			current->next=tempnode;
			tempnode->prev=current;
			tempCurrent->prev=tempnode;
			tempnode->next=tempCurrent;
			current=tempnode;
			
			
		}
	}
}

/***************************************************

insertbefore(): This method is used to add the song before a particular song in the list.

****************************************************/
void Doublylinkedlist::insertBefore(string &song)
{


	string str= song;
	Node *tempnode= new Node();
	tempnode = new Node(str);
	Node *tempCurrent= current;
	
	if(empty())		
	{	
		
		tail=tempnode;
		head=tempnode;
		current=head;
	}
	else
	{
		if(current->prev==NULL)
		{
			
			current->prev=tempnode;
			tempnode->next=current;
			current=current->prev;
			head=current;
		}
		else
		{
			
			tempCurrent=tempCurrent->prev;
			current->prev=tempnode;
			tempnode->next=current;
			tempCurrent->next=tempnode;
			tempnode->prev=tempCurrent;
			current=tempnode;
			
			
		}
	}

		
}

/***************************************************

remove(): This method is used to remove the song from the list.

****************************************************/
void Doublylinkedlist::remove(string &song)
{

	string str= song;
	Node *temp = new Node();
	Node *tempTail = new Node();
	Node *tempCurrent= new Node();
	Node *tempNode= new Node();
	tempTail=tail;
	temp=head;
	if(!empty())
	{
	  bool tempFind=find(str);
          if(tempFind==true)
	    {
		if(current==head)			//This is to check if song to be deleted is the head
		{
			//cout<<"Head Condition";
			temp=temp->next;
			delete head;
			head=temp;
			
			if(empty())			//This is to check if the node to be deleted is only song in the list
			{
			  head=NULL;
			  tail=NULL;
			  current=NULL;
			}
			else
			{
			  head->prev=NULL;
			  current=head;
			}
		}
		else if(current==tail)			//This is to check if the node to be deleted is the tail of the list
		{
			//cout<<"tail condition";
			tempTail=tempTail->prev;
			delete tail;
			tail =tempTail;
			tempTail->next=NULL;
			current=tail;
		
			
		}	
		else					//This condition is to check if the node is in between
		{
			//cout<<"Find Condition";
			
				
				
				tempCurrent=current;
				tempNode= current;
				tempNode= tempNode->next;
				current=current->prev;
				
				current->next=tempNode;
				tempNode->prev=current;
				delete tempCurrent;
				current=tempNode;
				
				
			
		}
	  }
	}


}


/***************************************************

getData(): This method is used to get the current data from the list.

****************************************************/
const string& Doublylinkedlist::getData()
{
    if(head!=NULL)
    {
	if(current!=NULL)
	{
 		return *current->data;
	}
	else
    	{
		return NULL;
	}
    }
    else
    {
	return NULL;
    }
}


