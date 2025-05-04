#include <stdio.h>
#include <stdlib.h>

int isEven(int n);
int isPrime(int n);

void main()
{
    FILE *fp, *fpe, *fpo, *fpp;
    int num;

    fp = fopen("D:/data/numbers.dat", "a+");
    fpe = fopen("D:/data/even.dat", "w+");
    fpo = fopen("D:/data/odd.dat", "w+");
    fpp = fopen("D:/data/prime.dat", "w+");

    if (fp == NULL || fpe == NULL || fpo == NULL || fpp == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter numbers (enter -1 to stop):\n");
    while (1)
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        fprintf(fp, "%d\n", num);
    }

    rewind(fp);

    while (fscanf(fp, "%d", &num) != EOF)
    {
        if (isPrime(num))
            fprintf(fpp, "%d\n", num);
        if (isEven(num))
            fprintf(fpe, "%d\n", num);
        else
            fprintf(fpo, "%d\n", num);
    }

    fclose(fp);
    fclose(fpe);
    fclose(fpo);
    fclose(fpp);

    printf("Data written to files successfully.\n");
}

int isEven(int n)
{
    return !(n & 1);
}

int isPrime(int n)
{
    int i;
    if (n < 0)
        return 0;

    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
