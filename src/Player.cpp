/*
 *  Player.cpp
 *
 *  Created on: Feb 4, 2021
 *  Author: Caden Perez
 *
 *  Description: Holds the user's name, current wins, and current losses. Will increment either one after each game.
 */

#include <string>
#include "Player.h"
using namespace std;

Player::Player(string n) {
	_name = n;
	_wins = 0;
	_losses = 0;
}

void Player::incWins() {
	_wins++;
}

void Player::incLosses() {
	_losses++;
}

int Player::getWins() {
	return _wins;
}

int Player::getLosses() {
	return _losses;
}

string Player::getName() {
	return _name;
}
