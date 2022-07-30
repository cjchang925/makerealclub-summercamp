#define ARRAY_LENGTH 5

void swap(int& a, int& b);

void quickSort(int books[ARRAY_LENGTH], int lowerBound,
               int upperBound) {
  if (lowerBound >= upperBound) {  // 代表只有1或0本書，不需要排序
    return;                        // 結束遞迴
  }
  int toBeComparedNumber = books[upperBound];
  int smallerNumberIndex = lowerBound;
  for (int walkingIndex = lowerBound; walkingIndex < upperBound;
       walkingIndex++) {
    if (books[walkingIndex] < toBeComparedNumber) {
      swap(books[walkingIndex], books[smallerNumberIndex]);
      smallerNumberIndex++;
    }
  }
  swap(books[upperBound], books[smallerNumberIndex]);

  quickSort(books, lowerBound, smallerNumberIndex - 1);
  quickSort(books, smallerNumberIndex + 1, upperBound);
}


