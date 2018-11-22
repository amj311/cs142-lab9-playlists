/*
     ;;;;;;;;;;;;;;;;;;;
     ;;;;;;;;;;;;;;;;;;;
     ;                 ;
     ;                 ;
     ;                 ;
     ;                 ;
     ;                 ;
     ;                 ;
     ;                 ;
,;;;;;            ,;;;;;
;;;;;;            ;;;;;;
`;;;;'            `;;;;'

Main Lab 9 - Playlists
Created by: Arthur Judd, amjudd315@gmail.com
Created using VS

Memory for songs freed at: main.cpp 260, main.cpp 136
*/

#include <iostream>
#include <string>
#include <limits>
#include <vector>

#include "Playlist.h"
#include "Song.h"

using namespace std;

//For validating getline inputs.
void ValidGetLine(string& targetStr, const string promptStr, const string failStr) {
	cout << promptStr << endl;
	getline(cin, targetStr);
	if (targetStr == "" || targetStr == " ") {
		getline(cin, targetStr);
	}

	while (cin.fail()) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetStr;
	}

	return;
}

//Input cin for strings
void ValidCin(string& targetStr, const string promptStr, const string failStr) {
	cout << promptStr;
	cin >> targetStr;
	cout << endl;

	while (cin.fail()) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetStr;
	}

	return;
}

//Input cin for integers
void ValidCin(int& targetInt, const string promptStr, const string failStr, const int minInt = 0, const int maxInt = 0) {
	cout << promptStr;
	cin >> targetInt;
	cout << endl;

	while (cin.fail() || targetInt < minInt || (maxInt != 0 && targetInt > maxInt)) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetInt;
	}

	return;
}
//Input cin for doubles
void ValidCin(double& targetDouble, const string promptStr, const string failStr, const double minDouble = 0, const double maxDouble = 0) {
cout << promptStr;
cin >> targetDouble;
cout << endl;

while (cin.fail() || targetDouble < minDouble || (maxDouble != 0 && targetDouble > maxDouble)) {
	// Clear error state
	cin.clear();

	// Ignore characters in stream until newline
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << failStr << endl << endl;
	cout << promptStr;
	cin >> targetDouble;
}

return;
}

//For Printing Playlists
void PrintLists(vector<Playlist> listToPrint) {
	for (unsigned int i = 0; i < listToPrint.size(); i++) {
		cout << i << ": " << listToPrint.at(i).GetName() << endl;
	}
}

//For Printing Library
void PrintLists(vector<Song*> listToPrint) {
	for (unsigned int i = 0; i < listToPrint.size(); i++) {
		cout << i << ": " << listToPrint.at(i)->GetTitle() << endl;
	}
}

// Deletes all songs and playlists before exiting program
void clearMemory(vector<Song*>& libraryToClear) {
	for (int i = libraryToClear.size() - 1; i >= 0; i--) {
		
		//clears memory for each song in loop
		delete libraryToClear.at(i);
	}

	return;
}

