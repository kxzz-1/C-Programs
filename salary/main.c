#include<stdio.h>
void salary(float [],int);
void main()
{
    int size;
    printf("Enter the number of employees= ");
    scanf("%d",&size);
    float hours[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter hours of #%d employee= ",i+1);
        scanf("%f",& hours[i]);
    }
    salary(hours,size);
}
void salary(float a[],int sizee)
{
    float hr=0;float sal=0;
    printf("Enter hourly rate=");
    scanf("%f",& hr);
    for(int i=0;i<sizee;i++)
    {
        sal= (a[i]) * hr;
        printf("\nSalary of employee #%d =%.2f",i+1,sal);
    }
}
