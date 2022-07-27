#include <iostream>
using namespace std;
int calculateNumberOfVirus(int time) {
    // In the beginning, there is 1 virus.
    int numberOfVirus = 1;
    /* 
     * For "time" seconds, we are going to calculate 2^time.
     * Therefore, we use a for loop to implement it.
     * 
     * In the for loop, the variable "counter" stands for
     * the counter of second, so it ranges from 1 to "time."
     * 
     * In each round of the for loop, "numberOfVirus" is
     * multiplied by 2, and "counter" is added by 1.
     */
    for (int counter = 1; counter <= time; counter++) {
        numberOfVirus *= 2; // multiply "numberOfVirus" by 2
    }

    return numberOfVirus;
}

int main() {
    int numberOfVirus = calculateNumberOfVirus(10);
    cout << "The number of virus after 10 seconds: " << numberOfVirus << endl;
    return 0;
}