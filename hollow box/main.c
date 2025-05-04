#include <stdio.h>
void main()
{
    int r=5,c=5;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=r;j++)
        {
            if(i==1||i==r||j==1||j==c)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
