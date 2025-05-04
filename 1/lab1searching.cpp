#include<stdio.h>

//sortings
#include<stdio.h>
#include<cstdlib>
#include "sorting.h"

void LinearSearch(int a[],int n);
void BinarySearch(int a[],int n);

int main()
{
 
 int size,i;
 char choice,choice1;
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
    
    printf("\nsort using\n1.Bubblesort\n2.Selection Sort\n3.Insertion Sort\n4.Binary Search\n5.Linear Search\n6.Exit\nEnter your choice:");
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
case '4'://Binary Search
            printf("1.In sorted array\nEnter your choice:");
            scanf(" %c",&choice1);
            if(choice1 == '1')
            {
            BinarySearch(dup,size);
            break;
            }
            else
            {
               printf("Invalid choice\n");
               break;
            }
case '5'://Linear Search
             printf("1.In sorted array\n2.In unsorted array\nEnter your choice:");
            scanf(" %c",&choice1);
            if(choice1 == '1')
            {
            LinearSearch(dup,size);
            break;
            }
            else if(choice1 == '2')
            {
            LinearSearch(arr,size);
            break;
            }
            else
            {
               printf("Invalid choice\n");
               break;
            }
case '6'://Exiting...
          printf("Exiting...\n");
    }

 }while(choice != '6');

 return 0;
}

void LinearSearch(int a[],int n)
{
   int S,i,check;
   printf("Enter the number to be searched:");
   scanf("%d",&S);
   for(i=0;i<n;i++)
   {
      if(S==a[i])
      {
         printf("The index of the element %d is %d\n",S,i);
         check=10;
      }
   }
   if(check!=10)
   {
      printf("Element not found\n");
   }
}

void BinarySearch(int a[],int n)
{
   int S,min,max;
   min=0;
   max=n-1;
   printf("Enter the element to be searched:");
   scanf("%d",&S);

   while(a[(min+max)/2]!=S && min<=max)
   {
      if(S<a[(min+max)/2])
      {
         max=((min+max)/2)-1;
      }
      else if(S>a[(min+max)/2])
      {
         min=((min+max)/2)+1;
      }
     
   }
 if(a[(min+max)/2]==S)
 {
    printf("The index of the element %d is %d\n",S,(min+max)/2);
 }  

 else 
      {
         printf("Element not found\n");
      
      }
}