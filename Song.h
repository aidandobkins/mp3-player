/****************************************************
Name: Aidan Dobkins
Date: 04/23/2020
Problem Number: #6
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <fstream>

using namespace std;

class Song
{
private:
	string artist;
	string title;
	int size;
	int position;
public:
	Song();
	Song(char*, char*, int, int);
	void setArtist(string);
	void setTitle(string);
	void setSize(int);
	void setPosition(int);
	const string getArtist() const;
	const string getTitle() const;
	int getSize() const;
	int getPosition() const;
	bool operator >(const Song &);
	bool operator <(const Song &);
	bool operator ==(const Song &);
	bool operator !=(const Song &);
};

#endif /* SONG_H_ */
