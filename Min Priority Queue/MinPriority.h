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
	   void print();
	   void update(string, int);

	private:
		 void buildMinHeap();
 		 void minheapify  (int);
		 int parent(int);
		 int left(int);
		 int right(int);
  		 
		 int heapsize;
		 vector<Element> Q;
		 
};