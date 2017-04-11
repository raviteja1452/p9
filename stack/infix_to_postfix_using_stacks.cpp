// Conversion from an Infix Expression to Postfix Expression using stacks
// p9Scripts
/*
Q) Convert an Infix Expression to Post Expression using Stack.
Algo: 
1) We use Stack stl for our purpose.
2) Process the Infix Expression from left to right.
3) For each character in string: 
	If its an operand, output it and move to next.
	If its an operator, follow the steps below.	
	*********
	Priority of operators
	^ --> 3
	*,/ --> 2
	+,- --> 1
	a) If the stack is empty, push the operator into the stack.

	b) If the stack is not empty, 
	compare the priority of operator on the top of the stack to the current operator
	c) let t = priority of operator on the top of the stack, p = priority of current operator
	while(t >= p):
		pop(t)
	after poping all operators whose priority is greater than the current opeartor, push this operator on the stack.
	**. if the operator is ( just push in to the stack, with out considering priority.
	**. if the operator is ) , Pop the opeartors and append till we encounter matching (. don't add (,) to the output.

	After processing completing string. pop all the operators from stack

*/

#include<iostream>
#include<stack>

using namespace std;

int pri(char ch)
{
    switch (ch)
    {
    	case '(':
    		return 1;
	    case '+':
	    case '-':
	        return 2;

	    case '*':
	    case '/':
	        return 3;

	    case '^':
	        return 4;
    }
    return -1;
}


int main(void){
	char str[] = "3+4*5*(4+3)-1/2+1";
	//char str[] = "3+4*5*4+3-1/2+1";
	int l = sizeof(str)/sizeof(char);
	int k = 0;
	stack<char> s;
	cout <<"InFix Expression: " << str << endl;
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == '('){
			s.push('(');
		}else if(str[i] == ')'){
			while(s.top() != '('){
				str[k++] = s.top();
				s.pop(); 
			}
			s.pop();
		}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			int pC = pri(str[i]);
			while(!s.empty() && pri(s.top()) >= pC){
				str[k++] = s.top();
				s.pop(); 
			}
			s.push(str[i]);
		}else{
			str[k++] = str[i];
		}
		i++;
	}
	while(!s.empty()){
		str[k++] = s.top();
		s.pop(); 
	}
	if(k < l -1){
		str[k++] = '\0';
	}
	cout <<"PostFix Expression: " << str << endl;
	return 0;
}