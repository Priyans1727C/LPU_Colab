// You are using GCC
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; 
}

std::string infixToRPN(const std::string& infix) {
    std::stack<char> operatorStack;
    std::stringstream rpn;
    
    for (char c : infix) {
        if (std::isdigit(c)) {
            rpn << c;
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                rpn << " " << operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        } else if (c == ' ') {
          
        } else {
            std::cerr << "Error: Invalid character in input." << std::endl;
            exit(1);
        }
    }

    while (!operatorStack.empty()) {
        rpn << " " << operatorStack.top();
        operatorStack.pop();
    }

    return rpn.str();
}

int main() {
    std::string infixExpression;
    std::getline(std::cin, infixExpression);

    std::string rpnExpression = infixToRPN(infixExpression);

    std::cout << "The Reverse Polish Notation (RPN) expression is: " << rpnExpression << std::endl;

    return 0;
}
