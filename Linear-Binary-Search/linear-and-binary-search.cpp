#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

//linear search algorithm searches for the target 
//sequentially in an array 
int linear_search(int *arr, int size, int target) {
    // iterate through array
    for (int i = 0; i < size; i++) {
        //if target matches current index return the index
        if (target == arr[i]) {
            return i;
        }
    }
    return -1;
}

// divide and conquer to find the specified value in an array
int binary_search(int *arr, int size, int target) {
    // start at the first position
    int first = 0;
    // last position is the index size minus one
    int last = size - 1;
    // sort the array to [0,2,4,5,7,8,10]
    sort(arr, arr+size);
    // the search will continue so long as the first position 
    // is less than or equal to the last position
    while (first <= last) {
        //define the midpoint every iteration
        int midpoint = round((first + last)/2);
        // if the midpoint is the target we win
        if (arr[midpoint] == target) {
            return midpoint;
        }
        // else if the midpoint is less than the target
        // assign the midpoint + 1 to be first. 
        else if (arr[midpoint] < target)
        {
            first = midpoint + 1;
        }
        // else i.e. the midpoint is greater than the target
        // assign the midpoint - 1 to be last.
        else
        {
            last = midpoint - 1;
        }  
    }
    //if the loop exits without finding the target
    return -1;
}

int main() {
    //initialzing the array to be searched and the target
    int unsorted_array[] = {5, 8, 7, 4, 2, 0, 10};
    int length = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    int find_me = 0;

    //Input output to capture a number value
    cout << "Enter a number between 0 and 10: ";
    while (!(cin >> find_me)) {
        cout << "Please enter numbers only." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter a number between 0 and 10: ";
    } 

    //determining if the linear search was successful
    int linear_index = linear_search(unsorted_array, length, find_me);
    if (linear_index != -1) {
        cout <<  find_me << " was found using linear search at index "<< linear_index << endl;
    } else {
        cout << find_me << " was not found using linear search" << endl;
    }

    //determining if the binary search was successful
    int binary_index = binary_search(unsorted_array, length, find_me);
    if (linear_index != -1) {
        cout <<  find_me << " was found using binary search at index "<< binary_index << endl;
    } else {
        cout << find_me << " was not found using binary search" << endl;
    }

    return 0;
}