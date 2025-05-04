//To create a menu driven C++ program for StackADT operations using single linked list.
//Time Complexity for Push Operation is O(1)
//Time Complexity for Pop Operation is O(1)
//Time Complexity for Peek Operation is O(n)

#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
//class to declare StackADT functions
class StackADT{
    private:
    struct Node{
        char data;
        Node* prev;
    };
    Node* top;
    public:
    //constructor
    StackADT():top(nullptr) {}
    //destructor
    ~StackADT(){
        Node* temp;
        while(top!=nullptr){
            temp=top;
            top=top->prev;
            delete temp;
        }
        temp=nullptr;
    }
    char Push(char element);//To push an element into the stack
    char Pop();//To pop the top element from the stack
    void Peek();//To peek at the top element in the stack
};
int main(){
    char choice,element;
    class StackADT stack;
    do{
        printf("\n\t\t  Stack\n\t\tMENU\n\t\t----\n");
        printf("\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit\nEnter your choice:");
        scanf(" %c",&choice);
            switch(choice){
        case '1':printf("Enter the element to be pushed into the stack:");
                 scanf(" %c",&element);
                 stack.Push(element);
                 break;
        case '2':stack.Pop();
                 break;
        case '3':stack.Peek();
                 break;
        case '4':printf("Exiting...\n");
               break;
        default:printf("Invalid Choice\n");
                continue;        
            }
    }while(choice!='4');
}
//To push an element into the stack
char StackADT::Push(char element){
    Node* newnode=new Node;
    newnode->data=element;
    newnode->prev=nullptr;
    if(top==nullptr){
        top=newnode;
    }
    else{
        newnode->prev=top;
        top=newnode;
    }
    printf("%c is pushed into the stack\n",element);
    return(element);
}
//To pop the top element in the stack
char StackADT::Pop(){
    if(top==nullptr){
        Peek();
        return('0');
    }
    else{
        Node* temp=top;
        top=top->prev;
        printf("%c is popped from the stack\n",temp->data);
        delete temp;
        temp=nullptr;
    }
    return('1');
}
//To peek at the top element of the stack
void StackADT::Peek(){
    if(top==nullptr){
        printf("The Stack ia empty\n");
    }
    else{
        printf("%c is at the top of the stack\n",top->data);
    }
}