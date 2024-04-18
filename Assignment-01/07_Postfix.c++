// Question: 
// Write a program/algorithm to evaluate postfix expression



// Code:

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int perform_operation(int operand1, int operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw invalid_argument("Division by zero!");
            }
            return operand1 / operand2;
        default:
            throw invalid_argument("Invalid operator");
    }
}

int evaluate_postfix(string expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = perform_operation(operand1, operand2, c);
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string postfix_expression ;
    
    cout << "\nEvaluate Postfix Expressions:\n=============================\n";
    cout << "\nEnter the Expression: ";
    getline(cin, postfix_expression);
    int result = evaluate_postfix(postfix_expression);
    cout << "Result: " << result << "\n\n";
    return 0;
}



// Output:
/*
Evaluate Postfix Expressions:
=============================

Enter the Expression: 8 2 / 3 *
Result: 12
*/