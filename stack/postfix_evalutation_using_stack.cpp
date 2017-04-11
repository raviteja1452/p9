// Evaluation of a Postfix Expression using Stack
// p9Scripts
/*
Q:Evaluation of a Postfix Expressoin using Stack
Algo: We process the Postfix String from List
We use a Stack Stl (Operand Stack) for our Algorithm
If the present character is operand , push to stack.
If the present character is operator, pop top two elements of stack. perform opeartion between them and push to stack.

The last element remaining in stack , after completely processing stack is the Answer 
*/

#include<iostream>
#include<stack>

using namespace std;

int calculate(char op, int l , int r){
	//cout << op << l << r << endl;
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
	char str[] = "345*43+*+12/-1+";
	cout << "Expression : " << str << endl;
	stack<int> s;
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();
			int re = calculate(str[i],l,r);
			//cout << re << endl;
			s.push(re);
		}else{
			s.push(int(str[i]) - 48);
		}
		i++;
	}
	cout << "Result: "<<s.top()<< endl;
	return 0;
}