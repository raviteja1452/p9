// Finding the stocks span problems using Stack
// p9Scripts


/*
Question: Find the spans for the given set of values in a list.
Span = count of elements just previous to the element and less than the element's value (consecutive).

Algorithm: 
Stacks can be used to solve this problem in a Time complexity of o(n).
Here , if we know the position of the element nearest,previous to the current element and greater than the element, 
We can find the span by substrating its position from current position
1) Traverse from left to right.
Initially P = -1
while traversing from left to right
Repeat the steps below
a) while the stack is not empty and current element > element on the top of stack: pop the element from stack.
      if the stack is empty P = -1 else P = stack.top()
      span[i] = i - P
    push the current element on to the stack.
*/
 
// Here we use stack stl for our implementation 
#include<iostream>
#include<stack>

using namespace std;

int main(void){
	int a[] = {6,3,4,5,2};
	int span[] = {0};
	int size = sizeof(a)/sizeof(int);
	stack<int> s;
	int P = -1;
	for(int i = 0;i < size; i++){
		while((!s.empty()) && (a[s.top()] < a[i])){
			s.pop();
		}
		if(s.empty()){
			P = -1;
		}else{
			P = s.top();
		}
		span[i] = i - P;
		s.push(i);
		cout <<  "span of :"<< i <<"--> " <<span[i]<< endl;
	}
	return 0;
}