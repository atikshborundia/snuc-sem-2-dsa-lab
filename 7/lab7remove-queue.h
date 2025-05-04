//This header file is used to remove previous characters whenever '+' occurs
#include <cstdio>
#include <cstdlib>
#include <string.h>

class stack{
    private:
        int cur=0;
        int value;
        struct node{
            char data;
            struct node *next;
        }*head;

    public:
        stack(){
            head=NULL;
        }
        void push(char num);
        int pop();
        void check(char string[],int len);
        void reverse(struct node *current);
};

//This function is used to push a element in the stack
void stack::push(char num){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if (head==NULL){
        temp->next=NULL;
        head=temp;
        cur++;    
    }
    else{
        temp->next=head;
        head=temp;
        cur++;    
    }
}


//This function is used to pop a element from the stack
int stack::pop(){
    if (cur==0){
        return -1;
    }
    else{
        struct node *temp=head;
        value=temp->data;
        head=temp->next;
        free(temp);
        cur--;
        return value;
    }
}

//This function is used to pop and push elements into the queue
void stack::check(char string[],int len){
    int temp;
    for(int i=0;i<len;i++){
        if(string[i]!='+'){
            push(string[i]);
        }
        else{
            temp=pop();
            if (temp==-1){
                printf("Invalid input\n");
                return;
            }
        }
    }
    if(head==NULL){
        printf("Empty string\n");
    }
    reverse(head);
}

//This function is used to print elements in reverse without actually reversing it
void stack::reverse(struct node *current) {
    if (current == NULL) {
        return;
    }
    reverse(current->next);
    printf("%c",current->data);
}