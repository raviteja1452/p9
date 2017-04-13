//p9scripts
/*
Question: Creation of Queue using Dynamic Circular Array

Algorithm : Queue is an Abstract Data Type. 
Implementation of Queue is nothing but implementation of the operations of it.
Such as Enqueue, Dequeue, Front, isEmpty, Size:

Here we are using a Circular array which double incremental strategy.

*/

#include<iostream>
using namespace std;

class Queue{
	private:
		// Circular Array of size 5
		int *arr,*dummy;
		int front,rear,max;
		// Doubling the stack by twice
		int doubleQueue(){
			dummy = arr;
			arr = new int[max*2];
			int max2 = max*2;
			int i = front;
			while(i%max!=rear){
				arr[i%max2] = dummy[i%max];
				i = i+1;
			}
			arr[i%max2] = dummy[rear];
			rear = i%max2;
			max = max2;
			cout << "Queue is resized to " << max << endl;
			delete [] dummy;
			return 1;
		}

	public:
		Queue(void){
			// Maximum Size of Queue
			cout << "Initialized the Queue" << endl;
			arr = new int [1];
			max = 1;
			// When queue is empty, front and rear are set to -1
			front = -1;
			rear = -1;
		}

		// Enqueue of Queue
		int enqueue(int val){
			// Using modulus as we are using a circular array.
			if ((rear+1)%max == front){
				doubleQueue();
			}
			rear = (rear + 1)%max;
			arr[rear] = val;
			cout << "enqueing :" << arr[rear] << endl;
			if(front == -1){
				front = (front + 1)%max;
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
					cout << arr[i] << " ";
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
	qe.display();
	qe.size();
	qe.enqueue(20);
	qe.display();
	qe.enqueue(30);
	qe.display();
	qe.enqueue(40);
	qe.display();
	qe.enqueue(50);
	qe.enqueue(60);
	qe.display();
	qe.enqueue(70);
	qe.display();
	qe.dequeue();
	qe.size();
	qe.Front();
	qe.dequeue();
	qe.size();
	qe.Front();
	qe.enqueue(80);
	qe.display();
	return 1;
}


// Complexities

// For Doubling Strategy.
// Time Complexity to push an element is o(1)
// Time Complexity to pop an element is o(1)
// Time Complexity to Delete complete Queue is o(1)
// Time Complexity to get size is o(1)