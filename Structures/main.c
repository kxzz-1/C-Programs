#include <stdio.h>
#include <string.h>
void main()
{
    struct book
    {
        char name[20];
        float price;
        int pages;
    };
    struct book b[5];
    for(int i =0; i<=2;i++)
    {
    printf("Enter name of b[%d]= ",i);
    scanf("%s", &b[i].name);
    printf("Enter price of b[%d]= ",i);
    scanf("%f", &b[i].price);
    printf("Enter pages of b[%d]= ",i);
    scanf("%d", &b[i].pages);
    }
     for(int i =0; i<=2;i++)
    {
    printf("\nName of b[%d]= %s",i,b[i].name);
    printf("\nPrice of b[%d]= %.2f",i,b[i].price);
    printf("\nPages of b[%d]= %d",i,b[i].pages);
    }
}
