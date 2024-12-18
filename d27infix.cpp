/*Implement C++ program for expression conversion as infix to postfix and 
its evaluation using stack based on given conditions  
a)	Operands and operator, both must be single character.  
b)	Input Postfix expression must be in a desired format.  
c)	Only '+', '-', '*' and '/ ' operators are expected. 
*/
#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit()
#include <cmath>  // For mathematical operations
using namespace std;

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        // If operand, add to the postfix expression
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop and add to postfix until '(' is found
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '(' from the stack
        }
        // If operator, pop operators from stack with higher or equal precedence
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char ch : postfix) {
        // If operand, push it to the stack
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to integer
        }
        // If operator, pop two operands and apply the operator
        else if (isOperator(ch)) {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top(); // Final result
}

int main() {
    string infix, postfix;
    cout << "Enter a valid infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Result of the Postfix Evaluation: " << result << endl;

    return 0;
}
