// Stack Using a Dynamic Array
// p9Scripts 

// Implementaion of Stack using a Linkedlists


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

class Stack{
	private:
		//Maximum Size of Stack is Private 
		Node * stack;

	public:
		// Constructor of Stack
		Stack(void){
			cout << "initialized a stack" << endl;
			stack = NULL;
		}

		// Push operations on stack
		int push(int value){
			Node *head = new Node();
			head->setData(value);
			head->setNext(stack);
			stack = head;
			cout << stack->getData() << " is pushed to stack" << endl;
			print();
			return 1;
		}

		// Pop operations on stack
		int pop(){
			Node *head;
			if(stack != NULL){
				head = stack;
				stack = head->getNext();
				cout << "element poped " << head->getData() << endl;
				delete head;
				print();
				return 1;
			}
			cout  << "stack is empty" << endl;
			return 0;
		}

		// Top operations on stack

		int topElement(){
			if(stack != NULL){
				cout << "top element of stack " << stack->getData() << endl;
				return 1;
			}
			cout << "stack is empty" << endl;
			return 0;
		}

		// Length of stack
		int print(){
			Node *t = stack;
			int count = 0;
			do{
				cout << t->getData() << endl;
				t = t->getNext();
				count += 1 ;
			}while(t != NULL);
			return 1;
		}

		int length(){
			Node *t = stack;
			int count = 0;
			do{
				t = t->getNext();
				count += 1 ;
			}while(t != NULL);
			return count;
		}
};


int main(){
	// Calling Stack
	Stack st;
	// Few Operations on stack
	st.pop();
	st.push(10);
	st.push(11);
	st.length();
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.push(70);
	st.pop();
	st.topElement();
	st.length();
	st.pop();
	st.length();
	st.topElement();
	st.push(80);
	return 1;
}


// Complexities

// For Doubling Strategy.
// Time Complexity to push an element is o(1)
// Time Complexity to pop an element is o(1)
// Time Complexity to Delete complete Stack is o(n)
// Time Complexity to get size is o(n)


