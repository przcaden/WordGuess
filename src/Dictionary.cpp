/*
 * Dictionary.cpp
 *
 *  Created on: Feb 3, 2021
 *      Author: przca
 */

#include <string>
#include <vector>
#include <fstream>
#include "Dictionary.h"
using namespace std;

Dictionary::Dictionary() {}

void Dictionary::addWord(string w) {
	_wordList.push_back(w);
}

void Dictionary::generateList() {
	ifstream infile("words.txt");
	string word;
	infile >> word;
	while (!infile.eof()) {
		_wordList.push_back(word);
		infile >> word;
	}
}

string Dictionary::getWord() {

}
