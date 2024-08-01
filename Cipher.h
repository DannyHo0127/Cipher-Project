//Header file for cipher class
//Create header guards for the cipher class
//Include string and queue header file
#ifndef CIPHER_H
#define CIPHER_H
#include <string>
#include "Queue.h" 

//Use using namespace std
using namespace std;

//Create a class named Cipher that will encode and decode messages
class Cipher {
	//In public, declare all the functions I will be using
	//Create a constructor Cipher()
	//Create a void function setCipher with an int and int array as parameters
	//Create an int pointer function getCipher that will return the cipher key as a pointer
	//Create two string functions encodeMessage and decodeMessage wit string parameters
	//Create an int getSize() that will return the size of the array/cipher key
	public:
		Cipher();
		void setCipher(int, int[]);
		int* getCipher();
		string encodeMessage(string);
		string decodeMessage(string);
		int getSize();
	//In private, create an int arraySize, queue object named encodeKey, and int pointer keyArray
	private:
		int arraySize;
		Queue encodeKey;
		int* keyArray;
};
#endif

