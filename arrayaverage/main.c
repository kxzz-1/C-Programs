#include <stdio.h>
void main()
{
    int array[5]={10,15,20,25,30};
    int i,sum=0;
    float average;
     printf("Array elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
        sum += array[i];
    }
    average= sum/5;
    printf("\nAverage of array elements : %f",average);
}

