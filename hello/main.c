#include <stdio.h>
void square(float);
void main()
{
    float num;
    printf("Enter a number:");
    scanf("%f", &num);
    square(num);
}
void square(float num)
{
    float result;
    result=num*num;
    printf("Square of %f is %f", num,result);
}
