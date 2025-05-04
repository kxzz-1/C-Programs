#include<stdio.h>
void main()
{
    int num,table,counter,cycles;
    printf("Enter a number:");
    scanf("%d",&num);
    printf("\nEnter the first number you want to multiply:");
    scanf("%d",&counter);
    printf("\nEnter the last number you want to multiply:");
    scanf("%d",&cycles);
    do
    {
        table=num*counter;
        /* code */
        printf("%d*%d=%d\n",num,counter,table);
        counter++;
    }
    while (counter<=cycles);

}
