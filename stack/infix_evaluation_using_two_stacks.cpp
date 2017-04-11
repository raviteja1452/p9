// Evaluation of Infix Expression using Two Stacks
// p9Scripts

/*
Q: Evalution of Infix Expression using Two Stacks.
Algo:  Here we have two stacks.
1) Operator Stack
2) Operand Stack.

*****
Here we process the given infix expression string from left to right.
1) If we come across an operand , We push the operand into the Operand Stack.
2) If we come across an an operator, We follow the following algorithm for operators

*********
	Priority of operators
	^ --> 4
	*,/ --> 3
	+,- --> 2
	( --> 1
	a) If the opeartor stack is empty, push the operator into the stack.

	b) If the opeartor stack is not empty, compare the priority of operator on the top of the stack to the current operator
	c) let t = priority of operator on the top of the stack, p = priority of current operator
	while(t >= p):
		pop(t)
	after poping all operators whose priority is greater than the current opeartor, push this operator on the stack.
	**. if the operator is ( just push in to the stack, with out considering priority.
	**. if the operator is ) , Pop the opeartors and append till we encounter matching (. don't add (,) to the output.

	After processing completing string. pop all the operators from stack
	
********
	*** When an operator is poped from the stack, perform calculation for the top two operands of stack with this operator. Push the result on to the operand stack .

	
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


int calculate(char op, int l , int r){
	if(op == '+'){
		return l + r;
	}else if(op == '-'){
		return l - r ;
	}else if(op == '*'){
		return l * r;
	}else if(op == '/'){
		if(r > 0){
			return l/r;
		}
		return 0;
	}else if(op == '^'){
		return l ^ r;
	}
	return -1;
}


int main(void){
	char str[] = "3+4*5*(4+3)-1/2+1";
	//char str[] = "3+4*5*4+3-1/2+1";
	int l = sizeof(str)/sizeof(char);
	int k = 0;
	stack<char> s;
	stack<int> op_s;
	cout <<"InFix Expression: " << str << endl;
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == '('){
			s.push('(');
		}else if(str[i] == ')'){
			while(s.top() != '('){
				 int r = op_s.top();
				 op_s.pop();
				 int l = op_s.top();
				 op_s.pop();
				 int re = calculate(s.top(),l,r);
				 op_s.push(re);
				s.pop(); 
			}
			s.pop();
		}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			int pC = pri(str[i]);
			while(!s.empty() && pri(s.top()) >= pC){
				int r = op_s.top();
				 op_s.pop();
				 int l = op_s.top();
				 op_s.pop();
				 int re = calculate(s.top(),l,r);
				 op_s.push(re);
				s.pop(); 
			}
			s.push(str[i]);
		}else{
			op_s.push(int(str[i])- 48);
		}
		i++;
	}
	while(!s.empty()){
		int r = op_s.top();
		op_s.pop();
		int l = op_s.top();
		op_s.pop();
		int re = calculate(s.top(),l,r);
		op_s.push(re);
		s.pop(); 
	}

	cout <<"Result: " << op_s.top() << endl;
	return 0;
}