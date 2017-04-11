// Implementing a Stack using 2 Queues
// p9Scripts.
/*
Here we use standard c++ stl library. 
We use queue stl and Implement a stack using the queues.
*/
/*
	Question: Implementation of Stack using Queues
	Algorithm:
	Let q1 and q2 be two queues. 
	Now we need to define the push and pop opeartions of stack using q1 and q2.'
	c_q = q1 // Queue  which we use for push operation
	s_q = q2
	Push of stack(i):
		c_q.enque(i)
	// Takes O(1) time.

	Pop os Stack():
		if(c_q.size == 0): underflow
		while(c_q.size > 1):
			s_q.enqueue(c_q.dequeue)
		e =  c_q.front()
		c_q.dequeue
		q = c_q
		c_q = s_q
		s_q = q
		return e
	// Takes O(n) time.

	Top of Stack():
		if(c_q.size == 0): underflow
		while(c_q.size > 0):
			top = c_q.front
			s_q.enqueue(c_q.dequeue)
		q = c_q
		c_q = s_q
		s_q = q
		return top
	Size of stack:
		return size of c_q
	is_empty:
		if len(c_q) == 0: return yes else no

	// Takes O(n) time.
*/
#include<iostream>
#include<queue>

using namespace std;

// Implementing a stack using two queues

class Stack{
	private:
		queue<int> q1,q2,q;

	public:
		// Push of Stack
		int push(int val){
			q1.push(val);
			cout << "pushed :" << val << endl;
			return 1;
		}
		// Pop of Stack
		int pop(){
			if(q1.empty()){
				cout << "pop: stack is empty"<<endl;
				return -1;
			}
			while(q1.size() > 1){
				q2.push(q1.front());
				q1.pop();
			}
			int e = q1.front();
			q1.pop();
			q = q1;
			q1 = q2;
			q2 = q;
			cout << "pop :" << e << endl;
			return e;
		}
		// Top of stack

		int top(){
			if(q1.empty()){
				cout << "top: stack is empty"<<endl;
				return -1;
			}
			int e;
			while(!q1.empty()){
				e = q1.front();
				q2.push(e);
				q1.pop();
			}
			q = q1;
			q1 = q2;
			q2 = q;
			cout << "top :" << e << endl;
			return e;
		}
		// is Empty:

		bool isEmpty(){
			if(q1.size() == 0){
				return true;
			}
			return false;
		}

		// Stack size

		int size(){
			cout << q1.size() << endl;
			return 1;
		}

};

int main(void){
	Stack s;
	s.push(10);
	s.push(11);
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.push(200);
	s.push(123);
	s.size();
	s.top();
	return 0;
}