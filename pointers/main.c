#include <stdio.h>
void callbyname(int,int);
void callbyrefrence(int*,int);
void main()
{
    int a=10,b=20;
    printf("%d %d\n",a,b);
    callbyname(a,b);
    printf("%d %d\n",a,b);
    callbyrefrence( &a,b);
    printf("%d %d\n",a,b);
}
void callbyname(int n1, int n2)
{
    n1=n1+10;
    n2=n2+10;
}
void callbyrefrence(int *n1,int n2)
{
    *n1=*n1+10;
    n2=n2+10;
}
