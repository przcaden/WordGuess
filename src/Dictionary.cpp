/*
 *  Dictionary.cpp
 *
 *  Created on: Feb 4, 2021
 *  Author: Caden Perez
 *
 *  Description: Populates a vector of words for the game to randomly choose from.
 */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Dictionary.h"
using namespace std;

Dictionary::Dictionary() {}

void Dictionary::enterList() {
	string entry;
	cout << "Please enter a word to include. Enter -1 to end your list: " << endl;
	cin >> entry;
	while (entry != "-1") {
		_wordList.push_back(entry);
		cout << "Enter a word to add, or -1 to end: " << endl;
		cin >> entry;
	}
}

void Dictionary::generateList(string list) {
	ifstream infile(list);
	if (!infile) {
		cout << "Error opening file.";
		exit(-1);
	}

	string w;
	infile >> w;
	while (!infile.eof()) { // push every word from file to _wordList
		_wordList.push_back(w);
		infile >> w;
	}
}

string Dictionary::getWord() {
	int val = rand() % _wordList.size(); // generate random value based on size of vector
	return _wordList[val];
}
