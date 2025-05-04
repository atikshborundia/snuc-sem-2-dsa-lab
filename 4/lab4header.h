#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
//To create NOdes
class Node
{
 public:
 int data;
 class Node* next=nullptr;
};
//Declaration of ListADT using class for declaring required functions
class ListADT
{
private:
 Node* head1=nullptr;//Points to the 1st element in list 1 (To null ar start)
 Node* head2=nullptr;//Points to the 1st element in list 2 (To null ar start)
 Node* head3=nullptr;//Points to the 1st element in list 3 (To null ar start)
 Node* gethead(int list)//To get the address of the required head of a list
 {
    if(list==1)//list 1 is chosen
    {
        return head1;//address of head of list 1 is being returned
    }
    else if(list==2)//list 2 is chosen
    {
        return head2;//address of head of list 2 is being returned
    }
    else if(list==3)//list 3 is chosen
    {
        return head3;//address of head of list 3 is being returned
    }
 };
 public:
 //Declarations of Functions
 int Insert_Ascending(int,int);//Inserts nodes into a given list in ascending order
 int Merge();//To merge list 1 and list 2 into list 3 in ascending order
 void Display();//To print all 3 lists
 void Delete();//To delete the merged list
 void Exit();//To free all the nodes created during runtime
};
//To insert elements in the linked list in ascending order
int ListADT::Insert_Ascending(int num,int list)
{
    Node* head=nullptr;//creates a head pointer to access the head of the required list
    if(list==1&&head1!=nullptr)//for 1st list
    {
        head=head1;
    }
    else if(list==2 &&head2!=nullptr)//for 2nd list
    {
        head=head2;
    }
    Node* curr;//To compare the element in the list with the inserted element to be inserted
    Node* prev;//To change the previous nodes next to the newnodes address
    Node* newnode=new Node;//To store the new element in a node
    newnode->data=num;
    newnode->next=nullptr;
    if(head==nullptr)//if the list is empty
    {
        head=newnode;
        if(list==1)
        {
            head1=head;
        }
        else if(list==2)
        {
            head2=head;
        }
    }
    else//if not empty
    {
        if(head->data>num)//if the 1st element is greater then the number being inserted, then the head needs to be changed
        {
            newnode->next=head;
            head=newnode;
            if(list==1)
            {
                head1=head;
            }
            else if(list==2)
            {
                head2=head;
            }
        }
        else
        {
         curr=head;
            while(curr!=nullptr && curr->data <= num)//To check where the new node should be inserted so it would be in ascending order
            {
                prev=curr;
                curr=curr->next;
            }
            if(curr!=nullptr &&curr->data>num)//if its in the middle of an array
            {
             newnode->next=curr;
             prev->next=newnode;
            }
            else //if its at the end of the array
            {
                prev->next=newnode;
            }
            
        }
    }
    Display();
    return(num);
}

