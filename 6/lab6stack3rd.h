// This is a header file containg push, pop, peek and isEmpty functions for stack implementation

#include <stdio.h>
#include <stdlib.h>

//Structure for stack
class Stack {
private:
    struct Node {
        int data;
        struct Node *next;
    }*top;

public:
    Stack() { top = NULL; }

    bool push(int value);// Function to push an element into the stack
    int pop();// Function to pop an element from the stack
    int peek();// Function to peek the top of the stack
    bool isEmpty();// Function to check if the stack is empty
};

// Function to push an element into the stack
bool Stack::push(int value) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
    return true;
}

// Function to pop an element from the stack
int Stack::pop() {
    if (top == NULL) {
        return -1; // Stack underflow
    }

    struct Node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);

    return poppedValue;
}

// Function to peek the top of the stack
int Stack::peek() {
    if (top == NULL) {
        return -1; // Stack is empty
    }
    return top->data;
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return top == NULL;
}

