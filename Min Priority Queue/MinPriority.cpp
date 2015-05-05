#include <vector>
#include <string>
#include "MinPriority.h"
#include <iostream>

using namespace std;

 MinPriority::MinPriority()
{
	heapsize=-1;
}
 MinPriority::Element::Element(string v, int k)
 {
	 this->key=k;

	 this->value=v;
 }
 MinPriority::~MinPriority()
 {

 }

 void MinPriority::insert(string v,int k)
 {
	 cout<<"Value:"<<v;
	 cout<<"Key:"<<k;
	 string infinity="Infinity";
	 //int infi=
	 heapsize++;
	 Element *objinfinity = new Element(infinity,1000);
	 Q.push_back(*objinfinity);


	 decreasekeyM(v,k);
 }

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
		 if(v==itr->value)
		 {
			 
			 itr->key=k;
			 buildMinHeap();
			 break;
		 }
			 
		}
		//
	 
		if(k>Q.at(heapsize).key)
		 {
			 return;

		 }
	 Q[heapsize]=*objElement;
	 int i= heapsize;
	 Element *temp = new Element(Q[heapsize].value, Q[heapsize].key);

	 while (i>=1 && Q.at(parent(i)).key>Q.at(i).key )
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

 void MinPriority::print()
 {
	 vector<Element>:: iterator itr;

	 //int i=0;
	 for(itr=Q.begin(); itr!=Q.end(); itr++)
	 {
		 cout<<"String: "<<itr->value<<" Key: "<<itr->key<<endl;
	 }
 }
 
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
 int MinPriority::parent(int size)
 {
	 return size/2;

 }

 int MinPriority::left(int size)
 {
	 return 2*size+1;
 }

 int MinPriority::right(int size)
 {
	 return 2*size + 2;

 }

 void MinPriority::buildMinHeap()
 {
	 int tempsize=Q.size()/2;
	 int i;
	 for(i=tempsize;i>=0;i--)
	 {
		 minheapify(i);
	 }
 }

 void MinPriority::minheapify(int size)
 {
	 int l = left(size);

	 int r=right(size);
		
	 int largest;
	 Element *temp = new Element("Dummy", 0);
	 if(l<heapsize && Q.at(l).key < Q.at(size).key)
	 {
		 largest=l;
	 }
	 else
	 {
		 largest=size;
	 }
	 if(r<heapsize && Q.at(r).key <Q.at(largest).key)
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

 string MinPriority::extractmin()
 {
	 string max;
	 if(heapsize==-1)
	 {
		 return "Empty";
	 }
	 else
	 {
		 max=Q.at(0).value;
		 Q.at(0).key= Q.at(heapsize).key;
		 Q.at(0).value=Q.at(heapsize).value;
		 heapsize=heapsize-1;
		 minheapify(0);
		 return max;
	 }
		 

 }