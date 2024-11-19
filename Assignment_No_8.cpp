/*
                                                      Assignment No.8
Problem Statement

Write a program to convert infix expression to postfix, infix expression to prefix and evaluation 
of postfix and prefix expression. 


Name: Shyam Sundar Yadav
PRN: 123B1B267
Batch: D3
Course: Data Structures Laboratory

*/


#include <iostream>
#include <string>
#include <cmath>
#define MAX 100
using namespace std;
// Stack class implementation using arrays
class Stack {
    int top;
    char arr[MAX];

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
        } else {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            return '\0';
        }
    }
};

// Stack class for integer evaluation
class IntStack {
    int top;
    int arr[MAX];

public:
    IntStack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int num) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
        } else {
            arr[++top] = num;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            return -1;
        }
    }
};

// Helper functions for operator precedence and checking
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool isLeftAssociative(char op) {
    if (op == '^') return false; // Right-associative for '^'
    return true;                 // Left-associative for others
}

// Function to reverse a string manually 
string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
    return str;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) { // If the character is an operand, add it to the result
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // Pop the '('
        } else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek()) && isLeftAssociative(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    // Reverse the infix expression
    infix = reverseString(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') 
        infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Get postfix of the modified infix
    string postfix = infixToPostfix(infix);

    // Reverse the postfix to get the prefix
    return reverseString(postfix);
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    IntStack st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            st.push(c - '0'); // Assuming single-digit operands
        } else if (isOperator(c)) {
            int val1 = st.pop();
            int val2 = st.pop();

            switch (c) {
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2 / val1); break;
                case '^': st.push(pow(val2, val1)); break;
            }
        }
    }

    return st.pop();
}

// Function to evaluate a prefix expression
int evaluatePrefix(string prefix) {
    IntStack st;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            st.push(c - '0'); // Assuming single-digit operands
        } else if (isOperator(c)) {
            int val1 = st.pop();
            int val2 = st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }

    return st.pop();
}

int main() {
    string infixExp, postfixExp, prefixExp;
    int choice;

    do {
        cout << "\n*** Expression Converter ***\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Evaluate Prefix Expression\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infixExp;
                postfixExp = infixToPostfix(infixExp);
                cout << "Postfix expression: " << postfixExp << endl;
                break;

            case 2:
                cout << "Enter infix expression: ";
                cin >> infixExp;
                prefixExp = infixToPrefix(infixExp);
                cout << "Prefix expression: " << prefixExp << endl;
                break;

            case 3:
                if (postfixExp.empty()) {
                    cout << "Please convert an infix expression to postfix first!\n";
                } else {
                    cout << "Postfix expression: " << postfixExp << endl;
                    cout << "Evaluation result: " << evaluatePostfix(postfixExp) << endl;
                }
                break;

            case 4:
                if (prefixExp.empty()) {
                    cout << "Please convert an infix expression to prefix first!\n";
                } else {
                    cout << "Prefix expression: " << prefixExp << endl;
                    cout << "Evaluation result: " << evaluatePrefix(prefixExp) << endl;
                }
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
