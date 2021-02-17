/*
 *  Dictionary.h
 *
 *  Created on: Feb 4, 2021
 *  Author: Caden Perez
 *
 *  Description: header file for the Dictionary class.
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <string>
#include <vector>
using namespace std;

class Dictionary {
private:
	vector<string> _wordList;

public:
	Dictionary();

	void enterList();
	//pre: user selected to enter their own list of words
	//post: _wordList is populated by all user-entered words

	void generateList(string);
	//pre: user selected to generate the pre-made list of words
	//post: _wordList is populated from words.txt

	string getWord();
	//pre: _wordList must be populated before call of this function
	//post: return a random word in _wordList
};

#endif /* DICTIONARY_H_ */
