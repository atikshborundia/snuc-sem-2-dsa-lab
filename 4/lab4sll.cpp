//To create a ListADT using Single Linked List
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
//To create nodes using class
class Node{
    public:
    int data;
    Node* next;
};
//Declaration of ListADT using class
class ListADT{
    private:
    Node* head;
    int size=0;
    public:
    ListADT()
    {
        head=nullptr;
    }
    //Declarations for all ListADT fuctions
    int Insert_Beginning(int num);
    int Insert_End(int num);
    int Insert_Position(int num,int position);
    int Delete_Beginning();
    int Delete_End();
    int Delete_Position(int position);
    int search(int num);
    void Display();
    void Display_Reverse();//Displays the Linked List in reverse order
    void Reverser(Node* node);//helps Display_Reverse
    void Link_Reverse();//Reverses the links in the Linked list
    void Exit();//Deletes all Nodes and exits the program
};

int main()
{
    class ListADT list;
    int choice,num,position;
    do//To run till exit is chosen
    {
        //Printing the Menu
        printf("\n\t\tMENU\n");
        printf("\t\t----\n");
        printf("\t 1.Insert at Beginning\n");
        printf("\t 2.Insert at End\n");
        printf("\t 3.Insert at Position\n");
        printf("\t 4.Delete Beginning\n");
        printf("\t 5.Delete End\n");
        printf("\t 6.Delete Position\n");
        printf("\t 7.Search\n");
        printf("\t 8.Display\n");
        printf("\t 9.Display Reverse\n");
        printf("\t10.Reverse Link\n");
        printf("\t11.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
    //Using switch case to differntiate functions
            switch(choice)
            {
     case  1://To insert at the beginning
             printf("Enter the number to be inserted:");
             scanf("%d",&num);
             list.Insert_Beginning(num);
             break;
     case  2://To insert at the end of the list
             printf("Enter the number to be inserted:");
             scanf("%d",&num);
             list.Insert_End(num);
             break;
     case  3://To insert at a certain position in the list
             printf("Enter the number to be inserted:");
             scanf("%d",&num);
             printf("At what position should the number be inserted:");
             scanf("%d",&position);
             list.Insert_Position(num,position);
             break;
     case  4://To Delete the first element in the array
             list.Delete_Beginning();
             break;
     case  5://To Delete the last element in the array
             list.Delete_End();
             break;
     case  6://To Delete a certain element in the array
             printf("Enter the position of the element to be deleted:");
             scanf("%d",&position);
             list.Delete_Position(position);
             break;
     case  7://To search an element in the list
             printf("Enter the element to be searched:");
             scanf("%d",&num);
             list.search(num);
             break;
     case  8://To display the current list
             list.Display();
             break;
     case  9://To display list in the reverse
             list.Display_Reverse();
             break;
     case 10://To Reverse the list 
             list.Link_Reverse();
             break;
     case 11://To exit the program
             list.Exit();
             break;
    default ://Incase of any number other than those mentioned in the switch cases
             printf("Inavlid Choice. Please try again\n");
             continue;        
            }
    }while(choice!=11);//To exit the loop when exit is chosen
}
//To insert in the 1st position the list
int ListADT::Insert_Beginning(int num)
{
 Node* newnode=new Node;
 newnode->data=num;
 newnode->next=nullptr;
 if(head==nullptr)
 {
    head=newnode;
 }
 else
 {
    newnode->next=head;
    head=newnode;
 }
 size+=1;
 Display();
 return(num);
}
//To insert in the last position in the list
int ListADT::Insert_End(int num)
{
 Node* newnode=new Node;
 newnode->data=num;
 newnode->next=nullptr;
 if(head==nullptr)
 {
    head=newnode;
 }
 else
 {
    Node* temp=head;
    while(temp->next!=nullptr)//To goto the required position
    {
        temp=temp->next;
    }
    temp->next=newnode;
 }
 size+=1;
 Display();//To print the new list
 return(num);
}
//To insert at a certain position in the list
int ListADT::Insert_Position(int num,int position)
{
    position-=1;
 Node* newnode=new Node;
 newnode->data=num;
 newnode->next=nullptr;
 int curr=1;
 if(head==nullptr || position<0)//To check if the list is empty or not && position is >0
 {
   Display();
    return(num);
 }
 else if(position==0)
 {
    newnode->next=head;
    head=newnode;
 }
 else
 {
    Node* temp=head;
    while(curr<position && temp!=nullptr)//To goto the required position
    {
        temp=temp->next;
        curr++;
    }
    if(temp!=nullptr)//to check that the node is not empty||Null
    {
    newnode->next=temp->next;
    temp->next=newnode;
    }
    else//If the given position is invalid
    {
        printf("Invalid Position\n");
        return(0);
    }
 }
 size+=1;
 Display();
 return(num);
}
//To delete the element in the 1st position of the list
int ListADT::Delete_Beginning()
{
    Node* temp;
    int del;
    if(head==nullptr)//To check if the list is empty || not
    {
        Display();
        return(0);
    }
    else
    {
        temp=head;
        del=head->data;
        head=head->next;
    }
    size-=1;
    Display();
    delete temp;
    printf("%d is deleted from the list\n",del);
    return(del);
}
//To delete the element in the last position in the list
int ListADT::Delete_End()
{
    int del;
    Node* temp;
    Node* prev;
    if(head==nullptr)//To check the same as in the above function
    {
        Display();
        return(0);
    }
    else if(head->next==nullptr)
    {
        temp=head;
        del=head->data;
        head=head->next;
        delete temp;
    }
    else
    {
     temp=head;
     while(temp->next!=nullptr)
     {
        prev=temp;
        temp=temp->next;
     }
     prev->next=nullptr;
     del=temp->data;
     delete temp;
    }
    size-=1;
    Display();
    printf("%d is deleted from the list\n",del);
    return(del);
}
//To delete the element in a certain position in the list
int ListADT::Delete_Position(int position)
{
    Node* temp;
    Node* prev;
    int curr=1,del;
    if(head==nullptr)
 {
    Display();
    return(0);
 }
 else if(position<1)
 {
    printf("Invalid Position\n");
    return(0);
 }
 else if(position==1)//If its the head
 {
    temp=head;
    del=head->data;
    head=head->next;
    size-=1;
    delete temp;
 }
 else
 {
    temp=head;
    while(curr<position && temp!=nullptr)//To goto the required position
    {
        prev=temp;
        temp=temp->next;
        curr++;
    }
    if(temp!=nullptr)//same as above functions
    {
     prev->next=temp->next;
     del=temp->data;
     size-=1;
     delete temp;
    }
    else
    {
        printf("Invalid Position\n");
        return(0);
    }
 }
 Display();
 printf("%d is deleted from the list\n",del);
 return(del);
}
//To search for an certain position in the list
int ListADT::search(int num)
{
    Node* temp;
    temp=head;
    int curr=1;
    while(temp!=nullptr && temp->data!=num)//To check if the element is present in the list and end the loop at the end of the list
    {
        temp=temp->next;
        curr+=1;
    }
    if(temp!=nullptr && temp->data==num)//To check if the element is found in the list
    {
        printf("Its in %d position\n",curr);
    }
    else{//or not
        printf("The element is not present in the array\n");
    }
    Display();
    return(curr);
}
//To print the elements in the list
void ListADT::Display()
{
    if(head==nullptr)//to check if the list is empty 
    {
        printf("The list is empty\n");
    }
    else//or not
    {
        Node* temp;
        temp=head;
        printf("The List is:\n");
        while(temp!=nullptr)//To goto the end of the list
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    printf("The size is %d\n",size);
}

/*                                                                      This code works as well
void ListADT::Display_Reverse()
{
    int pos=size;
    if(head==nullptr)
    {
        printf("The List is empty\n");
    }
    else
    {
        Node* temp;
        printf("The List in Reverse Order is :\n");
        while(pos!=0)
        {
            temp=head;
            for(int i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            printf("%d\t",temp->data);
            pos-=1;
        }
        printf("\n");
    }
}
  To display the list in reverse order*/
   void ListADT::Display_Reverse()
   {
    if(head==nullptr)
    {
        Display();
    }
    else
    {
        printf("Reverse:\n");
        Reverser(head);
    }
   }
   //To display the list in reverse order through an recursive function
   void ListADT::Reverser(Node* node)
   {
    if(node==nullptr)
    {
        return;
    }
    else
    {
        Reverser(node->next);
    }
    printf("%d\t",node->data);
   }
//To Reverse the links in the linked list
/*                                                                      This code works as well
void ListADT::Link_Reverse()
{
    int pos=size;
    if(head==nullptr)
    {
        Display();
    }
    else
    {
        Node* temp;
        Node* temp1;
        
        while(pos!=1)
        {
            temp=head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            if(pos==size)
            {
            temp1=temp->next;
            }
            temp->next->next=temp;
            pos-=1;
        }
        head->next=nullptr;
        head=temp1;
    }
    Display();
}
*/
void ListADT::Link_Reverse()
{
 Node* prev=nullptr;
 Node* curr=head;
 Node* next=nullptr;
 while(curr!=nullptr)
 {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
 }
 head=prev;
 Display();
}
//To delete all the nodes created during the runtime
void ListADT::Exit()
{
    Node* temp;
    while(head!=nullptr)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    printf("Exiting...\n");
}