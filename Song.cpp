/****************************************************
Name: Aidan Dobkins
Date: 04/23/2020
Problem Number: #6
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>

#include "Song.h"

using namespace std;

// Default constructor
Song::Song()
{
	artist = "empty";
	title = "empty";
	size = 0;
	position = 0;
}

// Constructor with parameters
Song::Song(char *cArtist, char *cTitle, int cSize, int cPosition)
{
	artist = cArtist;
	title = cTitle;
	size = cSize;
	position = cPosition;
}

// Sets artist private member within Song object
void Song::setArtist(string songArtist)
{
    artist = songArtist;
}

// Sets title private member within Song object
void Song::setTitle(string songTitle)
{
    title = songTitle;
}

// Sets size private member within Song object
void Song::setSize(int songSize)
{
    size = songSize;
}

// Sets position private member within Song object
void Song::setPosition(int songPosition)
{
    position = songPosition;
}

// Returns artist from Song
const string Song::getArtist() const
{
    return artist;
}

// Returns title from Song
const string Song::getTitle() const
{
    return title;
}

// Returns size from Song
int Song::getSize() const
{
    return size;
}

// Returns position from Song
int Song::getPosition() const
{
    return position;
}

bool Song::operator > (const Song &s1)
{
	bool status = 0;

    if(s1.artist < artist)
        status = 1;
    else if(s1.artist == artist)
        if(s1.title < title)
            status = 1;
        else if(s1.title == title)
            if(s1.size < size)
                status = 1;

	return status;
}

bool Song::operator < (const Song &s1)
{
	bool status = 0;

    if(s1.artist > artist)
        status = 1;
    else if(s1.artist == artist)
        if(s1.title > title)
            status = 1;
        else if(s1.title == title)
            if(s1.size > size)
                status = 1;

	return status;
}

bool Song::operator == (const Song &s1)
{
	bool status = 0;

	if(s1.artist == artist && s1.title == title && s1.size == size)
        status = 1;

	return status;
}

bool Song::operator != (const Song &s1)
{
	bool status = 0;

	if(!(s1.artist == artist && s1.title == title && s1.size == size))
        status = 1;

	return status;
}
