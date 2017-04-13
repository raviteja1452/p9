// p9Scripts
/*

Question: Reversing Elements of a Queue using Stack.

Algorithm: 
1) We use a Stack stl, Queue stl here.
2) Dequeue all elements from the queue and Push to the stack.
3) When the queue is empty, Pop each element from Stack and Enqueue to the queue.
4) Order of the Queue is Reversed.

Complexity:
Time: o(n) 
Moving n elements from queue to stack = o(n)
Moving n elements from stack back to queue = o(n)
Total Time = o(n) + o(n) = o(n)
Space : o(n), for the additional stack.
*/

/* Code */
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

stack<int> s;
queue<int> q;
 

// Function for Reversing the elements of Queue
void reverse(){
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
}

// For Displaying the elements of Queue
void display(){
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
	display();
	reverse();
	cout << "Elements of Queue after Reversing:" << endl;
	display();
	return 0;
}
