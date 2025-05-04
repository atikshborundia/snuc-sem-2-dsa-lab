//To create a Menu driven C++ Program for StackADT operations using an array of size 5
//Time Complexity for Push Operation is O(1)
//Time Complexity for Pop Operation is O(1)
//time Complexity for Peek Operation is O(n)
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
//class to declare StackADT operations/functions
class StackADT{
    private:
    char array[5];
    char *top=NULL;
    int size=0;
    public:
    char Push(char element);//To push the elements into the stack
    char Pop();//To pop the top element present in the stack
    void Peek();//To peek at the top element in the stack
};
int main(){
    char choice,element;
    class StackADT stack;
    do{
        printf("\n\t\t  Stack\n\t\tMENU\n\t\t----\n");
        printf("\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit\nEnter your choice:");
        scanf(" %c",&choice);
            switch(choice)
            {
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
    if(top==NULL){
        array[0]=element;
        top=array;
        size=1;
        printf("%c is pushed into the Stack\n",element);
    }
    else{
        if(size<5){
            array[size]=element;
            top=&array[size];
            size+=1;
            printf("%c is pushed into the Stack\n",element);
        }
        else{
            printf("The Stack is full\n");
        }
    }
    return(element);
}
//To pop the top element from the stack
char StackADT::Pop(){
    if(top==NULL){
        printf("The Stack is empty\n");
        return('0');
    }
    else{
        if(size==1){
            top=NULL;
            printf("%c is popped from the stack\n",array[0]);
            size=0;
        }
        else{
            top=&array[size-2];
            size-=1;
            printf("%c is popped from the stack\n",array[size]);
        }
    }
    return(array[size]);
}
//To peek at the top element in the stack
void StackADT::Peek(){
    if(top==NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("%c is at the top of the stack\n",*top);
    }
}