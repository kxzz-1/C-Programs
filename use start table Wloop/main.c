#include<stdio.h>
void main()
{
    int num,table;
    printf("Enter a number:");
    scanf("%d",&num);
    int counter;
    printf("\nEnter the multipyer:");
    scanf("%d",&counter);
    while(counter<=10)
    {
        printf("%d*%d=%d\n",num,counter,table,table=num*counter);
        counter++;
    }
}


