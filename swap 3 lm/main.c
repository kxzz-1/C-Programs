#include <stdio.h>
void main()
{
    int a,b,c;
    printf("Enter a=");
    scanf("%d", &a);
    printf("Enter b=");
    scanf("%d", &b);
    printf("Before swap: a=%d\tb=%d\n", a,b);
    c=a;
    a=b;
    b=c;
    printf("After swap: a=%d\tb=%d", a,c);
}
