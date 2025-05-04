//Array Operations ListADT
#include<stdio.h>
#include<cstdlib>

class ListADT
{
    private:
    int array[5];
    int size=0;
//Acessible to all functions related to class
    public:
    int Insert_Beggining(int num);
    int Insert_End(int num);
    int Insert_Position(int num,int index);
    int Delete_Beggining();
    int Delete_End();
    int Delete_Position(int index);
    int Search(int num);
    void Display();
    int Rotate(int k);
    void Exit();
};

int main()
{
    class ListADT list;
    int choice,num,index,k;
    do
    {//printing MENU
        printf("\n\t\tMENU\n");
        printf("\t\t----\n");
        printf("\t1.Insert Beggining\n");
        printf("\t2.Insert End\n");
        printf("\t3.Insert Position\n");
        printf("\t4.Delete Beggining\n");
        printf("\t5.Delete End\n");
        printf("\t6.Delete Position\n");
        printf("\t7.Search\n");
        printf("\t8.Display\n");
        printf("\t9.Rotate\n");
        printf("\t10.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case  1://To insert a number at the beggining of the array
                    printf("Enter the number to be inserted:");
                    scanf("%d",&num);
                    list.Insert_Beggining(num);
                    break;
            case  2://To insert a number at the end of the array
                    printf("Enter the number to be inserted:");
                    scanf("%d",&num);
                    list.Insert_End(num);
                    break;
            case  3://To insert a number at a given index
                    printf("Enter the number to be inserted:");
                    scanf("%d",&num);
                    printf("At what index should the number be inserted:");
                    scanf("%d",&index);
                    list.Insert_Position(num,index);
                    break;
            case  4://To delete the 0th index of the array
                    list.Delete_Beggining();
                    break;
            case  5://To delete the last index of the array
                    list.Delete_End();
                    break;
            case  6://To delete a certain index in the array
                    printf("Enter the index of the element to be deleted:");
                    scanf("%d",&index);
                    list.Delete_Position(index);
                    break;
            case  7://Search for an element in the array
                    printf("Enter the element to be searched:");
                    scanf("%d",&num);
                    list.Search(num);
                    break;
            case  8://To print the given array
                    list.Display();
                    break;
            case  9://Rotate the array towards left
                    printf("The no of times to be rotated:");
                    scanf("%d",&k);
                    list.Rotate(k);
                    break;
            case 10://Exits the program
                    list.Exit();
                    break;
            default:printf("Invalid Choice\n");//Any other value is invalid except for case values
                    continue;
        }
    }while(choice!=10);
}

int ListADT::Insert_Beggining(int num)
{
   int i;
   if(size<5)
   {
        if(size==0)
        {
        array[0]=num;
        size+=1;
        }
        else
        {
            for(i=size;i>0;i--)
            {
            array[i]=array[i-1];//shifts the array towards right
            }
            array[0]=num;
            size+=1;
        }
   }
    else
    {
        printf("The array is Full\n");
    }
 Display();
 return(num);
}

int ListADT::Insert_End(int num)
{
    if(size<5)
    {
        array[size]=num;//Inserts at the last index of the array
        size+=1;
    }
    else
    {
        printf("The array is Full\n");
    }
 Display();
 return(num);
}

int ListADT::Insert_Position(int num,int index)
{
   int i;
   if(size==0)
   {
    printf("The array is empty. Please start the array\n");
    return(0);
   }
   else
   {
    if(0<=index<=4)
    { 
        if(size<5)
        {
            for(i=size;i>index;i--)
            {
             array[i]=array[i-1];//shifts the array towards right
            }
            array[index]=num;//Inserts at the given index of the array
            size+=1;
        }
        else
        {
            printf("The array is full\n");
        }
    }
    else
    {
        printf("Invalid Index\n");
    }
   }
    Display();
    return(num,index);
}

int ListADT::Delete_Beggining()
{
  int num,i;
  if(size==0)
  {
    printf("The array is Empty\n");
    return(0);
  }
  else
  {
    num=array[0];
    printf("%d is deleted from the array\n",num);
    for(i=1;i<size;i++)
  {
    array[i-1]=array[i];//shifts array towards left
  }
  size-=1;
  }
  Display();
 return(num);
}

int ListADT::Delete_End()
{
   int i,num;
   if(size==0)
   {
    printf("The array is Empty\n");
    return(0);
   }
   else
   {
    num=array[size-1];
    printf("%d is deleted from the array\n",num);
    size-=1;//since its the last element decreasing the size will delete it
   }
 Display();
 return(num);
}

int ListADT::Delete_Position(int index)
{
    int i,num;
    if(size==0)
    {
        printf("The array is Empty\n");
        return(0);
    }
    else
    {
        if(0<=index && index<size)
        {
            for(i=size-1;i>index;i--)
            {
                array[i-1]=array[i];//shifts array towards left till the given index
            }
            size-=1;
        }
        else
        {
            printf("Invalid Index\n");
        }
    }
 Display();
 return(num);
}

int ListADT::Search(int num)
{
    int i,check;
    if(size==0)
    {
        printf("The array is empty\n");
        return(0);
    }
    else{
        for(i=0;i<size;i++)
        {
            if(array[i]==num)//checks whether the element is present in the array
            {
                printf("The index of %d is %d\n",num,i);
                check=1;//To know whether the element is found in the array
            }
        }
        if(check==0)
        {
            printf("The element is not found\n");
        }
    }
    return(i);
}

void ListADT::Display()
{
 int i;
 if(size>0)
 {
 printf("The Current Array is :-\n");
 for(i=0;i<size;i++)
 {
    printf("%d\t",array[i]);
 }
 printf("\n");
 }
 else
 {
    printf("The array is Empty\n");
 }
}
/*
int ListADT::Rotate(int k)
{
    int i,j,dup;
    k=k%size;
    if(size==0)
    {
        printf("the array is empty\n");
        return(0);
    }
    else{
        for(i=1;i<=k;i++)
        {
         dup=array[size-1];
            for(j=size-1;j>0;j--)
             {
            array[j]=array[j-1];//Rotates the array to right
            }
         array[j]=dup;
        }
    }
    Display();
}
*/  
void ListADT::Exit()
{
    printf("Exiting...\n");
}


int ListADT::Rotate(int k)
{
    int i,j,a=0;
    k=k%size;
    int dup[k];
    if(size==0)
    {
        printf("the array is empty\n");
        return(0);
    }
    else{
        for(i=size-k;i<size;i++)
        {
         dup[a]=array[i];
         a++;
        }
         for(j=size-1;j>=k;j--)
             {
            array[j]=array[j-k];//Rotates the array to right
            }
        for(i=0;i<k;i++)
        {
         array[i]=dup[i];
        }
    }
    Display();
}
