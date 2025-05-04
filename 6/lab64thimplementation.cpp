//To check whether the open parenthesis has its corresponding closing parenthesis in a given string.
//Time complexity for both methods is O(n) but space complexity for Counter method for O(1) whereas in stack method is O(n).
//If you just want to check whether the parenthesis are balanced or not counter method is best, but if ypu want to check if they 
// were correctly opend or not then stack is optimal.
//we can modify the counter method to break when balaence goes to negative which is even more optimal than stack since space usage
//is reduced.
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include"Stack.h"
//Declaration of function
char BalanceChecker(char string[],int len);

int main()
{
    class StackADT stack;
    char string[50];
    char balance='1';//To check the balance of parenthesis
    int len;
    int choice;
    do{
        printf("\n\tMENU\n\t----\n1.Balance\n2.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the string:");
                  scanf(" %[^\n]",string);
                  len=strlen(string);
                  //BalanceChecker(string,len);
                  for(int i=0;i<=len;i++)
                  {
                      if(string[i]=='(')
                      {
                          balance=stack.Push(string[i]);
                      }
                      else if(string[i]==')')
                      {
                          balance=stack.Pop();
                          if(balance=='0')
                          {
                            break;
                          }
                      }
                  }
                  if(balance=='1')
                  {
                    printf("The given string is balanced\n");
                  }
                  else
                  {
                    printf("The given string is not balanced\n");
                  }
                    break;
            case 2:break;
            default:printf("Invalid choice\n");
                    continue;
        }
    }while(choice!=2);
}
/*                          To check the parenthesis balance using counter
char BalanceChecker(char string[50],int len)
{
    int balance=0;
    for(int i=0;i<=len;i++)
    {
        if(string[i]=='(')
        {
            balance+=1;
        }
        else if(string[i]==')')
        {
            balance-=1;
        }
    }
    if(balance==0)
    {
        printf("The given string is balanced\n");
    }
    else
    {
        printf("The given string is not balanced\n");
    }
}
    */