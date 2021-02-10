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
#include <string>
#include <vector>
using namespace std;

#include "Player.h"
#include "Dictionary.h"

int main() {
	string word; // current word being solved by the user.
	string solvedWord; // the current word, but only the letters they have guessed.
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
		cout << "Please enter a word to include. Enter -1 to end your list: " << endl;
		cin >> entry;
		while (entry != "-1") {
			list.addWord(entry);
			cout << "Enter a word to add, or -1 to end: " << endl;
			cin >> entry;
		}
	}
	else list.generateList();

	// Gets the user's name and creates a personal class object.
	string playername;
	cout << "Proceeding..." << endl << "What is your name?: " << endl;
	cin >> playername;
	Player player(playername);
	cout << "Beginning the Word Guess game... " << endl;
	bool play = true; // remains true if the user wants to continue to play.

	// Main block for the game.
	do {
		// Set default conditions when a new word is retrieved.
		attemptsLeft = 5;
		word = list.getWord();
		solvedWord = word;
		char selection;
		bool endCheck = false;
		for (int i=0; i<word.length(); i++) {
			solvedWord[i] = "_";
		}

		// This block runs as long as the user has not solved the word yet.
		while (!endCheck) {
			// Print the solved word.
			for (int i=0; i<solvedWord.length(); i++) {
				cout << solvedWord[i] << " ";
			}
			cout << endl << endl;
			cout << "Attempts left: " << attemptsLeft << endl << "What letter do you choose?: " << endl;
			cin >> selection;

			while (!isalpha(selection)) { // Checks if character entered was alphabetical.
				cout << "Selection was invalid. Try again: " << endl;
				cin >> selection;
			}
			selection = tolower(selection); // Convert the input to lowercase if not already.

			// Check if the selection is a letter in the word. If not, decrement the attempts left by 1.
			for (int i=0; i<word.length(); i++) {
				if (word[i] == selection) {
					solvedWord[i] = selection;
				}
				else attemptsLeft = attemptsLeft-1;
			}
			// Checks win condition.
			if (solvedWord == word) {
				endCheck = true;
				player.incWins();
				cout << "You have guessed the word!" << endl;
			}
			else if (attemptsLeft == 0) {
				endCheck = true;
				player.incLosses();
				cout << "You have run out of attempts." << endl;
			}
		}

		// Ask the user if they want to continue playing.
		cout << "Play again? (Y/N): ";
		cin >> selection;
		while (!(selection="Y" || selection="y" || selection="N" || selection="n")) {
			cout << "Selection was invalid. Try again: ";
			cin >> selection;
		}

		// If the user does not want to continue, the game loop ends.
		if (selection == "N" || selection == "n")
			play = false;
	} while (play);
	cout << "Thank you for playing the Word Guess game." << endl;
}
