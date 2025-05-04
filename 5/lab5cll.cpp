/*
    Program: Circular Linked List (List ADT)
    Description: This program implements a List ADT using a circular linked list.
    It provides menu-driven operations including insertion, deletion, search, and display.
*/

#include <stdio.h>
#include <stdlib.h>

// Class for Circular Linked List
class CircularLinkedList {
private:
    // Node structure encapsulated within the class
    struct Node {
        int data;
        Node* next;
    };
    
    Node* head;
    int size;

public:
    // Constructor
    CircularLinkedList() {
        head = NULL;
        size = 0;
    }

    // Destructor to free all nodes
    ~CircularLinkedList() {
        if (head == NULL){
            return;
        }
        Node* temp = head;
        do {
            Node* next = temp->next;
            free(temp);
            temp = next;
        } while (temp != head);
        head = NULL;
    }

    // Function to insert at the beginning
    void insertBeginning(int num);
    
    // Function to insert at the end
    void insertEnd(int num);
    
    // Function to insert at a specific position
    void insertPosition(int num, int pos);
    
    // Function to delete from the beginning
    int deleteBeginning();
    
    // Function to delete from the end
    int deleteEnd();
    
    // Function to delete from a specific position
    int deletePosition(int pos);
    
    // Function to search for an element
    int search(int num);
    
    // Function to display the list
    void display();
};

int main() {
    CircularLinkedList list;
    int choice, num, pos;
    do {
        printf("\n1) Insert Beginning\n2) Insert End\n3) Insert Position\n4) Delete Beginning\n5) Delete End\n6) Delete Position\n7) Search\n8) Display\n9) Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &num);
                list.insertBeginning(num);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d", &num);
                list.insertEnd(num);
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position: ");
                scanf("%d", &pos);
                list.insertPosition(num, pos);
                break;
            case 4:
                printf("Deleted: %d\n", list.deleteBeginning());
                break;
            case 5:
                printf("Deleted: %d\n", list.deleteEnd());
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Deleted: %d\n", list.deletePosition(pos));
                break;
            case 7:
                printf("Enter the number to search: ");
                scanf("%d", &num);
                pos = list.search(num);
                if (pos != -1) {
                    printf("Found at position: %d\n", pos);
                }
                else {
                    printf("Element not found.\n");
                }
                break;
            case 8:
                printf("Circular Linked List: [ ");
                list.display();
                printf("]\n");
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);
    return 0;
}

// Function to insert at the beginning
void CircularLinkedList::insertBeginning(int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } 
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    size++;
}

// Function to insert at the end
void CircularLinkedList::insertEnd(int num) {
    if (!head) {
        insertBeginning(num);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    size++;
}

// Function to insert at a specific position
void CircularLinkedList::insertPosition(int num, int pos) {
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(num);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

// Function to delete from the beginning
int CircularLinkedList::deleteBeginning() {
    if (!head) {
        printf("List is empty!\n");
        return -1;
    }
    int data;
    if (head->next == head) {
        data = head->data;
        free(head);
        head = NULL;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        data = temp->data;
        temp->next = head->next;
        head = head->next;
        free(temp);
    }
    size--;
    return data;
}

// Function to delete from the end
int CircularLinkedList::deleteEnd() {
    if (!head){
        return -1;
    }
    int data;
    if (head->next == head) {
        data = head->data;
        free(head);
        head = NULL;
    }
    else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        data = temp->data;
        free(temp);
    }
    size--;
    return data;
}

// Function to delete from a specific position
int CircularLinkedList::deletePosition(int pos) {
    if (pos < 1 || pos > size){
        return -1;
    }
    if (pos == 1) {
        return deleteBeginning();
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    int data = temp->data;
    free(temp);
    size--;
    return data;
}

// Function to search for an element
int CircularLinkedList::search(int num) {
    if (!head){
        return -1;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == num){
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

// Function to display the list
void CircularLinkedList::display() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}



