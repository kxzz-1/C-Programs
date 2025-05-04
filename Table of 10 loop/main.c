#include <stdio.h>
void main()
{
    int num,num1,num2;
    printf("Enter the number whose table is to be printed:");
    scanf("%d", &num);
    printf("Enter min multiple:");
    scanf("%d", &num1);
    printf("Enter max multiple:");
    scanf("%d", &num2);

    int counter=num1;
    while (counter<=num2)
    {
        printf("%d*%d=%d\n", num,counter,num*counter);
        counter++;
    }
}
