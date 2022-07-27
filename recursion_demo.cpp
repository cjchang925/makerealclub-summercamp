#include <iostream>

using namespace std;

void printInfiniteNumbers(int number) {
    cout << number << " ";
    printInfiniteNumbers(number + 1);
}

int main() {
    printInfiniteNumbers(1);
    return 0;
}

