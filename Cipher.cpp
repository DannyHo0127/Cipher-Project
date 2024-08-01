//This is the .cpp file for the cipher class to define the functions
//Include the Cipher and Queue header files
//Include string and cctype to convert strings to lowercase letters
#include "Cipher.h"
#include "Queue.h"
#include <string>
#include <cctype>

//Use using namespace std
using namespace std;

//Define the constructor, which will set the cipher key to 1,2,3,4
//Create an in array called defaultKey to hold 4 element, which contains 1,2,3,4
//Call the setCipher function with parameters of 4 and the array to set the key
Cipher::Cipher() {
	int defaultKey[4] = {1, 2, 3, 4};
	setCipher(4, defaultKey);
}

//Define teh void function setCipher with parameters of int num and int array repeatKey[]
//This function will use the queue class to enqueue the cipher key
//Make an if statement that if num is greater than 100, set num to 100
//Then clear the queue object and set arraySize to num
//Dynamically allocate the keyArray pointer with int[arraySize]
//Make a for loop with int i = 0, i loop while less than num, increment i
//Use the queueObject to enqueue repeatKey[i] to enqueue one of the key
//Set keyArray[i] to repeatKey[i] 
void Cipher::setCipher(int num, int repeatKey[]) {
	if (num > 100) { 
		num = 100;
	}
	encodeKey.clear();
	arraySize = num;
	keyArray = new int[arraySize];
	for (int i = 0; i < num; i++) {
		encodeKey.enqueue(repeatKey[i]);
		keyArray[i] = repeatKey[i];
	}
}

//Define the int pointer function getCipher(), which will return the CipherKey
//Retuen keyArray, which holds the cipher key
int* Cipher::getCipher() {
	return keyArray;
}

//Define the string function encodeMessage with a string parameter called in
string Cipher::encodeMessage(string in) {
	//Create two strings result and newMessage and set both to nothing
	//SetCipher with the arraySize and keyArray to reset the key
	string result = "";
	string newMessage = "";
	setCipher(arraySize, keyArray);

	//Create a for loop with int i that loops through the string in
	//Create a char c and set it to in[i]
	//If c is an alphabetical letter, set newMessage plus equal to c
	for(int i = 0; i < in.length(); i++) {
		char c = in[i];
		if (isalpha(c)) {
			newMessage += c;
		}
	}

	//Create a for loop that loops through the string newMessage
	//Create a char& c and set it to newMessage[i]
	//Set c to tolowr(c), which will convert c to a lower case letter
	for (int i = 0; i < newMessage.length(); i++) {
		char& c = newMessage[i];
		c = tolower(c);
	}

	//Create a for loop that will loop through the newMessage string
	//Create a char c and set it to newMessage[i]
	//Create an int shift and actualShift
	//Call the object encodeKey.dequeue(shift) to set shift to the first element dequeued
	//If shift is a negative, set actual shift to (shift % 26 + 26) % 26 to convert the shift to how many forward shift it is
	//else, mean shift is 0 or positive and set actualShift to shift % 26 to see how forward shift there is
	//Set c to (c - 'a' + actualShift) % 26 + 'a' to encode the letter and set result  plus equals to c
	//Then enqueue the the int shift to repeat the key
	//return the result string, which is the encoded key
	for(int i = 0; i < newMessage.length(); i++) {
		char c =  newMessage[i];
		int shift;
		int actualShift;
		encodeKey.dequeue(shift);
		if (shift < 0) {
			actualShift = (shift % 26 + 26) % 26;
		}
		else {
			actualShift = shift % 26;
		}
		c = (c - 'a' + actualShift) % 26 + 'a';
		result += c;
		encodeKey.enqueue(shift);
	}
	return result;
}

//Define the string function decodeMessage with string parameter in, which will decode the encoded message using the given cipher key
string Cipher::decodeMessage(string in) {
	//Create two strings result and newMessage and set both to nothing
	//SetCipher with the arraySize and keyArray to reset the key
	string result = "";
	string newMessage = "";
	setCipher(arraySize, keyArray);

	//Create a for loop with int i that loops through the string in
	//Create a char c and set it to in[i]
	//If c is an alphabetical letter, set newMessage plus equal to c
	for(int i = 0; i < in.length(); i++) {
		char c = in[i];
		if (isalpha(c)) {
			newMessage += c;
		}
	}

	//Create a for loop that loops through the string newMessage
	//Create a char& c and set it to newMessage[i]
	//Set c to tolowr(c), which will convert c to a lower case letter
	for (int i = 0; i < newMessage.length(); i++) {
		char& c = newMessage[i];
		c = tolower(c);
	}

	//Create a for loop that will loop through the newMessage string
	//Create a char c and set it to newMessage[i]
	//Create an int shift and actualShift
	//Call the object encodeKey.dequeue(shift) to set shift to the first element dequeued
	//If shift is a negative, set actual shift to (shift % 26 + 26) % 26 to convert the shift to how many forward shift it is
	//else, mean shift is 0 or positive and set actualShift to shift % 26 to see how forward shift there is
	//Set c to (c - 'a' - actualShift) % 26 + 'a' to decode the letter and set result  plus equals to c
	//Then enqueue the the int shift to repeat the key
	//return the result string, which is the encoded key
	for (int i = 0; i < newMessage.length(); i++) {
		char c = newMessage[i];
		int shift;
		int actualShift;
		encodeKey.dequeue(shift);
		if (shift < 0) {
			actualShift = (shift % 26 + 26) % 26;
		}
		else {
			actualShift = shift % 26;
		}
		c = (c - 'a' - actualShift + 26) % 26 + 'a';
		encodeKey.enqueue(shift);
		result += c;
	}
	return result;
}

//Define the int function getSize(), which will return the size of the cipher key
//return arraySize
int Cipher::getSize() {
	return arraySize;
}
