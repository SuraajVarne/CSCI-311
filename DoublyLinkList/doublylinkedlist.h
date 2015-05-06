/**
 * @file doublylinkedlist.h   Declaration of a function for playlist/music.
 * 
 * @brief
 *    Implementation of all the function for music, appending a song in the list,
 *    removing a song, printing the song's name, etc.
 * @author Pritesh Jagani
 * @date 1/27/15
 */
#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>
#include "playlist.h"

using std::string;

class Doublylinkedlist
{

class Node
 {
 public:

	Node *prev;
	Node *next;
	string *data;
	Node();
	Node(string &);
	~Node();

 };
private:
Node *head, *tail, *current;

 public:
	Doublylinkedlist();
     	~Doublylinkedlist();
     	bool empty();
     	void append(string&);
     	void insertBefore(string&);
     	void insertAfter(string&);
     	void remove(string&);
     	void begin();
     	void end();
     	bool next();
     	bool prev();
     	bool find(string&);
     	const string& getData();
	
};

#endif

