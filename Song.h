#pragma once

#include <string>
using namespace std;

class Song {
public:
	Song(string songTitle = "noTitle", string firstLine = "noFirstLine", int numPlays = 0);
	~Song();
	string GetTitle();
	string GetFirstLine();
	int GetNumPlays();
	void PlaySong();
private:
	string songTitle;
	string firstLine;
	int numPlays;
};

