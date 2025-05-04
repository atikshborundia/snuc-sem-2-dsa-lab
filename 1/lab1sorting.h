#include<stdio.h>

//sorting using bubblesort
void bubble(int arr[],int size)
{
    int i,j,temp;
    
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void selection(int arr[],int size)
{
    int i,j;
    int min;

    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
        
        if(arr[min]>arr[j])
        {
            min=j;
        }
        }
        if(i!=min){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insertion(int arr[],int size)
{
    int i,j,temp;

    for(i=1;i<size;i++)
    {
        j=i-1;
        temp=arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        if(temp != arr[i])
        {
        arr[j+1]=temp;
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}