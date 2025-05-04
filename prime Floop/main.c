#include<stdio.h>
void main()
{
     int num,anyvariable=0;
  printf("ENTER THE NUMBER:");
  scanf("%d",&num);
  for(int counter=1;counter<=num;counter++)
  {
    if(num%counter==0)
    {
        anyvariable++;
    }
  }
  if(anyvariable == 2)
  {
    printf("It is a Prime");

  }
  else{
    printf("Not a Prime number");
  }
}
