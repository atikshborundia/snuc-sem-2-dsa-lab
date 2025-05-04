// program to check numbers for special properties..
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void palindrome(int *num);
void armstorm(int *num);
void perfect_number(int *num);

int main()
{
	int *number = (int*)malloc(sizeof(int));

	printf("Enter a number\n");
	scanf("%d", number);
	// printf("%d", *number);



// taking choice


	char *choice = (char*)malloc(sizeof(char));


	while(*choice!='d' || *choice != 'D')
	{
		printf("Please choose one of the below.\n");
		printf("a. Palindrome\n");
		printf("b. Armstrom\n");
		printf("c. Perfect number\n");
		printf("d. Exit\n");

		scanf(" %c", choice);


		if(*choice == 'a'|| *choice == 'A')
		{
			palindrome(number);

		}
		if(*choice == 'b'|| *choice == 'B')
		{
			armstorm(number);

		}
		if(*choice == 'c'|| *choice == 'C')
		{
			perfect_number(number);
		}
		if(*choice == 'd'|| *choice == 'D')
		{
			break;
		}

	}

	free(choice);
	free(number);
	return 0;






}




void palindrome(int *num)
{

	int *copy = (int*)malloc(sizeof(int));
	int *rem = (int*)malloc(sizeof(int));
	int *rev = (int*)malloc(sizeof(int));
	int *ret = (int*)malloc(sizeof(int));
	*rev = 0;
	*copy = *num;

	while(*copy!=0)
	{
		*rem = (*copy)%10;
		*rev = (*rev)*10+*rem;
		*copy = (*copy)/10;

	}

	if(*rev == *num)
	{
		printf("It's a palindrome number\n");
	}
	else {
		printf("It's not a palindrome number\n");
	}

	free(copy);
	free(rev);
	free(rem);
	free(ret);



}

void armstorm(int *num)
{
	int *copy = (int*)malloc(sizeof(int));
	*copy = *num;

	int *copy1 = (int*)malloc(sizeof(int));
	*copy1 = *num;

	int *digitcount = (int*)malloc(sizeof(int));
	*digitcount = 0;

	int *sum = (int*)malloc(sizeof(int));
	*sum = 0;

	int *rem = (int*)malloc(sizeof(int));


	while((*copy1) != 0)
	{
		(*digitcount)++;
		(*copy1) = (*copy1)/10;
	}

	while((*copy) != 0)
	{
		*rem = *copy%10;
		*sum = *sum + (int)pow((*rem),(*digitcount));
		*copy = *copy/10;
	}

	if(*sum == *num)
	{
		printf("It's an Armstrom number\n");
	}

	else {
		printf("It's not an Armstorm number\n");
	}

	free(copy);
	free(copy1);
	free(digitcount);
	free(sum);
	free(rem);





}


void perfect_number(int *num)
{
	int *i = (int*)malloc(sizeof(int));
	*i = 1;

	int *sum = (int*)malloc(sizeof(int));
	*sum = 0;

	while(*i <= (*num)/2)
	{
		if((*num)%(*i) == 0 )
		{
			*sum = (*sum) + (*i);

		}
		(*i)++;

	}

	if(*sum == *num)
	{
		printf("It's a perfect number\n");
	}

	else
	{
		printf("It's not a perfect number\n");
	}

	free(i);
	free(sum);

}
