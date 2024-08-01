//Include the CipherAdvance.h file
//Include iostream and fstream to read in files
//Include algorithm to use the sort key to sort words in alphabetical order
//Include string, set, vector, and cctype
#include "CipherAdvanced.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cctype>

//Use using namespace std
using namespace std;

//Define the void function unknownScramble that will decipher an encoded word print out all possible words using a key length between 1 and 5
void CipherAdvanced::unknownScramble(string word) {
	//Create a set<string> diction and set it equal to readDiction with the dictionPath as the parameter
	//Creat an int array key and set size to 5
	//Create a bool foundWord that will be true if word found, otherwise false
	//Create a set<string> sameWords that will contain valid word through different loops and make sure I don't print out repeating words
	//Create a string vector call wordVector that will contain all the valid words with each repeating key
	set<string> dictionary = readDictionary("/usr/share/dict/words");
	int key[5];
	bool foundWord = false;
	set<string> sameWords;
	vector<string> wordVector;
	
	//Create a massive nested for loop
	//The first for loop will iterate 5 times to create all possible cipher combinations from a key length of 1 to 5
	//The second for loop will start with int a and loop all the way to 26
	//Set key[0] to a
	//The third for loop will start with int b, make a conditional operator. if keyLength is greater than or equal to 1, loop through 26, else loop once
	//Set key[1] to b
	//The fourth  for loop will start with int c, make a conditional operator. if keyLength is greater than or equal to 2, loop through 26, else loop once
	//Set key[2] to c
	//The fifth for loop will start with int d, make a conditional operator. if keyLength is greater than or equal to 3, loop through 26, else loop once
	//Set key[3] to d
	//The sixth for loop will start with int e, make a conditional operator. if keyLength is greater than or equal to 4, loop through 26, else loop once
	//Set key[4] to e
	for (int keyLength = 1; keyLength <= 5; ++keyLength) {
		for (int a = 0; a <= 26; a++) {
			key[0] = a;
			for (int b = 0; b < (keyLength >= 1 ? 26 : 1); b++) {
				key[1] = b;
				for (int c = 0; c < (keyLength >= 2 ? 26 : 1); c++) {
					key[2] = c;
					for (int d = 0; d < (keyLength >= 3 ? 26 : 1); d++) {
						key[3] = d;
						for (int e = 0; e < (keyLength >= 4 ? 26 : 1); e++) {
							key[4] = e;
							//Call the setCipher function from the parent class of Cipher with parameters of keylength and key
							//Create a string called decodedWord and set it to decodeMessage function with the parameter of word
							//Create an if statement that if isValidWord(decodedWord, dictionary) is true and sameWords.find(decodedWord) is not in the set
							//Set foindWord to true, insert the decoded word in the SameWords set, and use the pushback to pushback the decoded word
							setCipher(keyLength, key);
							string decodedWord = decodeMessage(word);
							if (isValidWord(decodedWord, dictionary) && sameWords.find(decodedWord) == sameWords.end()) {
								foundWord = true;
								sameWords.insert(decodedWord);
								wordVector.push_back(decodedWord);
							}
							//Sort the vector in alphabetical order using the sort function from the include algorithm
							//Create a for loop that will loop through the vector and print the wordVector[u] and newline
							//Then, clear the word vector
							sort(wordVector.begin(), wordVector.end());
							for (int i = 0; i < wordVector.size(); i++) {
								cout << wordVector[i] << endl;
							}
							wordVector.clear();
						}
					}
				}
			}
		}
	}
	//Make an if statement that if foundWord is false, print no possibilities exist
	if (!foundWord) {
		cout << "NO POSSIBILITIES EXIST" << endl;
	}
}

//Define the set<string> function readDictionary with string  dictionaryPath
//This function will read in the dictionar path way and read into the dictionary and put every word into a string set and return that string set
set<string> CipherAdvanced::readDictionary(string dictionaryPath) {
	//Create an ifstream object called file(dictionarPath) to open the dictionary
	//Create a string set called dictionary
	//Create a string word
	//Make a while loop that while the file is still reading into the dictionary and setting the dictionary words to word
	//make a for loop that will iterate through the word and convert word[i] to a lowercase letter
	//Then insert the word to the set string diction 
	//Then, close the file and return dictionary
	ifstream file(dictionaryPath);
	set<string> dictionary;
	string word;
	while (file >> word) {
		for (int i = 0; i < word.length(); i++) {
			word[i] = tolower(word[i]);
		}
		dictionary.insert(word);
	}
	file.close();
	return dictionary;
}

//Define the bool function isValidWord with const string& word, const set<string>& dictionary as the parameter
//This will return true if the word is valid and false if the word is not valid
//I use const and & to make sure the parameters doesn't change and stay true during the program
//Return dictionary.find(word) != dictionary.end(), which will be true if the string set dictionary find the words before reaching to the end, otherwise return false
bool CipherAdvanced::isValidWord(const string& word, const set<string>& dictionary) {
	return dictionary.find(word) != dictionary.end();
}

