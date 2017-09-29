// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>

void reduce(int* a&, int n);

int main() {

    return 0;
}

void reduce(int* a&, int n) {
    int largest;
    int secondLargest;
    int thirdLargest;

    // array to store the number of instances
    // legend: [0] = largest count,
    //         [1] = secondLargest count,
    //         [2] = thirdLargest count
    int largestCount[3] = {0};

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
            largest = a[index]
            largestIndices = {0};
}