int main() {
	string userTask = "";
	vector<Song*> songLibrary;
	vector<Playlist> playlists;

	// Print initial greeting
	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

	ValidCin(userTask, "Enter your selection now: ", "Invalid string userTask.");
	// Main Loop
	do {
		if (userTask == "add") {
			string newSongTitle;
			string newSongFirstLine;

			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;

			do {
				ValidGetLine(newSongTitle, "Song Name: ", "Invalid");
				// STOP handler
				if (newSongTitle == "STOP") {
					break;
				}
				ValidGetLine(newSongFirstLine, "Song's first line: ", "Invalid");

				//Add new song to library
				songLibrary.push_back(new Song(newSongTitle, newSongFirstLine));
			} while (newSongTitle != "STOP");
		}

		else if (userTask == "list") {

			// Print all songs in library with idx, title, and plays.
			for (unsigned int i = 0; i < songLibrary.size(); i++) {
				cout << songLibrary.at(i)->GetTitle()
					<< ": \"" << songLibrary.at(i)->GetFirstLine()
					<< "\", " << songLibrary.at(i)->GetNumPlays() << " play(s)."
					<< endl;
			}
			cout << endl;
		}

		else if (userTask == "addp") {
			string newPlaylistName;

			ValidGetLine(newPlaylistName, "Playlist name: ", "Invalid string newPlaylistName");

			//Creat playlist and add to vector
			Playlist newPlaylist(newPlaylistName);
			playlists.push_back(newPlaylist);
			cout << endl;
		}

		else if (userTask == "listp") {
			PrintLists(playlists);
			cout << endl;
		}

		else if (userTask == "addsp") {
			int idxPlaylist;
			int idxSongPtr;

			PrintLists(playlists);
			ValidCin(idxPlaylist, "Pick a playlist index number: ", "Invalid int idxPlaylist.");

			PrintLists(songLibrary);
			ValidCin(idxSongPtr, "Pick a song index number: ", "Invalid int idxSong.");

			//Adds to selected playlist a pointer to selected song.
			playlists.at(idxPlaylist).AddSong(songLibrary.at(idxSongPtr));
		}

		else if (userTask == "play") {
			int idxPlaylist;

			PrintLists(playlists);
			ValidCin(idxPlaylist, "Pick a playlist index number: ", "Invalid int idxPlaylist.");

			//Plays all songs in selected playlist.
			cout << "Playing first lines of playlist: " << playlists.at(idxPlaylist).GetName() << endl;
			playlists.at(idxPlaylist).PlayList();
		}
		
		else if (userTask == "delp") {
			int idxPlaylist;
			PrintLists(playlists);

			ValidCin(idxPlaylist, "Pick a playlist index number to delete: ", "Invalid int idxPlaylist.");

			// Erases Playlist from list. Not necessary to free memory.
			playlists.erase(playlists.begin() + idxPlaylist);
		}

		else if (userTask == "delsp") {
			int idxPlaylist;
			int idxSongPtr;

			PrintLists(playlists);
			ValidCin(idxPlaylist, "Pick a playlist index number: ", "Invalid int idxPlaylist.");

			playlists.at(idxPlaylist).Print();
			ValidCin(idxSongPtr, "Pick a song index number to delete: ", "Invalid int idxSong.");

			//Removes from selected playlist a pointer to selected song.
			playlists.at(idxPlaylist).RemoveSong(idxSongPtr);
		}
		else if (userTask == "delsl") {
			int idxSongPtr;

			PrintLists(songLibrary);
			ValidCin(idxSongPtr, "Pick a song index number: ", "Invalid int idxSong.");

			//Deletes all pointers to song in any playlist, if found.
			for (unsigned int currList = 0; currList < playlists.size(); currList++) {
				playlists.at(currList).RemoveSong(songLibrary.at(idxSongPtr));
			}

			//Frees memory for Song
			delete songLibrary.at(idxSongPtr);

			//Removes pointer from library
			songLibrary.erase(songLibrary.begin() + idxSongPtr);
		}
		//Print Options Menu in all other cases
		else {
			cout << "add      Adds a list of songs to the library" << endl
				<< "list     Lists all the songs in the library" << endl
				<< "addp     Adds a new playlist" << endl
				<< "addsp    Adds a song to a playlist" << endl
				<< "listp    Lists all the playlists" << endl
				<< "play     Plays a playlist" << endl
				<< "delp     Deletes a playlist" << endl
				<< "delsp    Deletes a song from a playlist" << endl
				<< "delsl    Deletes a song from the library(and all playlists)" << endl
				<< "options  Prints this options menu" << endl
				<< "quit     Quits the program" << endl
				<< endl;
		}

		//Prompt selection
		ValidCin(userTask, "Enter your selection now: ", "Invalid string userTask.");

	} while (userTask != "quit");
	
	clearMemory(songLibrary);

	cout << "Goodbye!";
	//system("pause");
	return 0;
}