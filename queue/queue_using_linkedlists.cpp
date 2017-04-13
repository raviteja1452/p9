// p9Scripts 

/*
Question: Creation of Queue using Linkedlists;
Algorithm: We implement Queue ADT using linkedlist.
1) Front of Queue is pointed to head of linkedlist.
2) Rear of Queue is pointed to tail of linkedlist.
Here we define Operations of Queue such as enqueue, dequeue,front,size,display,isempty .
*/


#include<iostream>

using namespace std;

// Linkedlist Node class
class Node{
	private:
		int data;
		Node * next;

	public:
		Node(){
			data = -1;
			next = NULL;
		}

		int getData(){
			return data;
		}
		int setData(int d){
			data = d;
			return 1;
		}
		int setNext(Node *n){
			next = n;
			return 1;
		}
		Node * getNext(){
			return next;
		}
};

class Queue{
	private:
		Node *front,*rear; 
	public:
		Queue(){
			cout << "Initializing a Queue" << endl;
			front = NULL;
			rear = NULL;
		}
		// Enqueue
		int enqueue(int val){
			Node *n = new Node();
			n->setData(val);
			cout << "Enqueued:" << n->getData() <<endl;
			if(rear == NULL){
				rear = n;
				front = rear;
			}else{
				rear->setNext(n);
				rear = n;
			}
			return 0;
		}
		// Dequeue

		int dequeue(){
			if(front == NULL){
				cout << "Underflow" << endl;
				return -1;
			}
			cout << "Element popped:" << front->getData() << endl;
			front = front->getNext();
			if(front == NULL){
				rear = NULL;
			}
			return 0;
		}

		// front of queue
		int Front(){
			if(front == NULL){
				cout << "Underflow" << endl;
				return -1;
			}
			cout << "Element at top:" << front->getData() << endl;
			return 0;
		}
		
		// Size of Queue
		int size(){
			Node *l;
			l = front;
			int count = 0;
			l = front;
			while(l != NULL){
				l = l->getNext();
				count = count + 1;
			}
			cout << "Size of the queue:" << count << endl;
			return 0;
		}

		// Display of Queue
		int display(){
			Node *l;
			l = front;
			int count = 0;
			l = front;
			cout << "Elements of Queue :" << endl;
			while(l != NULL){
				cout << l->getData() << " ";
				l = l->getNext();
				count = count + 1;
			}
			cout << endl;
			return 0;
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

