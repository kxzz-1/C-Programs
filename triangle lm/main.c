#include <stdio.h>
void main()
{
    int a,b,c,h,Area,Perimeter;
    printf("Enter side a=");
    scanf("%d", &a);
    printf("Enter base b=");
    scanf("%d", &b);
    printf("Enter side c=");
    scanf("%d", &c);
    printf("Enter height h=");
    scanf("%d", &h);
    Area=(h*b)/2;
    Perimeter=a+b+c;
    printf("(%d*%d)/2=%d\n",h,b,Area);
    printf("%d+%d+%d=%d", a,b,c,Perimeter);
}
