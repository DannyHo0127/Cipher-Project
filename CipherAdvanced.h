//Danny Ho 
//CPSC 1070-010
//3/4/2023
//This the header file for the child class CipherAdvanced

//Create header guards for the child class CipherAdvanced
//Include base class cipher,h, vector, string, and set
#ifndef CIPHER_ADVANCED_H
#define CIPHER_ADVANCED_H
#include "Cipher.h"
#include <vector>
#include <string>
#include <set>

//Use using namespace std
using namespace std;

//Declare the child class CipherAdvance and indicate Cipher as the parent class by doing child : parent format
class CipherAdvanced : public Cipher {
	//In public, create the function needed for this class
	//Create void unknownScramble with string word as the parameter
	//Create a set<string> function readDictionary(string)
	//Create isValidWord(const string&, const set<string>&)
	//I use const and & to make sure the parameters are not changed and stay true throughout the program
	public:
		void unknownScramble(string);
		set<string> readDictionary(string);
		bool isValidWord(const string&, const set<string>&);
	//In private, create a string vector wordVector that will hold words that are valid
	private:
		vector<string> wordVector;
};

#endif
