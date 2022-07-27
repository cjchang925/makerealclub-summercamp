#include <iostream>

using namespace std;

void printOneToFour(int x) {
    cout << x << " ";
    if (x == 4) {
        return; // end this function
    }
    // continue printing
    printOneToFour(x + 1);
}

int main() {
    printOneToFour(1);
    return 0;
}

