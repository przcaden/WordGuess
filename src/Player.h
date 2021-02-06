/*
 * Player.h
 *
 *  Created on: Feb 3, 2021
 *      Author: przca
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

class Player {
private:
	string _name;
	int _wins;
	int _losses;

public:
	Player(){}
	Player(string);
	void setName();
	string getName();
	void incWins();
	void incLosses();
	int getWins();
	int getLosses();
};

#endif /* PLAYER_H_ */
