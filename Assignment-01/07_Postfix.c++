#include <iostream>
#include <stack>
#include <cctype> // For isdigit()

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
    cout << "Enter the Expression: ";
    cin >> postfix_expression;
    int result = evaluate_postfix(postfix_expression);
    cout << "Result: " << result << endl;
    return 0;
}
