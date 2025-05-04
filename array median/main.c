#include <stdio.h>
void main()
{
    int array[]={10,15,20,25,30,35};
    int arraysize=5;
    printf("Array elements: ");
    for(int i=0;i<arraysize;i++)
    {
        printf("%d ", array[i]);
    }
    for(int i=0;i<arraysize;i++)
    {
        for(int j=0;j<arraysize; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    float median;
    if(arraysize%2 != 0)
        median = array[(arraysize+1)/2];
    else
        median = (array[arraysize/2]+array[arraysize/2+1]) /2;
    printf("\nMedian of array is: %f", median);
}
