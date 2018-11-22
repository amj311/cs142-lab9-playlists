#pragma once
#include "Song.h"

#include <string>
#include <vector>
using namespace std;

class Playlist {
public:
	Playlist(string listName = "noName");
	~Playlist();
	string GetName();
	void AddSong(Song* newSongPtr);
	void RemoveSong(Song* removeSongPtr);
	void RemoveSong(int removeSongIdx);
	void Print();
	void PlayList();

private:
	string listName;
	vector<Song*> listSongs;
};

