//Include the Queue header file and cstdlib
#include "Queue.h"
#include <cstdlib>

//Use using namespace std
using namespace std;

//Define the Queue constructor that will initialze a Queue
//Set front and rear to nullptr and set queueSize to 0
Queue::Queue() {
	front = nullptr;
	rear = nullptr;
	queueSize = 0;
}

//Define the Queue destructor
//Create a QueueNode* called garbage and set it equal to front
//Make a while loop that while garbage is not equal to nullptr
//set front to next element
//Set garbage->next element to nullptr
//delete garvage and set garvage to front again
Queue::~Queue() {
	QueueNode * garbage = front;
	while(garbage != nullptr) {
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}

//Define the void function enqueue with int num as the parameter, this will enqueue the queue
//If queueSize is less than 100, the enqueue the num
//Increament queueSize
//create QueueNode* newNode equal new QueueNode
//Set newNode-> to num and set newNode->next to nullptr
//Make an if statement that if isEmpty() function is true, set front equal to newNode
//Else, set rear-> to newNode
//Then, set rear to newNode
void Queue::enqueue(int num) {
	if (queueSize < 100) {
		queueSize++;
		QueueNode* newNode = new QueueNode;
		newNode->value = num;
		newNode->next = nullptr;

		if (isEmpty()) {
			front = newNode;
		}
		else {
			rear->next = newNode;
		}
		rear = newNode;
	}
}

//Define the void function dequeue with int &num as the parameter,
//This function will dequeue the queue and return int& num, which will hold the value of the dequeued number
//Decrement queueSize and make an if statement that if isEmpty is false, dequeue the Queue
//Create QueueNode *temp and set it to nullptr
//Set num to front->value
//Set temp to front
//Set front to front->next and delete temp
void Queue::dequeue(int &num) {	
	queueSize--;
	if(!isEmpty()) {
		QueueNode *temp = nullptr;
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

//Define the bool function isEmpty() const, which will return true if the queue is empty
//Make an if statement that if front is equal to nullptr, return true, else return false
bool Queue::isEmpty() const {
	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//Define the void function clear(), which will clear the Queue
//Make an int value and make a while loop
//while isEmpty is false, dequeue(value) to clear the queue
//Set queueSize to 0
void Queue::clear() {
	int value;
	while(!isEmpty()) {
		dequeue(value);
	}
	queueSize = 0;
}

//Define the bool isFull() const function that will return true if the queue has 100 element, meaning full, else return false
//Make an if statement that if queueSize is equal to 100 and isEmpty is false, return true
//else return false
bool Queue::isFull() const {
	if (queueSize == 100 && isEmpty() == false) {
		return true;
	}
	else {
		return false;
	}
}

