#include <stdio.h>
void main()
{
    int age;
    printf("Enter your age=");
    scanf("%d", &age);
    if(age>=1&&age<=13)
        printf("Child");
else    if(age>13&&age<=18)
        printf("Teen");
else    if(age>18&&age<=30)
        printf("Adult");
else    if(age>30&&age<=50)
        printf("Middle Age");
else    if(age>50)
        printf("Old");
}
