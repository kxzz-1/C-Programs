#include <stdio.h>

void main()
{
    int n, c, k, space = 1;

    printf("Enter the number of rows (odd number): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    space = n / 2;

    for (k = 1; k <= n; k = k + 2)
        {
        for (c = 1; c <= space; c++)
         {
            printf(" ");
        }

        space--;

        for (c = 1; c <= k; c++)
            {
            printf("*");
        }
        printf("\n");
    }

    space = 1;

    for (k = n - 2; k >= 1; k = k - 2)
        {
        for (c = 1; c <= space; c++)
        {
            printf(" ");
        }

        space++;

        for (c = 1; c <= k; c++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
