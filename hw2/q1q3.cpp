// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>

int maxlen(int* a, int n);

int main() {
    int array[14] = {1,1,1,1,2,3,3,4,5,6,6,6,6,7};
    int largestInt = 7;

    std::cout << maxlen(array, largestInt) << "\n";

    return 0;
}

int maxlen(int* a, int n) {
    int longestSequence = 0;
    int currentSequence = 1;
    int lastInt = 0;

    // simple solution:
        // for entire array, as long as lastInt == currentInt,
        // keep incrementing currentSequence.
        // If currentSequence > longestSequence, make them the same.
    for (int index = 0; a[index] < n; index++) {
        if (lastInt == a[index]) {
            ++currentSequence;
            if (currentSequence > longestSequence)
                longestSequence = currentSequence;
        }
        else
            currentSequence = 1;
        lastInt = a[index];
    }
    // optimizations:
        // exit if longestSequence > distance from currentInt to end
    return longestSequence;
}

void reduce(int* a&, int n) {
    int largest;
    int secondLargest;
    int thirdLargest;

    // array is unsorted
    // need to make a new array
    // set 1st element to 1st, 2nd, 3rd largest
    // if next element is larger, make it 1st largest,
    // for each subsequent element, if it is not larger
    // than 1st, check 2nd. If not larger than 2nd, check 3rd.
    // store indices of largest elements (how?)
    // count how many nLargest elements there are
    // for the size of new array

    largest = a[0];
    secondLargest = a[0];
    thirdLargest = a[0];
    
    for (int index = 0; a[index] != n; index++) {
        if (a[index] > largest)
            largest = a[index];
        else if (a[index] > secondLargest)
            secondLargest = a[index];
        else if (a[index] > thirdLargest)
            thirdLargest = a[index];
    }
}
