#include <stdio.h>
void main()
{
    char string[50];
    printf("Enter a string: ");
    gets(string);
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }
    printf("Length of the string is : %d\n", count);
}
