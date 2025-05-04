#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void addbook();
void deletebook();
void modifybook();
void displaybook();
void issuebook();
void searchbyIsbn();
void searchbyname();
void searchbyauthor();
struct book
{
    int isbn_no;
    int serial_no;
    char name[10];
    int edition;
    char author[10];
    char is_reserved;
} b;
int main()
{
    FILE *fp,*ft;
    char choice,choice2,choice3='Y';
    long int recsize;
    int isbn;
    do
    {
        printf("1.   Add Book\n");
        printf("2.   Delete Book\n");
        printf("3.   Search Book by\n");
        printf("4.   Modify Book Record\n");
        printf("5.   Display All Book in Library\n");
        printf("6.   Issue Book to Anyone\n");
        printf("7.   Exit\n");
        printf("\n***Enter Your choice ***:\n");
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1':
            addbook();
            break;
        case '2':
            deletebook();
            break;
        case '3':
            printf("\ta.   ISBN\n");
            printf("\tb.   Book Name\n");
            printf("\tc   Author Name\n");
            fflush(stdin);
            choice2=getch();
            switch(tolower(choice2))
            {
            case 'a':
                searchbyIsbn();
                break;
            case 'b':
                searchbyname();
                break;
            case 'c':
                searchbyauthor();
                break;
            }
            break;
        case '4':
            modifybook();
            break;
        case '5':
            displaybook();
            break;
        case '6':
            break;
        case '7':
            exit(2);
            break;
        }
        printf("\nWELCOME TO LIBRARY!\nDo u want to perform any function on library books :\n");
        fflush(stdin);
        choice3= getch();
    }
    while(toupper(choice3)=='Y');
    return 0;
}
//ADD************
void addbook()
{
    FILE *fp;
    char choice3='Y';
    int isbn;
    fp= fopen("LMS.txt","a+");
    if(fp==NULL)
    {
            printf("CANT OPEN FILE");
            exit(1);
    }
    do
    {
        printf("\nEnter ISBN number :\n");
        scanf("%d",&isbn);
        rewind(fp);
        while(fscanf(fp,"%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved)!=EOF)
         {
            if(isbn==b.isbn_no)
                {
                    printf("ISBN no Already exists Enter Another ISBN number to continue\n");
                break;
                }
         }
         fseek(fp, 0, SEEK_END); //if not use it r+ will place cursor at start for overwriting
             if(isbn!=b.isbn_no)
            {
            b.isbn_no=isbn;
        printf("\nEnter Serial Number,  Name , Edition, Author name , Book reserved(Y/N):\n");
        scanf("%d %s %d %s %c",&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved);
            fprintf(fp,"%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
            }
        printf("Do u want to enter record of a new book\n");
        fflush(stdin);
        choice3= getch();
    }
    while(toupper(choice3)=='Y');
    fclose(fp);
}
//DELETE***********
void deletebook()
{
    FILE *fp,*ft;
    long int recsize;
    int isbn;
    char choice3='Y';
    fp= fopen("LMS.txt","r+");
    if(fp==NULL)
    {
            printf("CANT OPEN FILE");
            exit(1);
    }
    do
    {
        printf("\nEnter Book ISBN Number to delete its record:");
        scanf("%d",&isbn);
        ft = fopen("TLMS.txt","w+");
        rewind(fp);
        while(fscanf(fp,"%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved)!=EOF)
        {
            if(isbn!=b.isbn_no)
                fprintf(ft,"%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
        }
        fclose(fp);
        fclose(ft);
        remove("LMS.txt") ;
        rename("TLMS.txt","LMS.txt");//NOW TLMS IS UR LMS AND U CAN ACCES IT BY fp
      printf("\nRECORD DELETED SUCCESSFULLY\n\n");
        printf("Do u want to Delete record of another book\n");
        fflush(stdin);
        choice3= getch();
    }
    while(toupper(choice3)=='Y');
    fclose(fp);
}
//DISPLAY**********
void displaybook()
{
    FILE *fp;
    fp= fopen("LMS.txt","r+");
    if(fp==NULL)
    {
        fp= fopen("LMS.txt","a+");
        if(fp==NULL)
        {
            printf("CANT OPEN FILE");
            exit(1);
        }
    }
    rewind(fp);
    while(fscanf(fp,"%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved)!=EOF)
        printf("\n%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
    printf("\n\n");
    fclose(fp);
}
//MODIFY************
void modifybook()
{
  FILE *fp,*ft;
    long int recsize;
    int isbn;
    char choice3='Y';
    fp= fopen("LMS.txt","r+");
    if(fp==NULL)
    {
            printf("CANT OPEN FILE");
            exit(1);
    }
    do
    {
        printf("\nEnter Book ISBN Number to Modify its record:");
        scanf("%d",&isbn);
        ft = fopen("TLMS.txt","a+");
        rewind(fp);
        while(fscanf(fp,"%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved)!=EOF)
        {
            if(isbn!=b.isbn_no)
                fprintf(ft,"%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
            else if(isbn==b.isbn_no)
            {
                printf("\nEnter New ISBN no, Serial Number,  Name , Edition, Author name , Book reserved(Y/N):\n");
                scanf("%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved);
                fprintf(ft,"%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
            }
        }
        fclose(fp);
        fclose(ft);
        remove("LMS.txt") ;
        rename("TLMS.txt","LMS.txt");
        printf("Do u want to Modify record of another book\n");
        fflush(stdin);
        choice3= getch();
}while(toupper(choice3)=='Y');
    fclose(fp);
}
//SEARCH****BY ISBN***
void searchbyIsbn()
{
FILE *fp;
char choice3;
int isbn,flag=0;
fp= fopen("LMS.txt","r+");
if (fp==NULL)
{
    printf("CANT OPEN FILE\n");
    exit(1);
}
do
{
printf("Enter ISBN No to search book :\n");
scanf("%d",&isbn);
rewind(fp);
 while(fscanf(fp,"%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved)!=EOF)
 {
     if(isbn==b.isbn_no)
     {
         printf("BOOK FOUND\n");
         printf("\n%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
         flag=1;
         break;
     }
 }
 if(flag==0)
    printf("BOOK NOT FOUND\n");
printf("Do u want to Seach record of another book by ISBN : \n");
        fflush(stdin);
        choice3= getch();
}while(toupper(choice3)=='Y');
fclose(fp);
}
//SEARCH****BY NAME***
void searchbyname()
{
FILE *fp;
char choice3,bookname[10];
fp= fopen("LMS.txt","r+");
if (fp==NULL)
{
    printf("CANT OPEN FILE\n");
    exit(1);
}
do
{
printf("Enter Book Name to search book :\n");
fflush(stdin);
scanf("%s",bookname);
rewind(fp);
 while(fscanf(fp,"%d %d %s %d %s %c",&b.isbn_no,&b.serial_no,b.name,&b.edition,b.author,&b.is_reserved)!=EOF)
 {
     if(strcmp(bookname,b.name)==0)
     {
         printf("BOOK FOUND\n");
         printf("\n%-2d %-3d %-10s %d %-10s %c\n",b.isbn_no,b.serial_no,b.name,b.edition,b.author,b.is_reserved);
         break;
     }
 }
   if(strcmp(bookname,b.name)!=0)
   {
       printf("BOOK NOT FOUND\n");
   }
printf("Do u want to Search record of another book by Name :\n");
        fflush(stdin);
        choice3= getch();
}while(toupper(choice3)=='Y');
fclose(fp);
}
//SEARCH****BY AUTHOR***
void searchbyauthor()
{
    FILE *fp;
    char choice3, authorname[10];
    int flag = 0;  // Add this line
    fp = fopen("LMS.txt", "r+");
    if (fp == NULL)
    {
        printf("CANT OPEN FILE\n");
        exit(1);
    }
    do
    {
        printf("Enter Author Name to search book :\n");
        fflush(stdin);
        scanf("%s", authorname);
        rewind(fp);
        while (fscanf(fp, "%d %d %s %d %s %c", &b.isbn_no, &b.serial_no, b.name, &b.edition, b.author, &b.is_reserved) != EOF)
        {
            if (strcmp(authorname, b.author) == 0)
            {
                printf("BOOK FOUND\n");
                printf("\n%-2d %-3d %-10s %d %-10s %c\n", b.isbn_no, b.serial_no, b.name, b.edition, b.author, b.is_reserved);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("BOOK NOT FOUND\n");
        }
        printf("Do u want to Search record of another book by Author Name :\n");
        fflush(stdin);
        choice3 = getch();
    } while (toupper(choice3) == 'Y');
    fclose(fp);
}

//ISSUE****************
