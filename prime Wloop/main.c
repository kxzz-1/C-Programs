#include<stdio.h>
void main()
{
  int num,counter,anyvariable=0;
  printf("ENTER THE NUMBER:");
  scanf("%d",&num);
  counter=1;
  while(counter<=num)
  {
    if(num%counter==0)
    {

      anyvariable++;
    }
    counter++;
  }
    if(anyvariable==2)
    {printf("It is a Prime number");}
    else{
     printf("Not a Prime number");}

}
