#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct books {
    int Serialno;
    int ISBN;
    int edition;
    char Bookname[20];
    char authorname[20];
    char is_reserved[30];
} b;

struct student {
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
} s;

FILE *fp;

void library_menu();
void add_books();
void display_books();
void delete_books();
void issue_books();
void search_booksbyISBN();
void search_booksbybookname();
void search_booksbyauthorname();
void modify_books();
void exit_program();

int main() {
    int ch;

    while (1) {
        system("cls");
        printf("_LIBRARY MANAGEMENT SYSTEM_\n");
        printf("1. Add Books\n");
        printf("2. Display Books\n");
        printf("3. Delete Books\n");
        printf("4. Issue books\n");
        printf("5. Search Books by ISBN\n");
        printf("6. Search Books by bookname\n");
        printf("7. Search Books by authorname\n");
        printf("8. Modify Books\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)





        {
            case 0:
                exit_program();
                exit(0);

            case 1:
                add_books();
                break;

            case 2:
                display_books();
                break;

            case 3:
                delete_books();
                break;

            case 4:
                issue_books();
                break;

            case 5:
                search_booksbyISBN();
                break;

            case 6:
                search_booksbybookname();
                break;

            case 7:
                search_booksbyauthorname();
                break;

            case 8:
                modify_books();
                break;

            default:
                printf("INVALID CHOICE.\n");
        }
        printf("\nPress any key to continue...");
        getch();
    }

    return 0;
}

void add_books() {
    fp = fopen("books.txt", "ab");

    printf("Enter book serialno: ");
    scanf("%d", &b.Serialno);

    printf("Enter book ISBN: ");
    fflush(stdin);
    scanf("%d", &b.ISBN);

    printf("Enter edition: ");
    fflush(stdin);
    scanf("%d", &b.edition);

    printf("Enter book name: ");
    fflush(stdin);
    fgets(b.Bookname, sizeof(b.Bookname), stdin);

    printf("Enter author name: ");
    fflush(stdin);
    fgets(b.authorname, sizeof(b.authorname), stdin);

    printf("\nBook Added Successfully\n");

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}

void display_books() {
    system("cls");
    printf("AVAILABLE BOOKS\n\n");
    printf("%-10s %-10s %-10s %-10s %-20s\n", "Serial no", "ISBN", "Book name", "Edition", "Author");

    FILE *fp;
    struct books b;

    fp = fopen("books.txt", "rb");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("%-10d %-10d %-10s %-10d %-20s\n", b.Serialno, b.ISBN, b.Bookname, b.edition, b.authorname);
    }

    fclose(fp);
}

void delete_books() {
    int serialno, f = 0;
    system("cls");
    printf("_REMOVE BOOK_\n\n");
    printf("Enter serial no to remove book: ");
    scanf("%d", &serialno);
    FILE *ft;

    fp = fopen("book.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (serialno == b.Serialno) {
            f = 1;
        } else {
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if (f == 1) {
        printf("\n\nDeleted Successfully.\n");
    } else {
        printf("\n\nRecord Not Found!\n");
    }

    fclose(fp);
    fclose(ft);

    remove("book.txt");
    rename("temp.txt", "book.txt");
}

void issue_books() {
    int f = 0;

    system("cls");
    printf("ISSUE BOOK BY ISBN\n\n");

    printf("Enter book ISBN to search: ");
    scanf("%d", &s.id);

    fp = fopen("book.txt", "rb");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.ISBN == s.id) {
            strcpy(s.bookName, b.Bookname);
            f = 1;
            break;
        }
    }

    fclose(fp);

    if (f == 0) {
        printf("No record found.\n");
        return;
    }

    fp = fopen("issue.txt", "ab");
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.sName);

    printf("Enter Student Class: ");
    fflush(stdin);
    gets(s.sClass);

    printf("Enter Student Roll: ");
    scanf("%d", &s.sRoll);

    printf("Book Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void modify_books() {
    char oldbook[40];
    char newbook[40];
    int found = 0;

    printf("Enter the name of the book you want to update: \n");
    fflush(stdin);
    gets(oldbook);
    printf("Enter the new name of the book: \n");
    fflush(stdin);
    gets(newbook);
    FILE *tempFILE = fopen("temp.txt", "w");
    fp = fopen("book.txt", "r");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (strcmp(oldbook, b.Bookname) == 0) {
            found = 1;
            strcpy(b.Bookname, newbook);
        }
        fwrite(&b, sizeof(b), 1, tempFILE);
    }

    fclose(fp);
    fclose(tempFILE);
    remove("book.txt");
    rename("temp.txt", "book.txt");

    if (found) {
        printf("Book is updated successfully.\n");
    }
}

void search_booksbyauthorname() {
    int found = 0;
    char author[40];
    printf("Enter authorname to search book: ");
    fflush(stdin);
    scanf("%s", &author);

    fp = fopen("book.txt", "r");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (strcmp(author, b.authorname) == 0) {
            found = 1;
            printf("BOOK FOUND\n");
            printf("Name of book: %s\n", b.Bookname);
            printf("Serial number of book: %d\n", b.Serialno);
            printf("ISBN number of book: %d\n", b.ISBN);
            printf("Edition of book: %d\n", b.edition);
            printf("Author's name: %s\n", b.authorname);
            printf("\n");
        }
    }

    if (!found) {
        printf("BOOK NOT FOUND\n");
    }

    fclose(fp);
}

void search_booksbybookname() {
    int found = 0;
    char bookname[40];
    printf("Enter name of the book to search book: ");
    fflush(stdin);
    scanf("%s", &bookname);

    fp = fopen("book.txt", "r");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (strcmp(bookname, b.Bookname) == 0) {
            found = 1;
            printf("BOOK FOUND\n");
            printf("Name of book: %s\n", b.Bookname);
            printf("Serial number of book: %d\n", b.Serialno);
            printf("ISBN number of book: %d\n", b.ISBN);
            printf("Edition of book: %d\n", b.edition);
            printf("Author's name: %s\n", b.authorname);
            printf("\n");
        }
    }

    if (!found) {
        printf("BOOK NOT FOUND\n");
    }

    fclose(fp);
}

void search_booksbyISBN() {
    int found = 0;
    int isbn;
    printf("Enter ISBN No to search book: ");
    fflush(stdin);
    scanf("%d", &isbn);

    fp = fopen("book.txt", "r");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (isbn == b.ISBN) {
            found = 1;
            printf("BOOK FOUND\n");
            printf("Name of book: %s\n", b.Bookname);
            printf("Serial number of book: %d\n", b.Serialno);
            printf("ISBN number of book: %d\n", b.ISBN);
            printf("Edition of book: %d\n", b.edition);
            printf("Author's name: %s\n", b.authorname);
            printf("\n");
        }
    }

    if (!found) {
        printf("BOOK NOT FOUND\n");
    }

    fclose(fp);
}

void exit_program() {
    printf("Exiting the program\n");
}
