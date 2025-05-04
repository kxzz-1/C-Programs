#include<stdio.h>
void main()
{
int num,counter,table,cycles;
printf("Enter a number:");
scanf("%d",&num);
 printf("\nEnter the first number you want to multiply:");
    scanf("%d",&counter);
    printf("\nEnter the last number you want to multiply:");
    scanf("%d",&cycles);
    for (counter; counter <= cycles; counter++)
    {
        table=num*counter;
        printf("%d*%d=%d\n",num,counter,table);
    }

}
