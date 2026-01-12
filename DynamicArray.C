#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;
int main() {
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    // Allocate memory
    total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int*));
    for (int i = 0; i < total_number_of_shelves; i++) {
        *(total_number_of_pages + i) = NULL;
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            int books = *(total_number_of_books + x);

            // Reallocate memory for the new book
            *(total_number_of_pages + x) = realloc(*(total_number_of_pages + x), (books + 1) * sizeof(int));

            // Add book pages
            *(*(total_number_of_pages + x) + books) = y;

            // Update number of books
            *(total_number_of_books + x) += 1;

        } else if (type_of_query == 2) {