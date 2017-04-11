// Implementing a Queue using two Stacks.
// p9Scripts
/*
Q: Implementation of Queue using stacks.
Here we use stack c++ stl to build a queue
Operations that we design for a queue:

Stacks s1 and s2

Enqueue:
	s1.push()
Dequeue:
	if s2.empty(): 
		while !s1.empty()
			s2.push(s1.top())
			s1.pop()
	if !s2.empty():
		s2.pop()
	else:
		"Underflow"
Front:
	if s2.empty(): 
		while !s1.empty()
			s2.push(s1.top())
			s1.pop()
	if !s2.empty():
		s2.top()
	else:
		"Underflow"

Size:
	return s1.size() + s2.size();

isEmpty:
	if s1.empty and s2.empty :return true else false

*/

#include<iostream>
#include<stack>

using namespace std;

class Queue{
	private:
		stack<int> s1,s2;
	public:
		// Enqueue function of Queue
		void enqueue(int val){
			s1.push(val);
			cout << "enqueued :" << val << endl;
		}

		// Dequeue function of Queue
		void dequeue(){
			if (s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			if(!s2.empty()){
				cout << "dequeued :" << s2.top() << endl;
				s2.pop();
			}else{
				cout << "Underflow "<< endl;
			}
		}
		// Front
		void front(){
			if (s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			if(!s2.empty()){
				cout << "top :" << s2.top() << endl;
			}else{
				cout << "Underflow "<< endl;
			}
		}
		// Empty
		bool isEmpty(){
			if(s1.empty() && s2.empty()){
				cout << "Empty "<< endl;
				return true;
			}
			cout << "Not Empty "<< endl;
			return false;
		}

		// Size
		int size(){
			int s = s1.size() + s2.size();
			cout << "size :" << s << endl;
			return s;
		}

};

int main(void){
	Queue q;
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(3);
	q.dequeue();
	q.front();
	q.size();
	q.enqueue(10);
	q.front();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.size();
}

/*

Time Complexity:
Enqueue: o(1);
Dequeue: o(1);
front: o(1);
size: o(1);
empty:  o(1);

*/