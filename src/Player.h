/*
 *  Player.h
 *
 *  Created on: Feb 4, 2021
 *  Author: Caden Perez
 *
 *  Description: header file for the Player class.
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
using namespace std;

class Player {
private:
	string _name;
	int _wins;
	int _losses;

public:
	Player(string);
	void setName();
	string getName();
	void incWins();
	void incLosses();
	int getWins();
	int getLosses();
};

#endif /* PLAYER_H_ */
