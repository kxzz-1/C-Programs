#include <stdio.h>

void main()
{
    int sum=0, array [4]={10,15,20,25};
    printf("Sum of elements: ");
    for(int i=0; i<4; i++)
    {
        sum +=array[i];
    }
    printf("%d", sum);
}
