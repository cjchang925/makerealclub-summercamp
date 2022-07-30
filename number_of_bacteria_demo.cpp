#include <iostream>
using namespace std;
int calculateNumberOfBacteria(int time) {
    // In the beginning, there is 1 bacteria.
    int numberOfBacteria = 1;
    /* 
     * For "time" seconds, we are going to calculate 2^time.
     * Therefore, we use a for loop to implement it.
     * 
     * In the for loop, the variable "counter" stands for
     * the counter of second, so it ranges from 1 to "time."
     * 
     * In each round of the for loop, "numberOfBacteria" is
     * multiplied by 2, and "counter" is added by 1.
     */
    for (int counter = 1; counter <= time; counter++) {
        numberOfBacteria *= 2; // multiply "numberOfBacteria" by 2
    }

    return numberOfBacteria;
}

int main() {
    int numberOfBacteria = calculateNumberOfBacteria(10);
    cout << "The number of bacteria after 10 seconds: " << numberOfBacteria << endl;
    return 0;
}