// Finding the Largest Area Under a Histogram using Stacks
// p9Scripts
/*
Question:
1) Find the Largest Area Under a Histogram. Each bar of Histogram is considered of width 1.

Algorithm:
	Here we use stack for finding Largest Area under a Histogram. 
	1) Assumptions: Each bar of Histogram is of width 1 unit.
	MaxArea = -1 ;
	2) We traverse the Histogram from left to right. Repeat the steps 3 - 5 till we complete all bars in Histogram.
	3) If stack is empty or element at the top of stack is less than the current element , we push the element to stack.
	4) If the current element is equal to the element at the top of the stack, we ignore the element.
	5) If the current element is less than the element at the top of the stack. We pop the element from the stack and Calculate the Area with respect to that bar as follows.
	Area = length_of_the_bar*(position_current - position_of stack[top-1] - 1)
	if Area > MaxArea then MarArea = Area.

	Proceed as follows till we reach the end of the histogram.
	Now pop the stack and Area with respect to the last element present in stack = length*size_of_stack
	If Area > MaXArea then MaxArea = Area

*/

#include<iostream>
#include<stack>

using namespace std;

int main(void){
	// Here we use Stack Stl for our operations
	// Histogram Heights are represented by Array a
	int MaxArea = -1,Area = -1;
	int a[] = {3,2,5,4,3,6,2,2,1};
	//int a[] = {6,2,5,4,5,1,6};
	int size = sizeof(a)/sizeof(int);
	// Stack Stl
	stack<int> s;
	// Traversing the list from left to right
	for(int i = 0 ; i < size; i++){
		// If stack is empty or If the top element is less than the Current element, Element is pushed to stack
		if(s.empty() || (a[s.top()] < a[i])){
			s.push(i);
		}else{
			// If current element is smaller than element at the top of the stack. 
			// Pop the top element and find area with respect to it, till the top of stack is less than the current element or stack is empty.
			// Then push the current element.
			while(!s.empty() and a[s.top()] > a[i]){
				int h = a[s.top()];
				s.pop();
				int r = i;
				int l = -1;
				if(!s.empty()){
					l = s.top();
				}
				int w = r  - l - 1;
				Area = h * w;
				cout << "Area with respect to : " << h << " -- >" << Area << endl;
				if(Area > MaxArea){
					MaxArea = Area;
				}
			}
			if(s.empty() || (a[s.top()] < a[i])){
				s.push(i);
			}
		}
	}
	while(!s.empty()){
		int h = a[s.top()];
		s.pop();
		int r = size;
		int l = -1;
		if(!s.empty()){
			l = s.top();
		}
		int w = r  - l - 1;
		Area = h*w;
		cout << "Area with respect to : " << h << " -- >" << Area << endl;
		if(Area > MaxArea){
			MaxArea = Area;
		}
	}
	cout << "Max Area : " << MaxArea << endl;
	return 0;
}

// Time Complexity:

// Although we have a loop inside a loop . As we observe. Each element of list is Entered into stack once. and poped from stack once. 
// By Doing Amortized analysis of each step , we observe that, while loop in side the for loop is executed at max of n times over all the loops. 
// So time complexity for the Above algorithm is: T(n)  = o(n)
// Space Complexity = o(n), as it requires a stack for the opeartions