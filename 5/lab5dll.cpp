/*
    Program: Doubly Linked List with Tail (List ADT)
    Description: This program implements a List ADT using a doubly linked list with a tail.
    It provides menu-driven operations including insertion, deletion, search, and display.
*/

#include <stdio.h>
#include <stdlib.h>

// Class for Doubly Linked List with Tail
class DoublyLinkedList {
private:
    // Node structure
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Destructor to free all nodes
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
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

    // Function to get size
    int getSize() { return size; }
};

int main() {
    DoublyLinkedList list;
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
                if (list.search(num) == -1){
                    printf("Not found\n");
                }
                else{
                    printf("Found at position: %d\n", list.search(num));
                }
                break;
            case 8:
                list.display();
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
void DoublyLinkedList::insertBeginning(int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL){
        head->prev = newNode;
    }
    else{
        tail = newNode;
    }
    head = newNode;
    size++;
}

// Function to insert at the end
void DoublyLinkedList::insertEnd(int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL){
        tail->next = newNode;
    }
    else{
        head = newNode;
    }
    tail = newNode;
    size++;
}

// Function to insert at a specific position
void DoublyLinkedList::insertPosition(int num, int pos) {
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(num);
        return;
    }
    if (pos == size + 1) {
        insertEnd(num);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++){
        temp = temp->next;}
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    size++;
}

// Function to delete from the beginning
int DoublyLinkedList::deleteBeginning() {
    if (head == NULL){
        return -1;
    }    
    Node* temp = head;
    head = head->next;
    if (head != NULL){
        head->prev = NULL;
    }
    else{    
        tail = NULL;
    }
    int deletedValue = temp->data;
    free(temp);
    size--;
    return deletedValue;
}

// Function to delete from the end
int DoublyLinkedList::deleteEnd() {
    if (tail == NULL){
        return -1;
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL){
        tail->next = NULL;
    }
    else{
        head = NULL;
    }
    int deletedValue = temp->data;
    free(temp);
    size--;
    return deletedValue;
}

// Function to delete from a specific position
int DoublyLinkedList::deletePosition(int pos) {
    if (pos < 1 || pos > size){
        return -1;
    }
    if (pos == 1){
        return deleteBeginning();
    }
    if (pos == size){
        return deleteEnd();
    }
    Node* temp = head;
    for (int i = 1; i < pos; i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    int deletedValue = temp->data;
    free(temp);
    size--;
    return deletedValue;
}
// Function to search for an element
int DoublyLinkedList::search(int num) {
    Node* temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == num){
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Element not found
}

// Function to display the list
void DoublyLinkedList::display() {
    Node* temp = head;
    if (!temp) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
