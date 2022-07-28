#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <ratio>
#include <fstream>
#define ARRAY_LENGTH 5
using namespace std;

void swap(int& a, int& b) {    // swap the value of a and b
    int t = a;
    a = b;
    b = t;
}

void quickSort(int* books, int lowerBound, int upperBound) {
    if (lowerBound < upperBound) {    // check the two parameters are legal
        int toBeComparedNumber = books[upperBound];
        int smallerNumberIndex = lowerBound;
        for (int walkingIndex = lowerBound; walkingIndex <= upperBound - 1; walkingIndex++) {
            if (books[walkingIndex] < toBeComparedNumber) {
                swap(books[walkingIndex], books[smallerNumberIndex]);
                smallerNumberIndex++;
            }
        }
        swap(books[upperBound], books[smallerNumberIndex]);
        int comparedNumberIndex = smallerNumberIndex;

        quickSort(books, lowerBound, comparedNumberIndex - 1);
        quickSort(books, comparedNumberIndex + 1, upperBound);
    }
}

int main() {
    int books[1000] = {5, 1, 3, 2, 4};
    quickSort(books, 0, 1000 - 1);
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << books[i] << ' ';
    }
    return 0;
}