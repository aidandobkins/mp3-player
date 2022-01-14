/****************************************************
Name: Aidan Dobkins
Date: 04/23/2020
Problem Number: #6
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef TSUPOD_H_
#define TSUPOD_H_

#include "Song.h"
#include <string>
#include <fstream>

using namespace std;

class TsuPod
{
private:
	Song song;
	int numSongs;
	int maxSize;
	int currentMemory;
    struct ListNode
    {
        Song s;
        struct ListNode *next;
    };
    ListNode *head;
public:
	TsuPod();
	TsuPod(int);
	int initTsuPod();
	int addSong(string, string, int, int);
	int removeSong(string, string, int, int);
	int clearSongList();
	int showSongList();
	int shuffle();
	int sortSongList();
	int getTotalMemory() const;
	int getRemainingMemory() const;
	int getNumSongs() const;
	int closeFile();
	void setSong(Song);
};

#endif /* TSUPOD_H_ */
