// p9Scripts
/*

Question: Move Elements from Queue to Stack , 
such that the element on the front of queue is at the top of stack and order of the elements is preserved.

Algorithm: 
1) We use a Stack stl, Queue stl here.
2) Dequeue all elements from the queue and Push to the stack.
3) When the queue is empty, Pop each element from Stack and Enqueue to the queue.
4) Now when the stack is empty, again dequeue all elements from queue and push to stack.
5) Now the element which is at the front of queue, is on the top of the stack and order is preserved

Complexity:
Time: o(n) 
Moving n elements from queue to stack = o(n)
Moving n elements from stack back to queue = o(n)
Moving back n elements from queue to stack = o(n)
Total Time = o(n) + o(n) +o(n) = o(n)
Space : o(n), for the stack.
*/

/* Code */
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

stack<int> s;
queue<int> q;
 

// Function for Reversing the elements of Queue
void queueTostack(){
	int len = q.size();
	for (int i = 0; i < len; ++i)
	{
		s.push(q.front());
		q.pop();
	}
	for (int i = 0; i < len; ++i)
	{
		q.push(s.top());
		s.pop();
	}
	for (int i = 0; i < len; ++i)
	{
		s.push(q.front());
		q.pop();
	}
}

void displayStack(){
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		int r = s.top();
		cout << r << " "; 
		s.pop();
	}
	cout << endl;
}

// For Displaying the elements of Queue
void displayQueue(){
	int len = q.size();
	for (int i = 0; i < len; ++i)
	{
		int r = q.front();
		cout << r << " "; 
		q.pop();
		q.push(r);
	}
	cout << endl;
}



int main(){

	// Enqueing the Queue
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout << "Elements of Queue:" << endl;
	displayQueue();
	queueTostack();
	cout << "Elements of stack after Operation:" << endl;
	displayStack();
	return 0;
}
