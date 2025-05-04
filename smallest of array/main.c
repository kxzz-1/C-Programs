#include <stdio.h>

void main()
{
    int array[] = {10, 5, 23, 17, 8};
    int size = 5;
    int smallest = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
        }
    }

    printf("The smallest number is: %d\n", smallest);
}
