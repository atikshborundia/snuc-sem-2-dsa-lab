//TO get number of testcase, tower and block for each tower and compare the first block and increment it if the it is lower than other till it become higher or equal to other
#include<iostream>
#include<cstring>
#include<cstdlib>
#include <algorithm>

class tow{
    public:
    int result(int arr[],long int tower);
};

int main(){
    tow tree;
    long int testcase,tower;
    char input[100];
    while(true){
        printf("Enter the number of testcase : ");
        scanf("%ld",&testcase);
        if(1<=testcase && testcase<=10000){
            break;
        }
        else{
            printf("Enter the proper value of testcase :");
        }
    }
    int ans[testcase];

    for(int i =0; i<testcase;i++){
        while(true){
            printf("Enter the number of tower : ");
            scanf("%ld",&tower);
            if(2<=tower && tower<=200000){
                break;
            }
            else{
                printf("Enter the proper calue of tower");
            }
        }
        int arr[tower];
        printf("Enter the value of the block in the tower : ");

        scanf(" %[^\n]",input);
        int count=0;
        char *token=strtok(input," ");
        while(token!=NULL){
            arr[count++]=atoi(token);
            token=strtok(NULL," ");
        }
        std::sort(arr, arr + tower);
        ans[i]=tree.result(arr,tower);
    }

    for(int i=0;i<testcase;i++){
        printf(" %d\n",ans[i]);
    }
    return 0;
}

//To check the first element and increment it and decrement the remanining number
int tow::result(int arr[],long int tower){
    int value;
    for(int i=1;i<tower;i++){
        while(true){
            if(arr[0]<arr[i]){
                arr[0]=arr[0]+1;
                arr[i]=arr[i]-1;
            }
            else{
                break;
            }
        }
    }
    value=arr[0];
    return value;
}