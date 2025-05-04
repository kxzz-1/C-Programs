#include <stdio.h>

void main()
{
    int num1,num2,num3;
    printf("Enter first number=");
    scanf("%d", &num1);
    printf("Enter second number=");
    scanf("%d", &num2);
    printf("Enter third number=");
    scanf("%d", &num3);
    if(num1>num2&&num1>num3)
        printf("Number 1 is greatest");
 else   if(num2>num3&&num2>num1)
        printf("Number 2 is greatest");
 else   if(num3>num1&&num3>num1)
        printf("Number 3 is greatest");
}
