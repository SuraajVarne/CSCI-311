/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 * 
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger
 * @date 2/1/13
 */

#include <iostream>
#include <string>

#include "playlist.h"
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 */
void Playlist::processCommand() {

	string PlayListCommand;
	getline(cin,PlayListCommand);
	
	//Substr() is used to find the first space in the userinput.
	string command = PlayListCommand.substr(0, PlayListCommand.find(' '));

	//This command will erase the string till the first space
	PlayListCommand.erase(0,PlayListCommand.find(' ') +1);

	//This will save the string after the first space  
	string songname =PlayListCommand.substr();

	//This condition are the check for the commands and forward them to implementation

	if (command == "appendSong")
	{
		dll.append(songname);
	}
	else if(command == "removeSong")
	{
		dll.remove(songname);
	}
	else if(command	== "gotoFirstSong")
	{
		dll.begin();
	}
	else if(command	== "gotoLastSong")
	{
		dll.end();
	}
	else if(command	== "nextSong")
	{
		dll.next();
	}
	else if(command	== "prevSong")
	{
		dll.prev();
	}
	else if(command	== "playReverse")
	{
		cout<<"\nplaying reverse: ";
		cout<<"\n";
		if(!dll.empty())
		cout<<dll.getData();
		cout<<"\n";
		while(dll.prev())
		{
			cout<<dll.getData()+"\n";	
		}
		
	}
	else if(command	== "playForward")
	{
		cout<<"\nplaying forward: ";
		cout<<"\n";
		if(!dll.empty())
		cout<<dll.getData();
		cout<<"\n";
		while(dll.next())
		{
			cout<<dll.getData()+"\n";	
		}
	}
	else if (command == "insertAfter")
	{
		dll.insertAfter(songname);
	}
	else if (command == "insertBefore")
	{
		dll.insertBefore(songname);
	}
	else if(command	== "playCurrent")
	{
		
		cout<<"\nplaying current: ";
		if(!dll.empty())
		{
		string temp= dll.getData();
		cout<<temp+"\n";
		}
		
	}
	else if(command == "gotoSong")
	{
		dll.find(songname);

	}
	else if(command == "Exit")
	{
		exit(0);
	}


}

/**
 * The Playlist main loop will process command lines until eof.
 */  
void Playlist::mainLoop() {
   while (!cin.eof()) processCommand();         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}

