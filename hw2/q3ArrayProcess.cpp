// Nehemya McCarter-Ribakoff
// Dujmovic
// HW2
// 29 September 2017

#include <iostream>
#include <limits.h>
#include <vector>

void intReturnThreeLargest(int ar[], int topThree[]);
void intReduce(int ar[], int arLength);
void intPrintArray(int ar[]);
int intGetLength(int ar[]);

int main() {
int sampleList[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,7,3,2,4,7,1,3,2,9,2,1,

3,4,4,'\0'};


std::cout <<"Array: \n";
intPrintArray(sampleList);
std::cout << "\n\n_________________________________________________" <<

std::endl << "PROBLEM 3)\n" << std::endl;


// This solution is O(2n)
std::cout <<"Original array: \n";
intPrintArray(sampleList);

intReduce(sampleList, sizeof(sampleList)/sizeof(sampleList[0]));

std::cout <<"Reduced array: \n";
intPrintArray(sampleList);
    return 0;
}

void intReturnThreeLargest(int ar[], int topThree[]){

    int arLength = intGetLength(ar);


// Insted of comparing the value found in the array to the largest
//value first, it's compared to the third largest value. This causes
//less comparisons but is much less readable than the example presented
//in class. The benefit from less comparisons can be seen when there is
//a value found that is less than the third largest value, and as a
//result only requires one comparison, as opposed to 3, with every non-
//large value.


// An O(n) solution
    for (int i = 0; i < arLength; i++) {
        if (ar[i] > topThree[2] && ar[i] != topThree[2] 
            && ar[i] != topThree[1] && ar[i] != topThree[0]) {
            if (ar[i] > topThree[1]) {
                if (ar[i] > topThree[0]) {
                    topThree[2] = topThree[1];
                    topThree[1] = topThree[0];
                    topThree[0] = ar[i];
                } else {
                    topThree[2] = topThree[1];
                    topThree[1] = ar[i];
                }
            } else {
                topThree[2] = ar[i];
            }
        }
    }
}

void intReduce(int ar[], int arLength){
    if (arLength <= 3) {
        ar[0] = '\0';
    } else {
        int topThreeValues[3] = {INT_MIN, INT_MIN, INT_MIN};
        int j = 0;

        // the topThreeValues array is passed into the above function to compute
        // the three largest values of the array.
        intReturnThreeLargest(ar, topThreeValues);

        // To reduce the size of the array and remove the largest 3 values, this
        //for loop iterates to check if a value is one of the three largest values.
        //If it isn't, it's passed into the array (starting at 0) then j increments
        //to move on to the next index.
        for(int i = 0; i < arLength; i++) {
            if(!(topThreeValues[0] == ar[i] || topThreeValues[1] == ar[i] ||
               topThreeValues[2] == ar[i])) {

                ar[j] = ar[i];
                j++;
            }
        }

        //Length of the array is dictated by the null character at the end, therefore
        //we simply place a null character at the final location of our j iterator
        //above. It is not ar[j+1] because j is incrimented one last time after it
        //has already filled in our smaller values.

        ar[j] = '\0';
    }
}

void intPrintArray(int ar[]){
    for(int i = 0; i < intGetLength(ar); i++)
        std::cout << ar[i] << " ";
    std::cout << "\n\n";
}

int intGetLength(int ar[]){
int i = 0;
while(ar[i] != '\0')
i++;
return i;
}
