/****************************************************
Name: Aidan Dobkins
Date: 04/23/2020
Problem Number: #6
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "tsuPod.h"

using namespace std;

// Default constructor
TsuPod::TsuPod()
{
    head = NULL;
    currentMemory = 0;
    numSongs = 0;
}

// Constructor with parameters
TsuPod::TsuPod(int CmaxSize)
{
    head = NULL;
    maxSize = CmaxSize;
    currentMemory = 0;
    numSongs = 0;
}

/*
returns 0 if successful
returns -1 if unsuccessful
*/
int TsuPod::initTsuPod()
{
    bool err_check = 0;

    if(numSongs != 0 || currentMemory != 0)
        err_check = 1;

    return err_check;
}

// FUNCTION - int addSong
// returns 1 if failed due to lack of memory space
// returns 2 if failed due to missing title, artist or size being 0 or negative
int TsuPod::addSong(string strTitle, string strArtist, int size, int songNum)
{
    numSongs = numSongs + 1; //every time a song is added, the number of songs goes up
    currentMemory += size; //counts the running used memory

    if(currentMemory > maxSize)
    {
        currentMemory = currentMemory - size;
        numSongs--;
        return 1;
    }

    if(strTitle == " " || strArtist == " " || size <= 0)
    {
        currentMemory = currentMemory - size;
        numSongs--;
        cout << "Adding Song Failed - Please check the title, artist, and size for correct values." << endl;
        return 2;
    }

    ListNode *newNode,
             *nodeptr;

    newNode = new ListNode;
    newNode->s.setTitle(strTitle);
    newNode->s.setArtist(strArtist);
    newNode->s.setSize(size);
    newNode->s.setPosition(songNum);

    newNode->next = NULL;

    if(!head) //if the first value is null (entire list is empty)
        head = newNode;

    else
    {
        nodeptr = head;

        while(nodeptr->next) //sets nodeptr to the end of the list
            nodeptr = nodeptr->next;

        nodeptr->next = newNode; //sets newNode at the end of the list
    }

    return 0;
}

// FUNCTION - int removeSong
// returns 1 if list is empty
int TsuPod::removeSong(string strTitle, string strArtist, int size, int songNum)
{
    Song s1;
    s1.setTitle(strTitle);
    s1.setArtist(strArtist);
    s1.setPosition(songNum);
    s1.setSize(size);

    int counter = 1;

    if(strTitle == " " || strArtist == " " || size == 0)
    {
        cout << "Removing Song Failed - Please check the title, artist, and size for correct values."
             << endl << endl;
    }

    ListNode *nodeptr,
             *prevNode;

    if(!head)
        return 1;

    if(head->s == s1)
    {
        nodeptr = head->next;
        delete head;
        head = nodeptr;
        cout << "Song removed successfully" << endl << endl;
        currentMemory = currentMemory - size;
        numSongs = numSongs - 1;
    }
    else
    {
        nodeptr = head;

        while(nodeptr != NULL && nodeptr->s != s1)
        {
            prevNode = nodeptr;
            nodeptr = nodeptr->next;
        }

        if(nodeptr != NULL)
        {
            prevNode->next = nodeptr->next;
            delete nodeptr;
            cout << "Song removed successfully" << endl << endl;
            currentMemory = currentMemory - size;
            numSongs = numSongs - 1;
        }
    }

    nodeptr = head;

    while(nodeptr != NULL) //traversing to set positions correctly after deletion
    {
        nodeptr->s.setPosition(counter);
        prevNode = nodeptr;
        nodeptr = nodeptr->next;
        counter = counter+1;
    }


    return 0;
}

/* FUNCTION - int showSongList
	* prints the current list of songs in order from
	  first to last to standard output
	* format - slot #, Title, Artist, size in MB (one song per line)
*/
int TsuPod::showSongList()
{
    ListNode *newNode,
             *nodeptr,
             *prevNode = NULL;

    newNode = new ListNode;

    if(!head)
        return 1;

    else
    {
        nodeptr = head;

        while(nodeptr != NULL)
        {
            cout << "#" << nodeptr->s.getPosition() << " | "
                 << nodeptr->s.getTitle() << ", " << nodeptr->s.getArtist()
                 << " | " << nodeptr->s.getSize() << "MB" << endl;

            prevNode = nodeptr;
            nodeptr = nodeptr->next;
        }
    }

	return 0;
}

/* FUNCTION - int clearMemory
* clears all the songs from memory
*/
int TsuPod::clearSongList()
{
    ListNode *nextNode,
             *nodeptr;

    nodeptr = head;

    while(nodeptr != NULL)
    {
        nextNode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextNode;
    }

    head = NULL;

    return 0;
}



/* FUNCTION - int sortSongList
* sorts the list of songs in TsuPod
input parms - total number of songs
*/

int TsuPod::sortSongList()
{
    ListNode *nodeptr,
             *prevNode;

    Song holderValue;

    bool swapped = 1;

    while(swapped == 1)
    {

        nodeptr = head;

        swapped = 0;

        for(int i = 1; i <= numSongs; i++)
        {
            if(nodeptr->next != NULL)
            {
                prevNode = nodeptr;
                nodeptr = nodeptr->next;
            }

            if(nodeptr->s < prevNode->s) // if the prevnode is less than nodeptr
            {
                holderValue = prevNode->s; //swap the values
                prevNode->s = nodeptr->s;
                nodeptr->s = holderValue;
                swapped = 1;
            }

            prevNode->s.setPosition(i);
        }
    }

	return 0;
}

// FUNCTION - int shuffle
int TsuPod::shuffle()
{
    bool change;
    int *randomnum;
    randomnum = new int[numSongs] = {0}; //declare dynamic array of ints, size of numSongs, set to 0

    for(int i = 0; i < numSongs; i++)
    {
        randomnum[i] = rand() % numSongs + 1;

        do
        {
            change = 0;

            for(int j = 0; j < numSongs; j++) //makes sure the num isnt the same as any other num
            {
                while(randomnum[i] == randomnum[j])
                {
                    if(i != j) // excluding itself
                    {
                        randomnum[i] = rand() % numSongs + 1;
                        change = 1;
                    }
                    else
                        break;
                }
            }
        }
        while(change == 1);
    }

    ListNode *nodeptr,
             *prevNode;

    nodeptr = head;

    Song holderValue;

    bool swapped = 1;

    for(int k = 0; k < numSongs; k++)
    {
        nodeptr->s.setPosition(randomnum[k]);
        nodeptr = nodeptr->next;
    }

    while(swapped == 1)
    {

        nodeptr = head;

        swapped = 0;

        for(int m = 1; m <= numSongs; m++)
        {
            if(nodeptr->next != NULL)
            {
                prevNode = nodeptr;
                nodeptr = nodeptr->next;
            }

            if(nodeptr->s.getPosition() < prevNode->s.getPosition()) // if the position is less
            {
                holderValue = prevNode->s; //swap the values
                prevNode->s = nodeptr->s;
                nodeptr->s = holderValue;
                swapped = 1;
            }
        }
    }
    delete [] randomnum;
	return 0;
}

// Gets number of songs stored in TsuPod
int TsuPod::getNumSongs() const
{
    return numSongs;
}

// returns memory used within TsuPod
int TsuPod::getTotalMemory() const
{
	return maxSize;
}

// returns remaining memory within TsuPod
int TsuPod::getRemainingMemory() const
{
    return (maxSize - currentMemory);
}
