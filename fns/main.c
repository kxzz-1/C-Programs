#include <stdio.h>
void square01();
void square02(float);
float square03();
float square04(float);
void main()
{
    square01();
    float num02;
    printf("\nEnter a number:");
    scanf("%f", &num02);
    square02(num02);
    float result;
    result=square03();
    printf("%f", result);
    float num04,result1;
    printf("\nEnter a number:");
    scanf("%f", num04);
    result1=square04(num04);
    printf("%f", result1);
}
void square01()
{
    float num,result;
    printf("Enter a number:");
    scanf("%f", &num);
    result=num*num;
    printf("%f", result);
}
void square02(float num)
{
    float result;
    result=num*num;
    printf("%f", result);
}
float square03()
{
    float num03,result;
    printf("\nEnter a number:");
    scanf("%f", &num03);
    result=num03*num03;
    return result;

}
float square04(float num04)
{
    float result1;
    result1=num04*num04;
printf("Square of %f is", num04);
    return result1;
}
