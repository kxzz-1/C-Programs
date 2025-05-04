#include <stdio.h>
#include <string.h>
#include <conio.h>

struct book
{
    int srnum;
    char ISBN[15];
    char name[15];
    char edition[15];
    char author[15];
    int is_reserved;
};
void addbook();
void delbook();
void searchbyisbn();
void searchbyname();
void searchbyauthor();
void modifybook();
void displaybooks();
void issuebook();

void main()
{

    FILE *fp;
    int choice;

     printf("\nLibrary Management System\n");
        printf("1. Add Books\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Modify/Update Book\n");
        printf("5. Display All Books\n");
        printf("6. Issue Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
            case 1:
                addbook();
                break;
            case 2:
                delbook();
                break;
            case 3:
                printf("Search by?");
                printf("\na. ISBN");
                printf("\nb. Book Name");
                printf("\nc. Authors Name");
                char searchchoice;
                printf("\nEnter your choice: ");
                scanf("%c", &searchchoice);
                switch (searchchoice)
                    {
                    case 'a':
                        searchbyisbn();
                        break;
                    case 'b':
                        searchbyname();
                        break;
                    case 'c':
                        searchbyauthor();
                        break;
                    }
                    break;
            case 4:
                modifybook();
                break;
            case 5:
                displaybooks();
                break;
            case 6:
                issuebook();
                break;
        }

}

void addbook()
{
    FILE *fp;
    struct book b;
    fp = fopen("D:\\Library\\library.dat", "a");
        printf("\nAdd Book Details\n");

        printf("Enter name of the book: ");
        gets(b.name);
        fflush(stdin);
        printf("Enter serial number of book: ");
        scanf("%d", &b.srnum);
        fflush(stdin);
        printf("Enter ISBN number of book: ");
        gets(b.ISBN);
        printf("Enter edition of the book: ");
        gets(b.edition);
        printf("Enter author's name: ");
        gets(b.author);
        b.is_reserved=0;
        fprintf ( fp, "%s %d %s %s %s\n", b.name, b.srnum, b.ISBN, b.edition, b.author );
        printf("Book successfully added");
        fclose(fp);

}

void delbook()
{
    struct book b;
    FILE *fp, *ft;
    char isbn[15];
    int found = 0;

    fp = fopen("D:\\Library\\library.dat", "r");
    if (fp == NULL)
    {
        printf("CANT OPEN FILE");
        exit(1);
    }

    printf("\nEnter Book ISBN Number to delete its record:");
    scanf("%s", isbn);

    ft = fopen("D:\\Library\\templibrary.dat", "w");
    while (fscanf(fp, "%s %d %s %s %s", b.name, &b.srnum, b.ISBN, b.edition, b.author) != EOF)
    {
        if (strcmp(isbn, b.ISBN) != 0)
            fprintf(ft, "%s %d %s %s %s\n", b.name, b.srnum, b.ISBN, b.edition, b.author);
        else
            found = 1;
    }

    fclose(fp);
    fclose(ft);

    if (found==0)
        {
        remove("D:\\Library\\templibrary.dat");
        printf("Book with ISBN %s not found.\n", isbn);
        }
    else
        {
        remove("D:\\Library\\library.dat");
        rename("D:\\Library\\templibrary.dat", "D:\\Library\\library.dat");
        printf("Record successfully deleted.\n");
        }
}

