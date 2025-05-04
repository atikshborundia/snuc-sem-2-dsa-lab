#include <stdio.h>
#include <stdlib.h>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    
    Node* head;
    int size;

public:
    // Constructor
    CircularLinkedList(){
        head = NULL;
        size = 0;
    }
    // Destructor
    ~CircularLinkedList(){
        if (!head) return;
        Node* temp = head;
        do {
            Node* next = temp->next;
            free(temp);
            temp = next;
        } while (temp != head);
        head = NULL;
    }
    // Insert at End
    void insertEnd(int num);
    // Delete from Beginning
    int deleteBeginning();
    // Check if list is empty
    bool isEmpty();
    // Display the list
    void display();
};

// Insert at End
void CircularLinkedList::insertEnd(int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    size++;
}

// Delete from Beginning
int CircularLinkedList::deleteBeginning() {
    if (!head) return -1;
    int data;
    if (head->next == head) { // Only one node
        data = head->data;
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* delNode = head;
        data = delNode->data;
        temp->next = head->next;
        head = head->next;
        free(delNode);
    }
    size--;
    return data;
}

// Check if list is empty
bool CircularLinkedList::isEmpty() {
    return head == NULL;
}

// Display the list
void CircularLinkedList::display() {
    if (!head) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
