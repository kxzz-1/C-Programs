#include <stdio.h>
void sum(float,int);
void main()
{
    float num1;
    int num2;
    printf("Enter a number:");
    scanf("%f", &num1);
    printf("Enter second number:");
    scanf("%d", &num2);
    sum(num1,num2);
}
void sum(float num1,int num2)
{
    float result;
    result=num1+num2;
    printf("sum of %f and %d is %f:", num1,num2,result);
}
