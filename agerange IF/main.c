#include <stdio.h>
void main()
{
    int age;
    printf("Enter your age=");
    scanf("%d", &age);
    if(age>=1&&age<=13)
        printf("Child");
    if(age>13&&age<=18)
        printf("Teen");
    if(age>18&&age<=30)
        printf("Adult");
    if(age>30&&age<=50)
        printf("Middle Age");
    if(age>50)
        printf("Old");
}
