/*
 * Player.cpp
 *
 *  Created on: Feb 3, 2021
 *      Author: przca
 */

#include <string>
#include "Player.h"

Player::Player() {}

Player::Player(string n) {
	_name = n;
	_wins = 0;
	_losses = 0;
}

void Player::incWins() {
	_wins = _wins+1;
}

void Player::incLosses() {
	_losses = _losses+1;
}

int Player::getWins() {
	return _wins;
}

int Player::getLosses() {
	return _losses;
}
