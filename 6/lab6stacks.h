//Header File for 3rd and 4th Question 
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
};

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
    return(element);
}
//To pop the top element in the stack
char StackADT::Pop(){
    if(top==nullptr){
        return('0');
    }
    else{
        Node* temp=top;
        top=top->prev;
        delete temp;
        temp=nullptr;
    }
    return('1');
}
