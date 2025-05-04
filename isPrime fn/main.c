#include<stdio.h>
int isPrime(int);
void main()
{
    int num,result;
    printf("Enter a number:");
    scanf("%d",&num);
    result = isPrime(num);
    printf("%d", result);
}
int isPrime(int num)
{
    int i=2;
    while(i<=num/2)
    {
         if(num%i==0)
             return 0;
         else
             i++;
    }
    return 1;
}
