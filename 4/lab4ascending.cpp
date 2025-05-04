#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
#include"Lab4Header.h"//imports the header file where functions are written

int main()
{
    int choice,num;
    class ListADT list;
    do
    {
     printf("\n\t\tMENU\n");
     printf("\t\t----\n");
     printf("\t1.Insert in 1st list\n");
     printf("\t2.Insert in 2nd list\n");
     printf("\t3.Merge both into 3rd list\n");
     printf("\t4.Display\n");
     printf("\t5.Exit\n");
     printf("Enter your choice:");
     scanf("%d",&choice);
        switch(choice)
        {
    case 1://To insert in list 1 in ascending order
           printf("Enter the number to be inserted:");
           scanf("%d",&num);
           list.Insert_Ascending(num,1);
           break;
    case 2://To insert in list2 in ascending order
           printf("Enter the number to be inserted:");
           scanf("%d",&num);
           list.Insert_Ascending(num,2);
            break;
    case 3://To merge list 1 and list 2 into list 3 in ascending order
           list.Merge();
           break; 
    case 4://To Display all the arrays
           list.Display();
           break;
    case 5://To exit the program
           list.Exit();
           break;
    default:printf("Invalid Choice\n");
            continue;
        }
    }while(choice!=5);
}
