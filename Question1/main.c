#include <stdio.h>
void main()
{
   int n,num1=0,num2=1,next_num,counter;
   printf("Enter total numbers in series:");
   scanf("%d",&n);
   for(counter=0; counter <n; counter++)
   {
       next_num=num1+num2;
       num1=num2;
       num2=next_num;
       printf("%d\n", next_num);
   }
}

