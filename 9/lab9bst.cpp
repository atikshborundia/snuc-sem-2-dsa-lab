/* Binary Search Tree */
#include<cstdio>
#include<stdlib.h>

class BinarySTADT{
    private:
    struct Node{
        int data;
        struct Node *left;
        struct Node *right;
    };
    struct Node *root;
    public:
    BinarySTADT(){//Constructor
      root=NULL;
    }
    ~BinarySTADT(){//Destructor
        FREE(getroot());
    }
    int Insert(int val);//To insert values in to the tree
    Node* getroot(){//To return root node
        return root;
    };
    void Inorder(Node* temp);//To print Inorder
    void Preorder(Node* temp);//To print Preorder
    void Postorder(Node* temp);//To printf Postorder
    bool Search(int val,Node* temp);//To search for an element
    void FREE(Node* temp);//To free all nodes in the tree
};

int main()
{
    class BinarySTADT binary;
    int choice,value;
    do
    {//Menu printfing
        printf("\t   Binary Search Tree\n");
        printf("\tMENU\n");
        printf("1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
            switch(choice)
            {
        case 1:printf("Enter the value to be inserted:");
                scanf("%d",&value);
                if(!binary.Search(value,binary.getroot())){
                    binary.Insert(value);
                }
                else{
                    printf("The element is already present in the Tree\n");
                }
                break;
        case 2:printf("Preorder: ");
                binary.Preorder(binary.getroot());
                printf("\n");
                break;
        case 3:printf("Inorder: ");
                binary.Inorder(binary.getroot());
                printf("\n");
                break;
        case 4:printf("Postorder: ");
                binary.Postorder(binary.getroot());
                printf("\n");
                break;
        case 5:printf("Enter the value of the element to be searched:");
                scanf("%d",&value);
                if(binary.Search(value,binary.getroot())){
                    printf("Element is present in the Tree\n");
                }
                else{
                    printf("Element is not present in the Tree\n");
                }
                break;
        case 6:printf("Exiting...\n");
                break;
        default:printf("Invalid Choice\n");
                continue;
            }
    }while(choice!=6);
}
//To insert a new node into the tree
int BinarySTADT::Insert(int value){
    Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
    }
    else{
        struct Node* curr=root;
        struct Node* prev=NULL;
        while(curr!=NULL){
            if(curr->data > newnode->data){
                prev=curr;
                curr=curr->left;
            }
            else{
                prev=curr;
                curr=curr->right;
            }
        }
        if(prev->data > newnode->data){
            prev->left=newnode;
        }
        else if(prev->data <= newnode->data){
            prev->right=newnode;
        }
    }
    return(value);
}

//To printf the Inorder of the tree
void BinarySTADT::Inorder(Node* temp){
   if(temp!=NULL)
   {
    Inorder(temp->left);
    printf("%d ",temp->data);
    Inorder(temp->right);
   }
}
//To printf the Preorder of the tree
void BinarySTADT::Preorder(Node* temp){
    if(temp!=NULL){
        printf("%d  ",temp->data);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
//To print the Postorder of the tree
void BinarySTADT::Postorder(Node* temp){
    if(temp!=NULL){
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d  ",temp->data);
    }
}
//To search for an element in the tree
bool BinarySTADT::Search(int val,Node* temp){
    if(temp==NULL){
        return(0);
    }
    else{
        if(temp->data==val){
            return(1);
        }
        else{
            if(temp->data < val){
            return(Search(val,temp->right));
            }
            else{
                return(Search(val,temp->left));
            }
    }
}
}
//To free all nodes in the tree
void BinarySTADT::FREE(Node* temp){
    if(temp!=NULL){
        FREE(temp->left);
        FREE(temp->right);
        free(temp);
    }
}