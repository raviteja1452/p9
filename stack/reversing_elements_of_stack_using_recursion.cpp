// Reversing the elements of stack using Recursion

//p9scripts

/*
	Q: Reverse the elements of stack using Recursion.
	Algorithm: 
		Given a stack of n elements, we need to reverse the elements of stack.
		Here we have two functions. 
		1) Reverse function :

			Reverse at bottom is a recursive function , it recursively pops elements and stores in its call stack. Then calls Insert At bottom on each element 
			Which inserts each element at bottom of stack there by it reverses

		2) Insert At Bottom :
			It is also a recursive function which inserts the element at the bottom .
		ReverseFunction pops each element recursively

*/

#include<iostream>

using namespace std;


class Stack{
	private:
		//Maximum Size of Stack is Private 
		int stack[10];
		int top,max;

	public:
		// Constructor of Stack
		Stack(void){
			cout << "initialized a stack" << endl;
			top = -1;
			max = sizeof(stack)/sizeof(int);
		}

		// Push operations on stack
		int push(int value){
			if(top < max -  1){
				top = top + 1;
				stack[top] = value;
				cout << stack[top] << " is pushed to stack" << endl;
				return 1;
			}
			cout << "stack is full to its capacity " << endl;
			return 0;
		}

		// Pop operations on stack
		int pop(){
			if(top > -1){
				cout << "element poped " << stack[top] << endl;
				top = top - 1;
				return 1;
			}
			cout  << "stack is empty" << endl;
			return 0;
		}

		// Top operations on stack

		int topElement(){
			if(top > -1){
				cout << "top element of stack " << stack[top] << endl;
				return stack[top];
			}
			cout << "stack is empty" << endl;
			return 0;
		}

		int display(){
			cout <<endl<< "Elements of Stack:"<<endl;
			for(int i = 0;i <= top; i++){
				cout<<stack[i]<<endl;
			}
			cout <<endl; 
			return 0;
		}
		// Length of stack

		int length(){
			return top + 1;
		}
		// empty

		bool empty(){
			if(top == -1){
				return true;
			}
			return false;
		}
};
// Reversing the stack functions

/*
	InsertElement at the bottom function inserts the elements at the bottom of stack using recursion
*/

void insertAtBottom(Stack &s, int top){
	if(!s.empty()){
		int e = s.topElement();
		s.pop();
		insertAtBottom(s,top);
		s.push(e);
	}else{
		s.push(top);	
	}
}

/*

Reverse fucntion to reverse the elements of stack
It pops all the elements from the stack and keeps in the function call stack.
When the stack gets empty. It calls insertAtBottom() function on each elements. Which inserts each called element at the bottom. 

*/

void reverse(Stack &s){
	if(!s.empty()){
		int top = s.topElement();
		s.pop();
		reverse(s);
		insertAtBottom(s,top);
	}
}



int main(void){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.display();
	// Reversing stack
	reverse(s);
	cout << "After Reversing:"<<endl;
	s.display();
	return 0;
}

/*
Time Complexity:o(n^2)
*/