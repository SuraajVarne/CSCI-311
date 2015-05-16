/**
 * @file MinPriority.h:This file contains all the functionality
								of the program.
 * Desc: It has all the functions which is used to 
			build the prirority queue and do the
			further functionality.

 * @author Pritesh Jagani
 * @date 04/28/15
 */
#include <vector>
#include <string>
#include "MinPriority.h"
#include <iostream>

using namespace std;
//This is the constructor of the class.
 MinPriority::MinPriority()
{
	heapsize=-1;
}
//This is the parameterized constructor of the class.
 MinPriority::Element::Element(string v, int k)
 {
	 this->key=k;

	 this->value=v;
 }
//This is the destructor used to release all 
// the memory leaks.
 MinPriority::~MinPriority()
 {
	 /*
		vector<Element>:: iterator itr;

		for(itr=Q.begin(); itr!=Q.end(); itr++)
		{	 
			 delete *itr; 
		}
	*/
 }
/*
Function: insert()
Input: String is the value entered by the user,
		int is the key for the string
Desc: This function is used to insert the element 
		in the queue.
*/
 void MinPriority::insert(string v,int k)
 {
	 //cout<<"Value:"<<v;
	 //cout<<"Key:"<<k;
	 string infinity="Infinity";
	 //int infi=
	 heapsize++;
	 Element *objinfinity = new Element(infinity,1000);
	 Q.push_back(*objinfinity);
	Element *objElement = new Element(v,k);
	Q[heapsize]=*objElement;
	
	 decreasekeyM(v,k);
 }

/*
Function: decreaseKey()
Input: String is the value entered by the user,
		int is the key for the string
Desc: This function is used to update the value and key
		only if the key is less than the current key value.
*/
 void MinPriority::decreasekeyM(string v, int k)
 {
	  Element *objElement = new Element(v,k);
	 
	  

	 if(heapsize == 0)
	 {
		 Q[0]=*objElement;
	 }
	 else
	 {
		 vector<Element>:: iterator itr;

		for(itr=Q.begin(); itr!=Q.end(); itr++)
		{
			cout << "decrease key" << endl;
		 if(v==itr->value && k<itr->key)
		 {
			 
			 itr->key=k;
			 //buildMinHeap();
			 //break;
		 }
		
			 
		
		//
	 
		if(k>Q.at(heapsize).key)
		 {
			 return;

		 }
	 //Q[heapsize]=*objElement;

	 int i= heapsize;

	 Element *temp = new Element(Q[heapsize].value, Q[heapsize].key);

	 while (i>=0 && Q.at(parent(i)).key>Q.at(i).key )
	 {
		 temp->key=Q[i].key;
		 temp->value=Q[i].value;
		 Q[i]=Q[ parent(i)];
		 Q[parent(i)]=*temp;
		 i=parent(i);
		 //i++;
	 }
	 buildMinHeap();
	 }
}
 }

 void MinPriority::print()
 {
	 vector<Element>:: iterator itr;

	 //int i=0;
	 for(itr=Q.begin(); itr!=Q.end(); itr++)
	 {
		cout << itr->value << " ";;
		 // cout<<"String: "<<itr->value<<" Key: "<<itr->key<<endl;
	 }
	 cout << endl;
 }


/*
Function: isMember()
Input: String is the value entered by the user.
Out: True or false based on the results.
Desc: This function is used to check if the string 	
		is present in the queue.
*/
 bool MinPriority::isMember(string v)
 {
	  vector<Element>:: iterator itr;

	 //int i=0;
	 for(itr=Q.begin(); itr!=Q.end(); itr++)
	 {
		 if(v==itr->value)
		 {
			 return true;
		 }
			 
	 }
	 return false;
 }
/*
 void MinPriority::update(string v, int k)
 {
	 vector<Element>:: iterator itr;

	for(itr=Q.begin(); itr!=Q.end(); itr++)
	 {
		 if(v==itr->value)
		 {
			 
			 itr->key=k;
			 break;
		 }
			 
	 }
	buildMinHeap();
 }
*/

/*
Function: parent()
Input: current heapsize index.
Desc: This function is used to return the parent
*/
 int MinPriority::parent(int size)
 {
	 return size/2;

 }

/*
Function: left()
Input: current heapsize index.
Desc: This function is used to return the left of index.
*/
 int MinPriority::left(int size)
 {
	 return 2*size+1;
 }

/*
Function: left()
Input: current heapsize index.
Desc: This function is used to return the left of index.
*/

 int MinPriority::right(int size)
 {
	 return 2*size + 2;

 }

/*
Function: buildMinHeap()

Desc: This function is used to build heap.
*/
 void MinPriority::buildMinHeap()
 {
	 int tempsize=Q.size()/2;
	 int i;
	 for(i=tempsize;i>=0;i--)
	 {
		 minheapify(i);
	 }
 }

/*
Function: minHeapify()
Input: current heapsize index.
Desc: This function is used to balance the heap
		after extracting the minimum element from
		heap.
*/
 void MinPriority::minheapify(int size)
 {
	 int l = left(size);

	 int r=right(size);
		
	 int largest;
	 Element *temp = new Element("Dummy", 0);
	 if(l<=heapsize && Q.at(l).key < Q.at(size).key)
	 {
		 largest=l;
	 }
	 else
	 {
		 largest=size;
	 }
	 if(r<=heapsize && Q.at(r).key <Q.at(largest).key)
	 {
		 largest=r;
	 }
	 if(largest!=size)
	 {
		 temp->key=Q[largest].key;
		 temp->value=Q[largest].value;
		 Q[largest]=Q[ parent(size)];
		 Q[parent(size)]=*temp;
		 minheapify(largest);
	 }
	 
 }
/*
Function: extractmin()
output: Node which is extracted.
Desc: This function is used to extract the minium 
		node from the heap, which is the top element
		of the heap.
*/
 string MinPriority::extractmin()
 {
	 string max;
	 if(heapsize==-1)
	 {
		 return "Empty";
	 }
	 else
	 {
		//cout<<"test  "<<Q.at(0).value<<endl;
		 max=Q.at(0).value;
		 Q.at(0).key= Q.at(heapsize).key;
		 Q.at(0).value=Q.at(heapsize).value;
		Q.erase(Q.begin()+Q.size()-1); 
		heapsize=heapsize-1;
				
		minheapify(0);
		 return max;
	 }
		 

 }

bool MinPriority::isEmpty()
{
	return Q.size() == 0;
}