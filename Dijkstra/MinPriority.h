/**
 * @file MinPriority.h:This file contains all the method definition
								and declaration
 * Desc: It is the basic structure of the program
			and has all the declarations of the classes
			and functions.

 * @author Pritesh Jagani
 * @date 04/28/15
 */
#include <vector>
#include <string>

using namespace std;

class MinPriority
{
private: class Element{
public:
			int key;
			string value;
public:
				Element( string,int);
		 };
	public:

		MinPriority();

		~MinPriority();
		void insert(string, int);        //minheapinsert prototype
  		         
      void decreasekeyM (string,int);
	   string extractmin();
	   bool isMember(string);
		bool isEmpty();
	   void print();
	  // void update(string, int);

	private:
		 void buildMinHeap();
 		 void minheapify  (int);
		 int parent(int);
		 int left(int);
		 int right(int);
  		 
		 int heapsize;
		 vector<Element> Q;
		 
};
