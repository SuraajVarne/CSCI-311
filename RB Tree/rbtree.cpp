/**
 * @file rbtree.cpp This is a file where all the algorithm 
							is written
 * 
 * Desc: This file is used to initialise all 
			constructor and destructors.
			It will have all the algorithms to do 
			Insert, Find, and Delete.
 * 
 * @author Pritesh Jagani
 * @date 04/18/15
 */

#include <iostream>
#include <iomanip>
#include "rbtree.h"
#include <vector>

using std::cout;
using std::setw;
using std::endl;


/***********************************

Function: RbPrintTree()
Desc: This function is used to call the print function
		based on certain condition.
***********************************/
void RBTree::rbPrintTree()
{
	if (root == nil)
	{
		//cout << "Tree is empty" << endl;
	}
	else
	{
		reverseInOrderPrint(root, 0);
	}
}
/***********************************

Function: reverseInOrderPrint()

Desc: This function is used to print the tree
		in post order traversal.
***********************************/
void RBTree::reverseInOrderPrint(Node *x, int depth) {
   if ( x != nil ) {
      reverseInOrderPrint(x->right, depth+1);
      cout << setw(depth*4+4) << x->color << " ";
      cout << *(x->key) << " " << *(x->value) << endl;
      reverseInOrderPrint(x->left, depth+1);
   }
}
/***********************************

Function: deleteDestructor()

Desc: This function is to do post traversal and delete 
		whole tree.
***********************************/

void RBTree::deleteDestructor(Node* x)
{
if ( x != nil ) {
      deleteDestructor(x->right);
      
      deleteDestructor(x->left);
		delete x;
	}
}
/***********************************

Function: RBTree()

Desc: This is constructor used for initialising 
		node.
***********************************/
RBTree::RBTree()
{
	nil = new Node();
	root = nil;

}
/***********************************

Function: Node()

Desc: This is constructor used for initialising 
		node member to the NULL.
***********************************/
RBTree::Node::Node()
{
	key=NULL;
	value=NULL;
	parent=NULL;
	right=NULL;
	left=NULL;
	color='B';
	
}
/***********************************

Function: RBTree()

Desc: This is constructor used for initialising 
		node's member.
***********************************/
RBTree::Node::Node(const string& key, const string& value, Node *nil)
{
	
	parent=nil;
	right=nil;
	left=nil;
	color='R';
	string tempkey = key;
	string tempvalue = value;
	this->key = new string(tempkey);
	this->value = new string(tempvalue);
}

/***********************************

Function: ~RBTree()

Desc: This is destructor used for deleting all the node.
***********************************/
RBTree::~RBTree()
{
	deleteDestructor(root);
	delete nil;
	//cout<<"Root value"<<*root->value<<endl;
}

/***********************************

Function: ~Node()

Desc: This is destructor used for deleting the string
***********************************/
RBTree::Node::~Node()
{
	delete key;
	delete value;
}
/***********************************

Function: rbInsert()

Desc: This function creates the new node and calls the 
		Insert function to insert the node into the tree.
***********************************/

void RBTree::rbInsert(const string& key, const string& value)
{
	Node *tempNode = new Node(key, value, nil);
	rbInsert(tempNode);
}

