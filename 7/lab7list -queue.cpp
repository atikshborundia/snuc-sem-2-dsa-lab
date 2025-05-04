// This code is to show the Queue ADT in the linked list !!!
#include<iostream>
#include<cstdlib>

class lque{
    private:
    struct node{
        struct node* pre;
        int data;
        struct node* link;
    };
    struct node* head;
    struct node* tail;
    int cur;

    public:
    lque(): head(NULL){}
    int enqueue(int num);
    int dequeue();
    int peek();
};

int main(){
    lque q;
    int num,choice,ans;
    while(true){
        printf("\n MENU \n 1)Enqueue \n 2)Dequeue \n 3)Peek \n 4)Exit \n");
        printf("Enter the option :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted :");
                scanf("%d",&num);
                ans=q.enqueue(num);
                if(ans==-1){
                    printf("Failed to insert !!\n");
                }
                else{
                    printf("Added !!\n");
                }
                break;

            case 2:
                ans=q.dequeue();
                if(ans==-1){
                    printf("Failed to delete !!\n");
                }
                else{
                    printf("Deleated %d !!\n",ans);
                }
                break;

            case 3:
                ans=q.peek();
                if(ans==-1){
                    printf("Empty Queue !!\n");
                }
                else{
                    printf("The first element is  %d !!\n",ans);
                }
                break;

            case 4:
                printf("Exiting the loop!!!\n");
                break;

            default:
                printf("You have entered the wrong option !!!\n");
        }
        if(choice==4){
            break;
        }
        else{
            continue;
        }
    }

    return 0;
}

//To enqueue in the element inside the queue
int lque :: enqueue(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        return 0;
    }
    if(head==NULL){
        newnode->data=num;
        newnode->link=head;
        newnode->pre=NULL;
        head=newnode;
        tail=newnode;
    }
    else{
        newnode->data=num;
        newnode->link=NULL;
        newnode->pre=tail;
        tail->link=newnode;
        tail=newnode;
    }
    cur++;
    return 1;
}

//To dequeue out the element from the queue
int lque :: dequeue(){
    int value;
    if(head==NULL){
        return -1;
    }
    struct node* temp=head;
    value=temp->data;
    if(temp->link!=NULL){
        temp->link->pre=NULL;
    }
    head=temp->link;
    if(head==NULL){
        tail=NULL;
    }
    free(temp);
    cur--;
    temp=head;
    return value;
}

//TO peek the last element of the queue
int lque :: peek(){
    if(head==NULL){
        return -1;
    }
    int temp=head->data;
    return temp;
}
