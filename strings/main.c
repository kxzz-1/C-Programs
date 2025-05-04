#include<stdio.h>
#include<string.h>
void main()
{
    char masterlist[3][10]={"Rao","Adeel","Nawab"};
    char yourname[20];
    printf("Enter your name: ");
    gets(yourname);
    int i, flag=0,a;
    for(i=0;i<=2;i++)
    {
    a= strcmp(yourname,&masterlist[i][0]);
    if(a==0)
        {
            printf("Welcome to the party");
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf("Sorry your name is not in the list");

}