/***********************************

Function: rbInsert()

Desc: This function is used to insert the node into the tree.
***********************************/
void RBTree::rbInsert(Node *z)
{
	Node *x, *y;
	y = nil;
	x = root;
	while (x != nil)
	{
		y = x;
		if (*(z->key)<*(x->key))
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if (y == nil)
	{
		root = z;
	}
	else if (*(z->key)<*(y->key))
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
	z->left = nil;
	z->right = nil;
	z->color = 'R';
	rbInsertFixup(z);
}
/***********************************

Function: rbInsertFixup()

Desc: This function is used to fix the structure of the tree.
***********************************/
void RBTree::rbInsertFixup(Node *z)
{
	Node *y;
	while (z->parent->color == 'R')
	{
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y->color == 'R')  //case 1
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else if (z == z->parent->right) //case 2
			{
				z = z->parent;
				leftRotate(z);
			}
			else //Case 3
			{
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				rightRotate(z->parent->parent);
			}
		}
		else
		{
			y = z->parent->parent->left;
			if (y->color == 'R')  //case 4 
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else if (z == z->parent->left) //case 5
			{
				z = z->parent;
				rightRotate(z);
			}
			else //Case 6
			{
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = 'B';
}

/***********************************

Function: leftRotate()

Desc: This function is used for balancing the tree by doing
		left rotation
***********************************/
void RBTree::leftRotate(Node *x)
{
	Node *y = x->right;
	x->right = y->left;
	if (y->left != nil)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}
/***********************************

Function: rightRotate()

Desc: This function is used for balancing the tree by doing
		right rotation
***********************************/
void RBTree::rightRotate(Node *x)
{
	Node *y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}

/***********************************

Function: rbTreeMaximum()

Desc: This function is used for finding the maximum node
		of the tree
***********************************/
RBTree::Node* RBTree::rbTreeMaximum(Node* x)
{
	while (x->right != nil)
	{
		x = x->right;
	}
	return x;
}
/***********************************

Function: rbTreeMaximum()

Desc: This function is used for finding the minimum node
		of the tree
***********************************/
RBTree::Node* RBTree::rbTreeMinimum(Node* x)
{
	while (x->left != nil)
	{
		x = x->left;
	}
	return x;
}
/***********************************

Function: rbTreePredecessor()

Desc: This function is used for finding the predecessor node
		of the tree
***********************************/
RBTree::Node* RBTree::rbTreePredecessor(Node *x)
{
	Node *y;
	if (x->left != nil)
	{
		return rbTreeMaximum(x->left);
	}
	y=x->parent;
	while(y!=nil && (x==y->left))
	{
		x=y;
		y=y->parent;
	}
	return y;

}
/***********************************

Function: rbTreeSuccessor()

Desc: This function is used for finding the successor node
		of the tree
***********************************/
RBTree::Node* RBTree::rbTreeSuccessor(Node *x)
{
	
	if (x->right != nil)
	{
		return rbTreeMinimum(x->right);
	}
	Node *y;
	y=x->parent;
	while(y!=nil && (x==y->right))
	{
		x=y;
		y=y->parent;
	}
	return y;
	

}



/*



vector<Node*> RBTree::rbdeleteFind(const string& key, const string& value)
{
	
	Node *temp = root;
	Node *tempNode, *temp1;
	vector<const string*> KeySearch;
	vector<Node*> tempVector;
	tempNode = rbTreeSearch(temp, key);
	temp = tempNode;
	temp1 = tempNode;

	if (tempNode != nil)
	{
		tempVector.push_back(tempNode);
		
		while ((tempNode = rbTreePredecessor(temp)) != nil)
		{
			if (*(tempNode->key) == key && *(tempNode->value) == value)
			{
				tempVector.push_back(tempNode);
				temp = tempNode;
			}
			else
				break;
		}
		while ((tempNode = rbTreeSuccessor(temp1)) != nil)
		{
			if (*(tempNode->key) == key && *(tempNode->value) == value)
			{
				tempVector.push_back(tempNode);
				temp1 = tempNode;
			}
			else
				break;
		}
	}
	return tempVector;
}
*/
/*
void RBTree::rbDelete(const string& key, const string& value)
{
	vector<Node*> SearchKey;

	//Iterator is used to iterate through the vector.
	vector<Node*>::iterator iter;	

	if (root == nil)
	{
		cout << "There is no node in tree" << endl;
		cout<<value;
	}
	else
	{

		SearchKey=rbdeleteFind(key, value);

		for(iter=SearchKey.begin();iter!=SearchKey.end();iter++)
		{
			rbDelete(*iter);
		}
	}
}
*/
/***********************************

Function: rbTreePredecessor()

Desc: This function is used for finding node 
		and inserting into vector.
***********************************/
vector<const string*> RBTree::rbFind(const string& key)
{
	
	Node *temp = root;
	Node *tempNode, *temp1;
	vector<const string*> KeySearch;
	vector<Node *> tempVector;
	tempNode = rbTreeSearch(temp, key);
	temp = tempNode;
	temp1 = tempNode;

	if (tempNode != nil)
	{
		KeySearch.push_back(tempNode->value);
		
		while ((tempNode = rbTreePredecessor(temp)) != nil)
		{
			if (*(tempNode->key) == key)
			{
				KeySearch.push_back(tempNode->value);
				temp = tempNode;
			}
			else
				break;
		}
		while ((tempNode = rbTreeSuccessor(temp1)) != nil)
		{
			if (*(tempNode->key) == key)
			{
				KeySearch.push_back(tempNode->value);
				temp1 = tempNode;
			}
			else
				break;
		}
	}
	return KeySearch;
}

/***********************************

Function: rbTreeTransplant()

Desc: This function is used for replacing the
		deleting node.
***********************************/
void RBTree::rbTransplant(Node *u, Node *v)
{
	if (u->parent == nil)
	{
		root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	v->parent = u->parent;
}


/***********************************

Function: rbDeleteFixup()

Desc: This function is used to fix the structure of the tree
		after deletion of the tree.
***********************************/

void RBTree::rbDeleteFixup(Node *x)
{
	Node *w;

	while (x != root && x->color == 'B')
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				leftRotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == 'B' && w->right->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			}
			else if (w->right->color == 'B')
			{
				w->left->color = 'B';
				w->color = 'R';
				rightRotate(w);
				w = x->parent->right;
			}
			else
			{
				w->color = x->parent->color;
				x->parent->color = 'B';
				w->right->color = 'B';
				leftRotate(x->parent);
				x = root;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if (w->left->color == 'B' && w->right->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			}
			else if (w->left->color == 'B')
			{
				w->right->color = 'B';
				w->color = 'R';
				leftRotate(w);
				w = x->parent->left;
			}
			else
			{
				w->color = x->parent->color;
				x->parent->color = 'B';
				w->left->color = 'B';
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = 'B';
}

/***********************************

Function: rbTreeSearch()

Desc: This function is used for searching the node
		in the tree.
***********************************/
RBTree::Node* RBTree::rbTreeSearch(Node* x, const string& key)
{
	x=root;
	if(x== nil)
	{
		return x;
	}
	else
	{
	   while (x != nil)
	   {
		if (*(x->key) == key)
		{
			break;
		}
		else if (key<*(x->key))
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	   }
	   return x;
	}
}
/***********************************

Function: rbDelete()

Desc: This function is used for calling the RBdelete(Node)
		by using Rbtreeseach for finding the node.
***********************************/

void RBTree::rbDelete(const string& key, const string& value)
{
	
	if (root == nil)
	{
		cout << "There is no node in tree" << endl;
		cout<<value;
	}
	else
	{
		Node *node;
		//temp=key;
		Node *tempPreNode;
		
		node = rbTreeSearch(root, key);
		while (node != nil)
		{ 
			if(*(node->value)==value)
			{
				//cout<<"RBDELETE: " << *(node->key) << ":" << *(node->value) <<endl;
				rbDelete(node);
				delete(node);
				node = rbTreeSearch(root, key);
			}
			tempPreNode=node;
			while (tempPreNode != nil)
			{
				tempPreNode = rbTreePredecessor(tempPreNode);
				if ((tempPreNode != nil) && *(tempPreNode->key) == key && (*(tempPreNode->value)==value))
					{
						//cout<<"Pre: " << *(tempPreNode->key) << ":" << *(tempPreNode->value) <<endl;
						rbDelete(tempPreNode);
						delete(tempPreNode);
						//cout<<"Delete Done"<<endl;
						tempPreNode=rbTreeSearch(root,key);
						//cout<<"Pred"<<endl;
						//cout<<"TempPreNode"<<*(tempPreNode->key)<<endl;
					}
			}
			
			//cout<<"After Pred"<<endl;
			Node *tempSucNode;
			tempSucNode=rbTreeSearch(root,key);
			while (tempSucNode != nil)
			{
				tempSucNode = rbTreeSuccessor(tempSucNode);
				if ((tempSucNode != nil) && *(tempSucNode->key) == key && (*(tempSucNode->value)==value))
					{
						//cout<<"Suc: " << *(tempSucNode->key) << ":" << *(tempSucNode->value) <<endl;
						rbDelete(tempSucNode);
						delete(tempSucNode);
						tempSucNode=rbTreeSearch(root,key);
					}
			}
			node=rbTreeSearch(root,key);
			if(rbTreeSearch(root,key)!=nil)
			{
				if(*(node->value)!=value)
					break;
			}
		
		}
	}
}

/***********************************

Function: rbTreeDelete()

Desc: This function is used for deleting the node
		in the tree.
***********************************/
void RBTree::rbDelete(Node *z)
{
	Node *y, *x;
	y = z;
	char original_color = y->color;
	if (z->left == nil)
	{
		x = z->right;
		rbTransplant(z, x);
	}
	else if (z->right == nil)
	{
		x = z->left;
		rbTransplant(z, x);
	}
	else
	{
		y = rbTreeMaximum(z->left);
		original_color = y->color;
		x = y->left;
		if (y->parent == z)
			x->parent = y;
		else
		{
			rbTransplant(y, y->left);
			y->left = z->left;
			y->left->parent = y;
		}
		rbTransplant(z, y);
		y->right = z->right;
		y->right->parent = y;
		y->color = z->color;
	}
	if (original_color == 'B')
		rbDeleteFixup(x);
}