void searchbyisbn()
{
    struct book b;
    FILE *fp;
    int found=0;
    char isbn[15];
    fp= fopen("D:\\Library\\library.dat","r+");
    if (fp==NULL)
    {
        printf("CANT OPEN FILE\n");
        exit(1);
    }
    printf("Enter ISBN No to search book :\n");
    scanf("%s",&isbn);
    fflush(stdin);
    while (fscanf(fp, "%s %d %s %s %s", b.name, &b.srnum, b.ISBN, b.edition, b.author) != EOF)
    {
     if(strcmp(isbn,b.ISBN)==0)
        {
        printf("BOOK FOUND\n");
        printf("Name of book: %s\n", b .name);
        printf("Serial number of book: %d\n", b.srnum);
        printf("ISBN number of book: %s\n", b.ISBN);
        printf("Edition of book: %s\n", b.edition);
        printf("Author's name: %s\n", b.author);
        printf("\n");
         found=1;
         break;
        }
    }
    if(found==0)
    printf("BOOK NOT FOUND\n");


}
void searchbyname()
{
    struct book b;
    FILE *fp;
    int found=0;
    char name[15];
    fp= fopen("D:\\Library\\library.dat","r+");
    if (fp==NULL)
    {
        printf("CANT OPEN FILE\n");
        exit(1);
    }
    printf("Enter Name of book to search :\n");
    scanf("%s",&name);
    fflush(stdin);
    while (fscanf(fp, "%s %d %s %s %s", b.name, &b.srnum, b.ISBN, b.edition, b.author) != EOF)
    {
     if(strcmp(name,b.name)==0)
        {
        printf("BOOK FOUND\n");
        printf("Name of book: %s\n", b .name);
        printf("Serial number of book: %d\n", b.srnum);
        printf("ISBN number of book: %s\n", b.ISBN);
        printf("Edition of book: %s\n", b.edition);
        printf("Author's name: %s\n", b.author);
        printf("\n");
         found=1;
         break;
        }
    }
    if(found==0)
    printf("BOOK NOT FOUND\n");


}
void searchbyauthor()
{
    struct book b;
    FILE *fp;
    int found=0;
    char author[15];
    fp= fopen("D:\\Library\\library.dat","r+");
    if (fp==NULL)
    {
        printf("CANT OPEN FILE\n");
        exit(1);
    }
    printf("Enter Author's name to search book :\n");
    scanf("%s",&author);
    fflush(stdin);
    while (fscanf(fp, "%s %d %s %s %s", b.name, &b.srnum, b.ISBN, b.edition, b.author) != EOF)
    {
     if(strcmp(author,b.author)==0)
        {
        printf("BOOK FOUND\n");
        printf("Name of book: %s\n", b .name);
        printf("Serial number of book: %d\n", b.srnum);
        printf("ISBN number of book: %s\n", b.ISBN);
        printf("Edition of book: %s\n", b.edition);
        printf("Author's name: %s\n", b.author);
        printf("\n");
         found=1;
         break;
        }
    }
    if(found==0)
    printf("BOOK NOT FOUND\n");
}
void modifybook()
{
    struct book b;
    FILE *fp, *ft;
    char isbn[15];
    int found = 0;

    fp = fopen("D:\\Library\\library.dat", "r");
    if (fp == NULL)
    {
        printf("CANT OPEN FILE");
        exit(1);
    }

    printf("\nEnter Book ISBN Number to Modify its record:");
    scanf("%s", isbn);

    ft = fopen("D:\\Library\\templibrary.dat", "w");
    while (fscanf(fp, "%s %d %s %s %s", b.name, &b.srnum, b.ISBN, b.edition, b.author) != EOF)
    {
        if (strcmp(isbn, b.ISBN) == 0)
            {
            found = 1;
            printf("\nEnter new details of book\n");
            printf("Enter new name of the book: ");
            fflush(stdin);
            gets(b.name);
            printf("Enter serial number of book: ");
            scanf("%d", &b.srnum);
            printf("Enter ISBN number of book: ");
            gets(b.ISBN);
            printf("Enter edition of the book: ");
            gets(b.edition);
            printf("Enter author's name: ");
            gets(b.author);
            b.is_reserved = 0;
            }
        fprintf(ft, "%s %d %s %s %s\n", b.name, b.srnum, b.ISBN, b.edition, b.author);
    }

    fclose(fp);
    fclose(ft);

    if (found==0)
    {
        printf("Book with ISBN %s not found.\n", isbn);
        remove("D:\\Library\\templibrary.dat");
    }
    else
    {
        remove("D:\\Library\\library.dat");
        rename("D:\\Library\\templibrary.dat", "D:\\Library\\library.dat");
        printf("Modification complete.\n");
    }
}



void displaybooks()
{

    struct book b;
    FILE *fp;
    fp = fopen("D:\\Library\\library.dat", "r");
    if(fp==NULL)
    {
        fp= fopen("D:\\Library\\library.dat","a+");
        if(fp==NULL)
        {
            printf("CANT OPEN FILE");
            exit(1);
        }
    }

        printf("\nBooks Details\n\n");

    while(fscanf(fp,"%s %d %s %s %s", b.name, &b.srnum, b.ISBN, b.edition, b.author)!= EOF)
    {
    printf("Name of book: %s\n", b .name);
    printf("Serial number of book: %d\n", b.srnum);
    printf("ISBN number of book: %s\n", b.ISBN);
    printf("Edition of book: %s\n", b.edition);
    printf("Author's name: %s\n", b.author);
    printf("\n");
    }

    fclose(fp);
}
void issuebook()
{
    struct book b;
    FILE *fp, *ft;
    char isbn[15];
    int found = 0;

    fp = fopen("D:\\Library\\library.dat", "r");
    if (fp == NULL)
    {
        printf("CANT OPEN FILE");
        exit(1);
    }

    printf("\nEnter Book ISBN Number to reserve or unreserve its record:");
    scanf("%s", isbn);

    ft = fopen("D:\\Library\\templibrary.dat", "w");

    while (fscanf(fp, "%s %d %s %s %s %d", b.name, &b.srnum, b.ISBN, b.edition, b.author, &b.is_reserved) != EOF)
    {
        if (strcmp(isbn, b.ISBN) != 0)
            fprintf(ft, "%s %d %s %s %s %d\n", b.name, b.srnum, b.ISBN, b.edition, b.author, b.is_reserved);

         else
        {
            found = 1;
            printf("Book Found: %s\n", b.name);
            printf("Is the book with ISBN %s Reserved? (1 for yes, 0 for no): ", isbn);
            scanf("%d", &b.is_reserved);
            fflush(stdin);

            fprintf(ft, "%s %d %s %s %s %d\n", b.name, b.srnum, b.ISBN, b.edition, b.author, b.is_reserved);
        }
    }

    fclose(fp);
    fclose(ft);

    if (found==0)
    {
        remove("D:\\Library\\templibrary.dat");
        printf("Book with ISBN %s not found.\n", isbn);
    }
    else
    {
        remove("D:\\Library\\library.dat");
        rename("D:\\Library\\templibrary.dat", "D:\\Library\\library.dat");
        printf("Reservation status updated successfully.\n");
    }
}
