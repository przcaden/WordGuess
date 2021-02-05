/*
 *  GameState.cpp
 *
 *  Created on: Feb 4, 2021
 *  Author: Caden Perez
 *
 *  Description: Main class for the state of the word game. Prompts all user inputs in the console and prints every message.
 *  	Also manages class objects and their private values.
 */

#include <iostream>
#include <fstream>
#include "GameState.h"
#include <string>
#include <vector>
using namespace std;

#include "Player.h"
#include "Dictionary.h"

int main() {
	string word; // current word being solved by the user.
	string userWord; // the current word, but only the letters they have guessed.
	vector<string> wrongLetters; // wrong letters that the user has chosen.
	vector<string> wrongWords; // wrong words that the user has played.
	int attemptsLeft; // number of attempts the user has left.

	string listchoice;
	cout << "-------------------------------- The Word Guess Game --------------------------------" << endl;
	cout << "Welcome. To start, would you prefer to (1) enter your own list of words or (2) use an auto-generated one?" << endl;
	cout << "Enter 1 or 2: ";
	cin >> listchoice;

	while (listchoice!="1" || listchoice!="2") {
		cout << "Error with user entry. Enter either 1 or 2: ";
		cin >> listchoice;
	}

	// Following block generates the list of words based on the user's choice.
	Dictionary list();
	if (listchoice == "1") { // this if block uses a sentinel loop to add multiple words to the list.
		string entry;
		cout << "Please enter a word to include. Enter -1 to end your list: ";
		cin >> entry;
		while (entry != "-1") {
			list.addWord(entry);
			cout << "Enter a word: ";
			cin >> entry;
		}
	}
	else list.generateList();

	// Gets the user names and creates a personal class object.
	string playername;
	cout << "Proceeding..." << endl << "What is your name?: ";
	cin >> playername;
	Player player(playername);


	do {

	} while ();
}
