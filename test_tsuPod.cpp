/****************************************************
Name: Aidan Dobkins
Date: 04/23/2020
Problem Number: #6
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>

#include "tsuPod.h"
#include "Song.h"

using namespace std;

int main()
{
    int totalSongs = 0;
    int totalMem = 0;



	TsuPod tsuPod(256);	//setting max memory size to 256mb

	cout << "Initializing" << endl;
	int retCode = tsuPod.initTsuPod(); //initialization
	if(retCode == 1)
	{
		cout << "Initialization failed";
		return 1;
	}

	retCode = tsuPod.showSongList();

	cout << endl;

	// Adding songs successfully to list
	cout << "Adding songs to list" << endl;
   	retCode = tsuPod.addSong("Song1", "Bon Jovi1", 4, 1);
    retCode = tsuPod.addSong("Song2", "Bon Jovi4", 7, 2);
    retCode = tsuPod.addSong("Song3", "Bon Jovi6", 5, 3);
    retCode = tsuPod.addSong("Song4", "Bon Jovi4", 8, 4);
    retCode = tsuPod.addSong("Song5", "Bon Jovi7", 7, 5);
    retCode = tsuPod.addSong("Song6", "Bon Jovi5", 12, 6);
    retCode = tsuPod.addSong("Song7", "Bon Jovi3", 9, 7);
    retCode = tsuPod.addSong("Song8", "Bon Jovi2", 4, 8);
	retCode = tsuPod.addSong("Song9", "Bon Jovi9", 4, 9);

	cout << "Return Code: " << retCode << endl << endl;

	tsuPod.showSongList();

    cout << endl;

	retCode = tsuPod.addSong("Song9", " ", 4, 10);
	//the artist is blank, error, unsuccessful song addition

	cout << endl;

	cout << "Sorted Song List" << endl;

	tsuPod.sortSongList();
	// Sorting the list of songs

	cout << endl;

	tsuPod.showSongList();

	cout << endl;

	cout << "Shuffled song list" << endl << endl;

	tsuPod.shuffle();
	//Showing shuffle functionality

    tsuPod.showSongList();

	cout << endl;

	cout << "Total memory: " << tsuPod.getTotalMemory() << endl;				// Shows Total memory used
	cout << "Remaining memory: " << tsuPod.getRemainingMemory() << endl << endl;		// Shows remaining memory

	retCode = tsuPod.removeSong(" ", "Bon Jovi", 8, 4);
	// Unsuccessful song deletion, Title can't be blank

	cout << "Total memory: " << tsuPod.getTotalMemory() << endl;
	cout << "Remaining memory: " << tsuPod.getRemainingMemory() << endl << endl;

	retCode = tsuPod.removeSong("Song4", "Bon Jovi4", 8, 4);
	//Successful song deletion

	cout << "Total memory: " << tsuPod.getTotalMemory() << endl;
	cout << "Remaining memory: " << tsuPod.getRemainingMemory() << endl << endl;

	tsuPod.showSongList();

	tsuPod.clearSongList();//clearing song list

	cout << endl;

	cout << "Song list clear" << endl << endl;

	tsuPod.showSongList();

	return 0;
}
