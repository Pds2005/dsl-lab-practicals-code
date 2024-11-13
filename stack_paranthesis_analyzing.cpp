#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isWellParenthesized(const string& expression) {
    stack<char> s;  // Stack to store opening brackets
    
    // Iterate through each character in the string
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        // Push opening brackets to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Check if closing brackets match the top of the stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty, there's no matching opening bracket
            if (s.empty()) {
                return false;
            }

            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                s.pop();  // Pop the matched opening bracket
            } else {
                return false;  // Mismatched brackets
            }
        }
    }
    
    // If stack is empty, all brackets are matched correctly
    return s.empty();
}

int main() {
    string expression;
    
    cout << "Enter an expression: ";
    getline(cin, expression);  // To allow spaces in the expression

    // Check if the expression is well-parenthesized
    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is NOT well-parenthesized." << endl;
    }

    return 0;
}
