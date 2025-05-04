#include<stdio.h>
void main()
{
    int num,table,counter;
    printf("Enter a number:");
    scanf("%d", &num);
    for (counter=1;counter<=10;counter++)
    {
        printf("%d*%d=%d\n",num,counter,table,table=num*counter);
    }


}
