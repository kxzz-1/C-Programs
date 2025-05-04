#include <stdio.h>
void main()
{
    int size, i, j, duplicatecount;
    printf("Enter the number of elements in array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++)
    {
        printf("Enter element[%d] of array: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size; i++)
    {
        duplicatecount = 1;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicatecount++;
                arr[j] = -1;
            }
        }
        if (duplicatecount > 1 && arr[i] != -1)
        {
            printf("%d occurs %d times\n", arr[i], duplicatecount);
        }
    }
}

