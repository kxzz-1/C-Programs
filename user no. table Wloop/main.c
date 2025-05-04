#include <stdio.h>
void main()

{
    int num,table;
    printf("Enter a number:",num);
    scanf("%d",&num);
    int counter=1;
    while(counter<=10)
    {
        printf("%d*%d=%d\n",num,counter,table,table=num*counter);
        counter++;
    }
}
