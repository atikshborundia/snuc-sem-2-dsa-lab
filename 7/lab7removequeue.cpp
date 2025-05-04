//this program is used to remove a letter whenever '+' occurs
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "remove.h"

int main(){
    stack s1;
    printf("Enter the string: ");
    char string[50];
    scanf("%s",string);
    int len=strlen(string);
    s1.check(string,len);
}

