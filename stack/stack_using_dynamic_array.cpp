// Stack Using a Dynamic Array
// p9Scripts 

// Implementaion of Stack using a Dynamic Array
/* 
	Implementing stack using Dynamic Array to overcome the exception of Overflow when the array gets full.
	1) When the array gets full, we dynamically take a new array of bigger size and copy the previous elements to new array and push the new element
	2) First approach is to increase the size of new array by +1
	3) Second approach is to increase the size of new array by twice. 
	4) Comparing the Time complexity in both the cases.

*/

#include<iostream>

using namespace std;

class Stack{
	private:
		//Maximum Size of Stack is Private 
		int * stack;
		int * dummy;
		int top,max;

		// Increase the size of stack by 1
		int incStack(){
			dummy = stack;
			stack = new int[max + 1];
			for(int i = 0; i < max; i++){
				stack[i] = dummy[i];
			}
			max = max + 1;
			cout << "Stack is resized to " << max << endl;
			delete [] dummy;
			return 1;
		}
		// Doubling the stack by twice
		int doubleStack(){
			dummy = stack;
			stack = new int[max*2];
			for(int i = 0; i < max; i++){
				stack[i] = dummy[i];
			}
			max = max *2;
			cout << "Stack is resized to " << max << endl;
			delete [] dummy;
			return 1;
		}

	public:
		// Constructor of Stack
		Stack(void){
			cout << "initialized a stack" << endl;
			stack = new int [1];
			top = -1;
			max = 1;
		}

		// Push operations on stack
		int push(int value){
			if(top >= max - 1){
				//incStack();
				doubleStack();
			}
			top = top + 1;
			stack[top] = value;
			cout << stack[top] << " is pushed to stack" << endl;
			for(int i = 0; i <= top;i++){
				cout<< stack[i]<<endl;
			}
			return 1;
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
				return 1;
			}
			cout << "stack is empty" << endl;
			return 0;
		}

		// Length of stack

		int length(){
			return top + 1;
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

/*
Here incStack implements increase the stack by +1
doubleStack implements increase the stack by double

Time complexity in inc +1
T(1) =  0
T(2) = 1 + 0
T(n-1) = n-2 + .. 1 (no of copy operations)
Therefore T(n) = n + n -1  + ..... 1 = o(n^2);

Time Complexity for double strategy

T(n) = n/2 + n/4 + n/8 + .... + 1;
T(n) = n(1/2*(1 - (1/2)^k)/ =~ o(n)
k = log2(n)

Therefore Time Complexity of Double Strategy is less than the Time complexity of Inc + 1 Strategy.

*/

// Complexities

// For Inc + 1.
// Time Complexity to push an element is o(n)
// Time Complexity to pop an element is o(1)
// Time Complexity to Delete complete Stack is o(1)
// Time Complexity to get size is o(1)

// For Doubling Strategy.
// Time Complexity to push an element is o(1)
// Time Complexity to pop an element is o(1)
// Time Complexity to Delete complete Stack is o(1)
// Time Complexity to get size is o(1)
