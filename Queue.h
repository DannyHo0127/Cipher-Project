//Create header guards
//Include cstdlib
#ifndef QUEUE_H
#define QUEUE_H
#include <cstdlib>

//Included using namespace std
using namespace std;

//Create the class Queue and I used the textbook chapter 19.5 as referenced to create this class 
class Queue {
	//In private create a struct named QueueNode
	//Inside the struct, create an int value and QueueNode *next
	//Then create QueueNode *front and QueueNode *rear for the front and rear part of a Queue
	//Create an int queueSize to know how many elements are in the queue
	private:
		struct QueueNode {
			int value;
			QueueNode *next;
		};
		QueueNode *front;
		QueueNode *rear;
		int queueSize;
		//In public, create the queue construuctor and destructor for the Queue class
		//Create voids functions enqueue with int parameter and dequeue with an int& parameter
		//Then create bool isEmpty() const
		//Create void function clear functions
		//Create a bool isFull() const function
	public:
		Queue();
		~Queue();
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty() const;
		void clear();
		bool isFull() const;
};
#endif

