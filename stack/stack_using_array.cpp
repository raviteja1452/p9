// Stack Using an Array
// p9Scripts 

// Implementaion of Stack using Array of Fixed size



#include<iostream>

using namespace std;

class Stack{
	private:
		//Maximum Size of Stack is Private 
		int stack[5];
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

// Complexities

// Time Complexity to push an element is o(1)
// Time Complexity to pop an element is o(1)
// Time Complexity to Delete complete Stack is o(1)
// Time Complexity to get size is o(1)
