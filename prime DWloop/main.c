#include<stdio.h>
void main()
{
    int num,counter,anyvariable=0;
    printf("Enter the number:");
    scanf("%d",&num);
    counter=1;
    do
    {
        /* code */
        if(num%counter==0){
        anyvariable++;}
        counter++;
    } while (/* condition */
    counter<=num);
    if(anyvariable==2){
    printf("prime");}
    else
   { printf("not prime");}


}
