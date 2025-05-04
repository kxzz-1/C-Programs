#include<stdio.h>
void main()
{
    int arr1[2][2];int arr2[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("Enter array1 element[%d,%d]:",i,j);
            scanf("%d",& arr1[i][j]);
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("Enter array2 element[%d,%d]:",i,j);
            scanf("%d",& arr2[i][j]);
        }
    }
    for(int a=0;a<2;a++)
    {
        for(int b=0;b<2;b++)
        {
            int prd=arr1[a][b]*arr2[a][b];
            printf("\nPRODUCT of elements at (%d,%d) = %d",a,b,prd);
        }
    }

}
