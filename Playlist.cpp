#include "Playlist.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

Playlist::Playlist(string initName) {
	listName = initName;
}

Playlist::~Playlist()
{
}

string Playlist::GetName() {
	return listName;
}

//Receives a ptr to add
void Playlist::AddSong(Song* newSongPtr) {
	listSongs.push_back(newSongPtr);
}

//Receives a ptr to search for and remove all instances of.
void Playlist::RemoveSong(Song* removeSongPtr) {
	for (unsigned int currSongPtr = 0; currSongPtr < listSongs.size(); currSongPtr++) {
		if (listSongs.at(currSongPtr) == removeSongPtr) {
			listSongs.erase(listSongs.begin() + currSongPtr);
			currSongPtr--;
		}
	}
}

//Receives an int as an idx to remove from vector.
void Playlist::RemoveSong(int removeSongIdx) {
	listSongs.erase(listSongs.begin() + removeSongIdx);
}

//Prints all song titles with index.
void Playlist::Print() {
	for (unsigned int i = 0; i < listSongs.size(); i++) {
		cout << i << ": " << listSongs.at(i)->GetTitle() << endl;
	}
	cout << endl;
}

//Plays all songs in list.
void Playlist::PlayList() {
	for (unsigned int i = 0; i < listSongs.size(); i++) {
		listSongs.at(i)->PlaySong();
	}
}
