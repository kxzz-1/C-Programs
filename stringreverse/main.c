#include<stdio.h>
#include<string.h>
int main()
{
    char original[10],reverse[10];
    printf("ENTER ORIGINAL STRING: ");
    scanf("%s",original);
    strcpy(reverse,original);
     strrev(reverse);
    printf("REVERSE STRING: %s",reverse);
    if(strcmp(original,reverse)==0)
        printf("\nREVERSE IS SAME");
    else
        printf("\nREVERSE IS NOT SAME");
}
