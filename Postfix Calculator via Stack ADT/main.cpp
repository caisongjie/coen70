#include<cmath>
#include<iostream>
#include"lab3.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

int main()
{
    Stack s;
 	string expr, token;
	getline(cin, expr);
    
    
	istringstream stream(expr);
    float num1, num2;
	
    
	while(stream >> token) {
        
		if(token.length() > 1) {
			double x = atof(token.c_str());
			s.push(x);
			continue;
            
		}
        
		switch (token[0]){
			case '+':
				num1 = s.pop();
				num2 = s.pop();
				s.push(num1 + num2);
				break;
			case '-':
				num2 = s.pop();
				num1 = s.pop();
				s.push(num1 - num2);
				break;
			case '*':
				num1 = s.pop();
				num2 = s.pop();
				s.push(num1 * num2);
				break;
			case '/':
				num2 = s.pop();
				num1 = s.pop();
				s.push(num1 / num2);
				break;
			default:
				double x = atof(token.c_str());
				s.push(x);
				break;
        }
        
		
	}
    
    
	cout << "Result: " << s.pop() << endl;
    
    
	return 0;
    
}

