//To do the expression tree by getting the postfix expression
#include "extreep.h"

int main() {
    string postfix;
    Node* root = nullptr;
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a postfix expression: ";
                cin >> postfix;
                cout << "Postfix expression stored!\n";
                break;
            case 2:
                if (postfix.empty()) {
                    cout << "No postfix expression provided! Please enter one first.\n";
                } else {
                    root = constructExpressionTree(postfix);
                    cout << "Expression tree constructed!\n";
                }
                break;
            case 3:
                if (root) {
                    cout << "Preorder Traversal: ";
                    preorder(root);
                    cout << endl;
                } else {
                    cout << "Expression tree not yet constructed!\n";
                }
                break;
            case 4:
                if (root) {
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << endl;
                } else {
                    cout << "Expression tree not yet constructed!\n";
                }
                break;
            case 5:
                if (root) {
                    cout << "Postorder Traversal: ";
                    postorder(root);
                    cout << endl;
                } else {
                    cout << "Expression tree not yet constructed!\n";
                }
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from postfix notation
Node* constructExpressionTree(string postfix) {
    stack<Node*> s;
    
    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(new Node(c));
        } else if (isOperator(c)) { 
            Node* node = new Node(c);
            
            node->right = s.top(); s.pop();
            node->left = s.top(); s.pop();
            
            s.push(node);
        }
    }
    
    return s.top();
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

// Postorder traversal 
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}
