//Include the Cipher, Queue, and CipherAdvanced header files for this project
//Include iostream and string 
#include "Cipher.h"
#include "Queue.h"
#include "CipherAdvanced.h"
#include <iostream>
#include <string>

//Use using namepsace std
using namespace std;

//Create a main that will start the Cipher project
int main() {
	//Create an int arraySize and an array with any key and size
	//This is test the project for different cipher keys
	//Create an Cipher class object named key
	int arraySize;
	int array[4] = {-1, 2, -50, 100};
	Cipher key;

	//Call the SetCipher function to set the cipher key with the specific size and array
	key.setCipher(4, array);

	//Create three string message, encondeMessage, and decodeMessage to display the messages
	string message;
	string encodeMessage;
	string decodeMessage;

	//Set arraySize to key.getSize() function to get the size of the array
	arraySize = key.getSize();

	//Create an int cipherKey pointer and dynamically allocate the pointer to a new int[arraySize]
	//Set cipherKey to keu.getCipher(), which returns the cipher key
	int* cipherKey = new int[arraySize];
	cipherKey = key.getCipher();

	//Print out the cipher key that the program will use
	//Use a for loop to iterate through the pointer and print out all the key with a comma between them
	//Put the key in brackets also print cipherKey[arraySize-1] to print the last key element and prevent a comma from being printed
	cout << "Key: [";
	for (int i = 0; i < arraySize - 1; i++) {
		cout << cipherKey[i] << ", ";
	}
	cout <<cipherKey[arraySize - 1];
	cout << "]" << endl;

	//Then prompt the user to enter a message they want to encode, use the getline function get the entire message in the string
	//Then, set encodeMessage to key.encodeMessage(message), which will encode the message using the cipherKey and get rid of white spaces, uppercase characters, and special characters
	//Set decodeMessage to key.decodeMessage(encodeMessage), which will decode the encoded message by reversing the cipher key
	cout << "Encoding: ";
	getline(cin, message);
	encodeMessage = key.encodeMessage(message);
	decodeMessage = key.decodeMessage(encodeMessage);

	//print out the encoded message and two new lines
	//Print out the cipher key again for the decoded message
	cout << "Encoded: " << encodeMessage << endl << endl;
	cout << "Key: [";
	for (int i = 0; i < arraySize - 1; i++) {
		cout << cipherKey[i] << ", ";
	}
	cout << cipherKey[arraySize - 1];
	cout << "]" << endl;

	//Print out the encoded message, and then the decoded message after decrypting the message
	cout << "Decoding: " << encodeMessage << endl;
	cout << "Decoded: " << decodeMessage << endl << endl;

	//Create a CipherAdvanced object called decodedWords
	//Create a string called scrambledWord and set it a scrambled word of choice
	CipherAdvanced decodedWords;
	string scrambledWord = "asgusd"; 

	//Use the object decodedWords to call unknownScramble with the scrambledWord as the parameter to print out all possible words
	//Using all possible cipher keys from length 1 to 5
	decodedWords.unknownScramble(scrambledWord);
}
