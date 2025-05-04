/*
    Program: Round Robin Scheduling using Circular Linked List
    Description: This program implements the Round Robin scheduling algorithm
    using a circular linked list. It allows inserting processes with an execution
    time, executing them based on a fixed time slice, and handling remaining time.
*/

#include <stdio.h>
#include "circular_linked_list.h" // Custom header file for CircularLinkedList class

int main() {
    CircularLinkedList processQueue;
    int choice, timeSlice, execTime;
    
    printf("Enter the fixed time slice for execution: ");
    scanf("%d", &timeSlice);
    
    do {
        printf("\n1) Insert Process\n2) Execute\n3) Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter process execution time: ");
                scanf("%d", &execTime);
                processQueue.insertEnd(execTime);
                break;
            case 2:
                if (processQueue.isEmpty()) {
                    printf("No processes in queue!\n");
                } else {
                    execTime = processQueue.deleteBeginning();
                    printf("Executing process with %d time units\n", execTime);
                    execTime -= timeSlice;
                    if (execTime > 0) {
                        printf("Process needs more time, re-adding with %d time units\n", execTime);
                        processQueue.insertEnd(execTime);
                    } else {
                        printf("Process completed!\n");
                    }
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}
