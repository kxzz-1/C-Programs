#include <stdio.h>
void modify(int*, int);
void main()
{
    int ages[4]={10,15,20,25};
    printf("Values before fn call: ");
    for(int i=0;i<4;i++)
    {
        printf("%d ", ages[i]);
    }
    modify(ages,4);
    printf("Values after fn call: ");
    for(int i=0;i<4;i++)
    {
        printf("%d ", ages[i]);
    }
}
void modify(int *ptr,int size)
{
    for(int i=0;i<size;i++)
    {
        *ptr = *ptr+10;
        ptr++;
    }
}
