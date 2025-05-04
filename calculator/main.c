#include <stdio.h>
void main()
{
    int num1,num2,sum,sub,product,divide,mod;
    printf("Enter num1=");
    scanf("%d", &num1);
    printf("Enter num2=");
    scanf("%d", &num2);
    sum=num1+num2;
    sub=num1-num2;
    product=num1*num2;
    divide=num1/num2;
    mod=num1%num2;
    printf("%d+%d=%d\n",num1,num2,sum);
    printf("%d-%d=%d\n",num1,num2,sub);
    printf("%d*%d=%d\n",num1,num2,product);
    printf("%d/%d=%d\n",num1,num2,divide);
    printf("%d%\%d=%d\n",num1,num2,mod);
}
