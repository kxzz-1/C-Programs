#include <stdio.h>
void main()
{
    int marks[5]={1,2,3,4,5};
    int i,*ptr;
    ptr=marks;
    for(i=0;i<=4;i++)
    {
        printf("%d  %d\n", ptr,*ptr);
        ptr++;
    }
}
