#include <stdio.h>
float sum(float,float);
float sub(float,float);
float prd(float,float);
float div(float,float);

void main()
{
    float num1,num2,result;
    printf("Enter first number:");
    scanf("%f", &num1);
    printf("Enter second number:");
    scanf("%f", &num2);
    result=sum(num1,num2);
    printf("%f\n", result);
    result=sub(num1,num2);
    printf("%f\n", result);
    result=prd(num1,num2);
    printf("%f\n", result);
    result=div(num1,num2);
    printf("%f\n", result);



}
float sum(float num1, float num2)
{
    float result;
    result=num1+num2;
    printf("Sum of %f and %f is \n", num1,num2);
    return result;
    }
    float sub(float num1, float num2)
  {
    float result;
    result=num1-num2;
    printf("Sub of %f and %f is \n", num1,num2);
    return result;
  }
  float prd(float num1, float num2)
  {
          float result;
    result=num1*num2;
    printf("Prd of %f and %f is \n", num1,num2);
    return result;
  }
  float div(float num1,float num2)
  {
    float result;
    result=num1/num2;
    printf("Div of %f and %f is \n", num1,num2);
    return result;
  }
