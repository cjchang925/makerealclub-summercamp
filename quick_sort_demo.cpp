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
    chrono::high_resolution_clock::time_point beginTime = chrono::high_resolution_clock::now();
    quickSort(books, 0, 1000 - 1);
    chrono::high_resolution_clock::time_point endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, std::ratio<1, 1000000>> duration_ms = chrono::duration_cast<chrono::duration<double, ratio<1, 1000000>>>(endTime - beginTime);
    std::cout << "Quick Sort takes " << duration_ms.count() << " microseconds for sorting 1000 elements\n";
    /*for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << books[i] << ' ';
    }*/
    return 0;
}