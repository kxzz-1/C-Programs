#include <stdio.h>
void main()
{
    char choice='y';
    while (choice=='y')
    {
       float num;
        printf("Enter a number:");
        scanf("%f", &num);
        printf("Square of the number=%f\n", num*num);
        printf("Do you want to continue?(y/n)\n");
        choice=getche();
        printf("\n");

    }
}
