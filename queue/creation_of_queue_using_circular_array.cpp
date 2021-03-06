//p9scripts
/*
Question: Creation of Queue using Circular Array

Algorithm : Queue is an Abstract Data Type. 
Implementation of Queue is nothing but implementation of the operations of it.
Such as Enqueue, Dequeue, Front, isEmpty, Size:

Here we are using a Circular array of fixed size of the same. 

*/

#include<iostream>
using namespace std;

class Queue{
	private:
		// Circular Array of size 5
		int arr[5];
		int front,rear,max;

	public:
		Queue(void){
			// Maximum Size of Queue
			cout << "Initialized the Queue" << endl;
			max = sizeof(arr)/sizeof(int);
			// When queue is empty, front and rear are set to -1
			front = -1;
			rear = -1;
		}

		// Enqueue of Queue
		int enqueue(int val){
			// Using modulus as we are using a circular array.
			if ((rear+1)%max == front){
				cout << "Queue is Full, Overflow" <<endl;
				return -1;
			}else{
				rear = (rear + 1)%max;
				arr[rear] = val;
				cout << "enqueing :" << arr[rear] << endl;
				if(front == -1){
					front = (front + 1)%max;
				}
			}
			return 0;
		}

		// Dequeue of a Queue
		int dequeue(){
			if(front == -1){
				cout << "Queue is Empty, Underflow" << endl;
				return -1;
			}
			cout << "dequeing :" << arr[front] << endl;
			front = (front + 1)%max;
			if(front == rear){
				front = -1;
				rear = -1;
			}
			return 0;
		}

		// returns front element of Queue
		int Front(){
			if(front == -1){
				cout << "Queue is Empty, Underflow" << endl;
				return -1;
			}
			cout << "Element at top:" << arr[front] << endl;
			return 0;
		}

		// Is the queue empty
		int isEmpty(){
			if(front == -1){
				cout << "Yes, Its empty" << endl;
				return 1;
			}
			cout << "No, Its not empty" << endl;
			return 0;
		}

		// Is the Queue Full
		int isFull(){
			if(front == (rear + 1)%max){
				cout << "Yes, Its Full" << endl;
				return 1;
			}
			cout << "No, Its not Full" << endl;
			return 0;
		}

		// Returns the size of queue
		int size(){
			int s = 0;
			if(front == -1){
				cout << s << endl;
				return s;
			}
			s = (rear + max - front)%max + 1;
			cout << s << endl;
			return s;
		}

		// Displays Queue
		void display(){
			if(front == -1){
				cout << "Queue is empty" << endl;
			}else{
				cout << "Elements of Queue are" << endl;
				int i = front;
				while(i != rear){
					cout << arr[i] ;
					i = (i + 1)%max;
				}
				cout << arr[rear] << endl;
			}
		}
};

int main(void){

	// Call Queue
	Queue qe;
	// Few Operations on stack
	qe.dequeue();
	qe.enqueue(10);
	qe.enqueue(11);
	qe.size();
	qe.enqueue(20);
	qe.enqueue(30);
	qe.enqueue(40);
	qe.enqueue(50);
	qe.enqueue(60);
	qe.enqueue(70);
	qe.dequeue();
	qe.size();
	qe.Front();
	qe.dequeue();
	qe.size();
	qe.Front();
	qe.enqueue(80);
	return 1;
}