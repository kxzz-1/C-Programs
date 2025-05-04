#include <stdio.h>
void main()
{
    float array[5];
    int i,j,flag;
    float value;
    for(i=0;i<=4;i++)
    {
        printf("Enter array element[%d]: ", i);
        scanf("%f", &array[i]);
    }
    printf("Enter a value to search: ");
    scanf("%f", &value);
    flag=0;
    for(i=0;i<=4;i++)
    {
        if(value==array[i])
        {
            printf("Element Found");
            flag=1;
            break;
        }
        if(flag==0)
            printf("Element not found");
    }
}
