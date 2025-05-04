
#include <stdio.h>
int isVowel(char c);
void main()
{
    char c;

    printf("Enter a character: ");
    scanf(" %c", &c);

    if (isVowel(c))

        printf("It is a vowel\n");

    else

        printf("It is a consonant\n");


    return 0;
}

int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
     else

        return 0;

}
