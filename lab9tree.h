// ExpressionTree prototype
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
    
    Node(char val) {
        value = val;
        left = right = nullptr;
    }
};


bool isOperator(char c);
Node* constructExpressionTree(string postfix);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);

#endif
