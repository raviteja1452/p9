// Balancing Symbols ***Braces like [],(),{}***  using Stacks 
// p9scripts
/*
Q: Find out whether a given string of symbols is balanced or not
Algorithm:
We use C++ stack stl.
Move from left to right of string.
1) Push into stack if you encounter any opening brace [ , { , ( 
2) When you encounter a closing brace, compare it with the top of stack. 
	If its matching with its counter opening brace. continue to next by popping the stack.
	Else break from the loop and return not balanced.
*/

#include<iostream>
#include<stack>

using namespace std;

int main(void){
	stack<char> s;
	char str[] = "{{(())}}[[{{}}]]";
	//char str[] = "{{(())}}[[{{}}]";
	int l = sizeof(str)/sizeof(char);
	int i =0;
	for(i = 0;i < l; i++){
		if(str[i] == '{' || str[i] == '(' || str[i] == '['){
			s.push(str[i]);
		}else if(str[i] == '}'){
			if(!s.empty() && s.top() == '{'){
				s.pop();
			}else{
				break;
			}
		}else if(str[i] == ']'){
			if(!s.empty() && s.top() == '['){
				s.pop();
			}else{
				break;
			}

		}else if(str[i] == ')'){
			if(!s.empty() && s.top() == '('){
				s.pop();
			}else{
				break;
			}
		}
	}
	if(i == l && s.empty()){
		cout << "Balanced" << endl;
	}else{
		cout << "Not Balanced" << endl;
	}
	return 0;	
}

/*
Time Complexity: O(n), One traversal from left to right

*/