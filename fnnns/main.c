#include <stdio.h>
int factorial(int);
void main()
{
    int num,result;
    printf("Enter a number: ");
    scanf("%d", &num);
    result=factorial(num);
    printf("%d", result);
}
int factorial(int num)
{
    int result;
    if (num==0 || num==1)
        return 1;
    else
        return num * factorial(num-1);
}
