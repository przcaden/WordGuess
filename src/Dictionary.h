/*
 * Dictionary.h
 *
 *  Created on: Feb 3, 2021
 *      Author: przca
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <string>

class Dictionary {
private:
	vector<string> _wordList;

public:
	Dictionary();
	void addWord(string); // manually add a string to the vector.
	void generateList(); // generate a list from the words.txt file.
	string getWord(); // get a word from the list.
};

#endif /* DICTIONARY_H_ */