//To merge list 1 and list 2 in ascending order in list 3
int ListADT::Merge()
{
    int choice;
    Node* temp1;//To hold nodes in list1
    Node* temp2;//to hold nodes in list2
    Node* temp3=nullptr;//to change the next of nodes and link it to list3
    if(head1==nullptr && head2==nullptr)//if Both lists are empty
    {
        printf("List 1 and List2 are empty\nTry again\n");
        if(head3!=nullptr)//if a merged list already exits
        {
            printf("Although do you want to empty the merged list?\n1.Yes\n2.No\nEnter Your Choice:");
            scanf("%d",&choice);
            if(choice==1)
            {
            Delete();//Deletes list 3 
            printf("Deleted successfully\n");
            }
        }
        return(1);
    }
    else
    {
        temp1=head1;//Holds 1st node in list1
        temp2=head2;//Holds 1st node in list2
        if(head3!=nullptr)//if a merged list already exits we need to delete it to create a new merged list
        {
            Delete();//deletes merged list
        }
        while(temp1!=nullptr && temp2!=nullptr)//To compare the elements in the list till either list becomes empty
        {
                if(head3==nullptr)//if the merged list is empty
                {
                    if(temp1->data<temp2->data)//if list1 element is less than list2 element
                    {
                        head3=temp1;
                        temp1=temp1->next;//                                    inserts 1st element of list1 in the head list3
                        temp3=head3;//to point to the last element in the list3
                    }
                    else if(temp2->data<temp1->data)//if list2 element is less than list1 element
                    {
                        head3=temp2;
                        temp2=temp2->next;//                                    inserts 1st element of list2 in the head list3
                        temp3=head3;//to point to the last element in the list3
                    }
                    else if(temp1->data==temp2->data)//if both elements of each list are equal
                    {
                        head3=temp1;
                        temp1=temp1->next;
                        temp3=head3;
                        temp3->next=temp2;//                                    inserts list1 element first and then inserts the list2 element||node
                        temp2=temp2->next;
                        temp3=temp3->next;//to point to the last element in the list3
                    }
                    
                }
                else
                {
                    if(temp1->data<temp2->data)//if list1 element is less than list2 element
                    {
                        temp3->next=temp1;
                        temp1=temp1->next;//inserts the list1 element in list3
                        temp3=temp3->next;//to point to the last element in the list3
                    }
                    else if(temp2->data<temp1->data)//if list2 element is less than list1 element
                    {
                        temp3->next=temp2;
                        temp2=temp2->next;//inserts the list2 element in list3
                        temp3=temp3->next;//to point to the last element in the list3
                    }
                    else//i.e., both elements of list1 and list2 are equal
                    {
                        temp3->next=temp1;
                        temp1=temp1->next;
                        temp3=temp3->next;
                        temp3->next=temp2;                      //first list1 element is inserted and then list2 element is inserted
                        temp2=temp2->next;
                        temp3=temp3->next;//to point to the last element in the list3
                    }
                }   
        }
        if(temp1==nullptr && temp2!=nullptr)// if list1 completes before list2, remaining list2 nodes are inserted as they were in list3
        {
            temp3->next=temp2;
        }
        else if(temp1!=nullptr && temp2==nullptr)// if list2 completes before list2, remaining list1 nodes are inserted as they were in list3
        {
            temp3->next=temp1;
        }
    }
    head1=nullptr;//emptys list1
    head2=nullptr;//emptys list2
    Display();
}

//prints the elements of each list in order
void ListADT::Display()
{
    Node* temp;
    if(head1!=nullptr)//to check if list1 is empty ||not
    {
    temp=head1;
    printf("List 1:\n");
    while(temp!=nullptr)//to reach till the last node of the list
    {
     printf("%d\t",temp->data);
     temp=temp->next;
    }
    printf("\n");
    }
    else{//if head1==nullptr meaning list1 is empty
        printf("List 1 is Empty\n");
    }
    if(head2!=nullptr)//to check if list2 is empty ||not
    {
    temp=head2;
    printf("List 2:\n");
    while(temp!=nullptr)//to reach till the last node of the list
    {
     printf("%d\t",temp->data);
     temp=temp->next;
    }
    printf("\n");
    }
    else//if head2==nullptr meaning list2 is empty
    {
        printf("List 2 is Empty\n");
    }
    if(head3!=nullptr)//to check if list3 is empty ||not
    {
    temp=head3;
    printf("List 3:\n");
    while(temp!=nullptr)//to reach till the last node of the list
    {
     printf("%d\t",temp->data);
     temp=temp->next;
    }
    printf("\n");
    }
    else{//if head3==nullptr meaning list3 is empty
        printf("List 3 is Empty\n");
    }
}
//Deletes all nodes created during runtime
void ListADT::Exit()
{
    Node* temp;//To delete one node at a time
    while(head1!=nullptr)//deletes list1
    {
        temp=head1;
        head1=head1->next;
        delete temp;
    }
    while(head2!=nullptr)//deletes list2
    {
        temp=head2;
        head2=head2->next;
        delete temp;
    }
    while(head3!=nullptr)//deletes list3
    {
        temp=head3;
        head3=head3->next;
        delete temp;
    }
    printf("Exiting...\n");
}
//Deletes list3
void ListADT::Delete()
{
    Node* temp;
    while(head3!=nullptr)
    {
        temp=head3;
        head3=head3->next;
        delete temp;
    }
}