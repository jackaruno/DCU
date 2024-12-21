/**Heading
Author: Jack Mcmahon
Date: 17/12/2024
Description: library Catalog Management

**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Book Book;
struct Book
{
    char *title;
    char *author;
    int year;
    Book *next;
    Book *prev;
};

Book *create_library_linked_list(char *argv[], int book_count, Book *first_library_book);
void find_books_after_date(Book *first_library_book, int given_year);
void print_all(Book *last_book);
void print_book(Book *book);


int main(int argc, char *argv[]){
    int count_of_books = atoi(argv[1]);
    Book *first_library_book = (Book *)malloc(sizeof(Book));
    Book *last_book = (Book *)malloc(sizeof(Book));
    last_book = create_library_linked_list(argv, count_of_books, first_library_book);
    print_all(last_book);
    int given_year = atoi(argv[(count_of_books*3)+2]);
    find_books_after_date(last_book, given_year);
}


Book *create_library_linked_list(char *argv[], int book_count, Book *first_library_book){
    first_library_book->prev = NULL;
    Book *current = first_library_book;
    Book *prev;
    //printf("\n\n");
    for (int i = 0;i<book_count;i++){
        //printf("%s %s %d\n", argv[(i*(3))+2], argv[(i*(3))+3], atoi(argv[(i*(3))+4]));
        current->next = (Book *)malloc(sizeof(Book));
        current->title = argv[(i*(3))+2];
        current->author = argv[(i*(3))+3];
        current->year = atoi(argv[(i*(3))+4]);
        prev = current;
        current = current->next;
        current->prev = prev;
    }
    prev = current->prev;
    current = NULL;
    return prev;
}

void find_books_after_date(Book *first_library_book, int given_year){
    Book *current = first_library_book;
    printf("Books published after %d\n", given_year);
    bool printed = false;
    while (current!=NULL){
        if (current->year>=given_year){
            print_book(current);
            printed = true;
        }
        current = current->prev;
    }
    if (!printed){
        printf("No books found published after %d", given_year);
    }
    

}

void print_all(Book *last_book){
    Book *current = last_book;
    printf("Library Catalog\n");
    while (current){
        print_book(current);
        current = current->prev;
    }
}

void print_book(Book *book){
    printf("Title: %s, ", book->title);
    printf("Author: %s, ", book->author);
    printf("Year: %d\n", book->year);
}