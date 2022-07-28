#include <iostream>
#define ARRAY_LENGTH 5
using namespace std;
void quickSort(int books[ARRAY_LENGTH], int lowerBound, int upperBound);
void swap(int& a, int& b) {    // 交換a和b的值
    int t = a;
    a = b;
    b = t;
}
int main() {
    int books[1000] = {5, 1, 4, 2, 3}; // 宣告代表五本書的Array
    quickSort(books, 0, ARRAY_LENGTH - 1); // 排序這五本書
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << books[i] << ' ';
    }
    return 0;
}