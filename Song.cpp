#include "Song.h"

#include <iostream>
#include <string>
using namespace std;


Song::Song(string initTitle, string initFirstLine, int initNumPlays) {
	songTitle = initTitle;
	firstLine = initFirstLine;
	numPlays = initNumPlays;
}


Song::~Song() {
	// cout << "Deleted \"" << songTitle << "\"" << endl;	//For troubleshooting
}

string Song::GetTitle() {
	return songTitle;
}

string Song::GetFirstLine() {
	return firstLine;
}

int Song::GetNumPlays() {
	return numPlays;
}

void Song::PlaySong() {
	cout << firstLine << endl;
	numPlays++;
}
