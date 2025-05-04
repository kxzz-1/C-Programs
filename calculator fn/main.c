#include <stdio.h>
int sum(int,int);
int sub(int,int);
int prd(int,int);
int div(int,int);
int mod(int,int);

void main()
{
    int num1,num2,result;
    printf("Enter first number:");
    scanf("%d", &num1);
    printf("Enter second number:");
    scanf("%d", &num2);
    result=sum(num1,num2);
    printf("%d", result);
    result=sub(num1,num2);
    printf("%d", result);
    result=prd(num1,num2);
    printf("%d", result);
    result=div(num1,num2);
    printf("%d", result);
    result=mod(num1,num2);
    printf("%d", result);


}
int sum(int num1, int num2)
{
    int result;
    result=num1+num2;
    printf("Sum of %d and %d is \n", num1,num2);
    return result;
    }
    int sub(int num1, int num2)
  {
    int result;
    result=num1-num2;
    printf("Sub of %d and %d is \n", num1,num2);
    return result;
  }
  int prd(int num1, int num2)
  {
          int result;

    result=num1*num2;
    printf("Prd of %d and %d is \n", num1,num2);
    return result;
  }
  int div(int num1,int num2)
  {
          int result;

    result=num1/num2;
    printf("Div of %d and %d is \n", num1,num2);
    return result;
  }
  int mod(int num1, int num2)
  {
          int result;

    result=num1%num2;
    printf("Mod of %d and %d is \n", num1,num2);
    return result;
}
