#include <iostream>
#define ARRAY_LENGTH 10
using namespace std;
void selectionSort(int books[ARRAY_LENGTH], int sortedBooks[ARRAY_LENGTH]) {
    // Run "ARRAY_LENGTH" times taking the maximum book away.
    for (int counter = 1; counter <= ARRAY_LENGTH; counter++) {
        /* 
         * Find the maximum number in array "books."
         * Set "maximum" to -1 so that every book is initially
         * greater than "maximum."
         * Set "maximum_index" to -1 so that initially it does
         * not point to any book.
         */
        int maximum = -1;
        int maximum_index = -1;
        for (int index = 0; index < ARRAY_LENGTH; index++) {
            if (books[index] > maximum) {
                // Renew "maximum" and "maximum_index."
                maximum = books[index];
                maximum_index = index;
            }
        }
        // We have obtained the book with maximum number.
        // Now put it in "sortedBooks." 
        sortedBooks[ARRAY_LENGTH - counter] = maximum;
        books[maximum_index] = -1;
    }
}
int main() {
    int books[ARRAY_LENGTH] = {5, 1, 3, 8, 9, 10, 6, 7, 2, 4};
    int sortedBooks[ARRAY_LENGTH] = {0};
    selectionSort(books, sortedBooks);
    for (int index = 0; index < ARRAY_LENGTH; index++) {
        cout << sortedBooks[index] << ' ';
    }
    return 0;
}