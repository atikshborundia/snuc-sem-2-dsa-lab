//Program to convert infix expression to postfix expression and evaluate the postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "3Stack.h"

// Function prototypes
int precedence(char op);
void infixToPostfix(const char* infix, char* postfix);
int evaluatePostfix(const char* postfix);

// Main function
int main() {
    char infix[100], postfix[100];
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Get Infix\n2. Convert Infix to Postfix\n3. Evaluate Postfix\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a valid infix expression: ");
                scanf("%s", infix);
                break;
            case 2:
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
            case 3:
                printf("Evaluation Result: %d\n", evaluatePostfix(postfix));
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-'){
        return 1;
    }
    else if (op == '*' || op == '/'){ 
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    int postIndex = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            postfix[postIndex++] = infix[i];
        } 
        else {
            while (!stack.isEmpty() && precedence(infix[i]) <= precedence(stack.peek())) {
                postfix[postIndex++] = (char)stack.pop();
            }
            stack.push(infix[i]);
        }
    }

    while (!stack.isEmpty()) {
        postfix[postIndex++] = (char)stack.pop();
    }
    postfix[postIndex] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(const char* postfix) {
    Stack stack;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            stack.push(postfix[i]- '0');
        }
        else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            switch (postfix[i]) {
                case '+': 
                    stack.push(val1 + val2);
                    break;
                case '-':
                    stack.push(val1 - val2);
                    break;
                case '*': 
                    stack.push(val1 * val2); 
                    break;
                case '/': 
                    stack.push(val1 / val2); 
                    break;
            }
        }
    }
    return stack.pop(); 
}
