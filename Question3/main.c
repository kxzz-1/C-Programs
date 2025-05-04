#include <stdio.h>
void sum(int n, int* isPrime);
void main()
{
    int i, num, j = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 2; i <= num / 2; ++i)
        {
        int isPrime1 = 1;
        int isPrime2 = 1;

        sum(i, isPrime1);
        sum(num - i, isPrime2);

        if (isPrime1 == 1 && isPrime2 == 1)

            {
            printf("YES\nExplanation:%d can be expressed as the sum of %d and %d which are prime.\n", num, i, num - i);
            j = 1;
        }
    }

    if (j == 0)
        {
        printf("NO\nExplanation:There are no two prime numbers whose sum is %d.\n", num);
    }

}

void sum(int n, int* isPrime)
{
    int i;
    *isPrime = 1;
    for (i = 2; i <= n / 2; ++i)
        {
        if (n % i == 0) {
            *isPrime = 0;
            break;
        }
    }
}
