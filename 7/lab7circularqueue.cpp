//To implement the Queue ADT  using the array of the size 5
#include<iostream>

class aqueue{
    private:
    int front;
    int rear;
    int arr[5];
    int fixed;

    public:
    aqueue(){
        front=-1;
        rear=-1;
        fixed=5;
        for(int i=0;i<fixed;i++){
            arr[i]=0;
        }
    };
    int enqueue(int num);
    int dequeue();
    int peek();
};

int main(){
    aqueue queue;
    int choice,num,ans;
    while(true){
        printf("\n MENU \n 1)Enqueue \n 2)Dequeue \n 3)Peek \n 4)Exit \n");
        printf("Enter the option :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted :");
                scanf("%d",&num);
                ans=queue.enqueue(num);
                if(ans==-1){
                    printf("Failed to insert !!\n");
                }
                else{
                    printf("Added !!\n");
                }
                break;

            case 2:
                ans=queue.dequeue();
                if(ans==-1){
                    printf("Failed to delete !!\n");
                }
                else{
                    printf("Deleated %d !!\n",ans);
                }
                break;

            case 3:
                ans=queue.peek();
                if(ans==-1){
                    printf("Empty queue !!\n");
                }
                else{
                    printf("The First element is  %d !!\n",ans);
                }
                break;

            case 4:
                printf("Exiting the loop!!!\n");
                break;

            default:
                printf("You have entered wrong option!!!\n");
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

//This function is to enqueue the element in the queue
int aqueue::enqueue(int num){
    int temp;
    temp=((rear+1)%fixed);
    if(temp==front){
        return -1;
    }
    if(front==-1){
        front=0;
    }
    arr[temp]=num;
    rear=temp;
}

//This function is to dequeue the last element out of the queue
int aqueue::dequeue(){
    if(rear==-1){
        return -1;
    }
    int value=arr[front];
    if(front==rear){
        front=rear=-1;
    }
    
    front=(front+1)%5;
    return value;
}

//This function is to peek the element of the list
int aqueue::peek(){
    if(front==-1){
        return -1;
    }
    return arr[front];
}