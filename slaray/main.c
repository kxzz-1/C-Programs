#include<stdio.h>

void main()
{
    int size;
    float hr;
    printf("Enter the number of employees");
    scanf("%d",&size);
    float hours[size];
    printf("Enter the hourly rate of salary");
    scanf("%f", &hr);
    for(int i=0;i<size;i++)
    {
        printf("Enter hours of # %d employee",i);
        scanf("%f",& hours[i]);
    }
}
