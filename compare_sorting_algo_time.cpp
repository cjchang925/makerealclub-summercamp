#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <ratio>
#include <fstream>
#include <cstdio>
#define ARRAY_LENGTH 10000
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

void selectionSort(int* books, int* sortedBooks) {
    for (int counter = 1; counter <= ARRAY_LENGTH; counter++) {
        int maximum = -1;
        int maximum_index = -1;
        for (int index = 0; index < ARRAY_LENGTH; index++) {
            if (books[index] > maximum) {
                maximum = books[index];
                maximum_index = index;
            }
        }
        sortedBooks[ARRAY_LENGTH - counter] = maximum;
        books[maximum_index] = -1;
    }
}

int main() {
    int books[ARRAY_LENGTH] = {0};
    srand(time(NULL));
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        books[i] = rand() % ARRAY_LENGTH;
    }
    chrono::high_resolution_clock::time_point beginTime = chrono::high_resolution_clock::now();
    quickSort(books, 0, ARRAY_LENGTH - 1);
    chrono::high_resolution_clock::time_point tempTime = chrono::high_resolution_clock::now();
    chrono::duration<double, std::ratio<1, 1000000>> duration_ms = chrono::duration_cast<chrono::duration<double, ratio<1, 1000000>>>(tempTime - beginTime);
    std::cout << "Quick Sort takes " << duration_ms.count() << " microseconds to sort 10000 elements\n";
    int sortedBooks[ARRAY_LENGTH] = {0};
    chrono::high_resolution_clock::time_point newBeginTime = chrono::high_resolution_clock::now();
    selectionSort(books, sortedBooks);
    chrono::high_resolution_clock::time_point newEndTime = chrono::high_resolution_clock::now();
    chrono::duration<double, std::ratio<1, 1000000>> newDuration_ms = chrono::duration_cast<chrono::duration<double, ratio<1, 1000000>>>(newEndTime - newBeginTime);
    std::cout << "Selection Sort takes " << newDuration_ms.count() << " microseconds to sort 10000 elements\n";
    return 0;
}