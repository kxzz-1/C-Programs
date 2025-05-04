#include<stdio.h>
void main()

{
    int num,table;
    printf("Enter a num:");
    scanf("%d",&num);
    int counter=1;
    do
    {
        printf("%d*%d=%d\n",num,counter,table,table=num*counter);
        counter++;
    } while (counter<=10);

}
