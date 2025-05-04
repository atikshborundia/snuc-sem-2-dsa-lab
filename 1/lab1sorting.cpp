//sortings
#include<stdio.h>
#include<cstdlib>

//types of sortings
void bubble(int a[],int n);
void selection(int a[],int n);
void insertion(int a[],int n);

int main()
{
 
 int size,i;
 char choice;
 printf("Enter the no of elements in the array:");
 scanf("%d",&size);
 int arr[size];
 int dup[size];
 for(i=0;i<size;i++)
 {
    printf("Enter Element %d:",i+1);
    scanf("%d",&arr[i]);
 }
        do{
    
        printf("The unsorted array is:\n");
        for(i=0;i<size;i++)
        {
            printf("%d  ",arr[i]);
        }
        puts("");
    printf("\nsort using\n1.Bubblesort\n2.Selection Sort\n3.Insertion Sort\n4.Exit\nEnter your choice:");
    scanf(" %c",&choice);
    switch(choice)
    {
case '1'://chose bubblesort
            for(i=0;i<size;i++)
            {
                dup[i]=arr[i];
            }
         bubble(dup,size);
         break;
case '2'://chose Selection Sort
            for(i=0;i<size;i++)
            {
                dup[i]=arr[i];
            }
         selection(dup,size);
         break;
case '3'://chose Insertion Sort
            for(i=0;i<size;i++)
            {
                dup[i]=arr[i];
            }
         insertion(dup,size);
         break;
case '4'://Exiting
        printf("Exiting...\n");
        return 0;
    }
        }while(choice != '4');

 return 0;
}

//sorting using bubblesort
void bubble(int dup[],int n)
{
    int i,j,temp;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(dup[j]>dup[j+1])
            {
                temp=dup[j];
                dup[j]=dup[j+1];
                dup[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",dup[i]);
    }
}

void selection(int dup[],int n)
{
    int i,j;
    int min;

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
        
        if(dup[min]>dup[j])
        {
            min=j;
        }
        }
        if(i!=min){
            int temp=dup[i];
            dup[i]=dup[min];
            dup[min]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",dup[i]);
    }
    printf("\n");
}

void insertion(int dup[],int n)
{
    int i,j,temp;

    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=dup[i];
        while(j>=0 && dup[j]>temp)
        {
            dup[j+1]=dup[j];
            j--;
        }
        if(temp != dup[i])
        {
        dup[j+1]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",dup[i]);
    }
    printf("\n");
}