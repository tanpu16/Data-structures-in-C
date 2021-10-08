#include<stdio.h>

void countfun(int n);
int fibonacci(int n);

int main()
{
	int num,k=0;
	printf("Enter a Number : ");
	scanf("%d",&num);
	countfun(num);

	printf("\n\nFibonacci is : ");
	int temp = fibonacci(num);
	printf("%d",temp);

	printf("\n\nFibonacci series is : ");
	for(int i=0;i<=num;i++)
	{
		printf("%d ",fibonacci(k));
		k++;
	}


	printf("\n\n");
	return 0;

}

void countfun(int n)
{
	printf("%d ",n);
	if(n == 0)
	{
		return;
	}
	countfun(n-1);
}

int fibonacci(int n)
{
	if(n<=1)
	{
		return n;
	}
	else
	{
		return (fibonacci(n-1) + fibonacci(n-2));  
	}

}
