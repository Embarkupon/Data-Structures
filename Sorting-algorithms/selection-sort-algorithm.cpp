#include <iostream>
using namespace std;

void selection_sort (int arr[], int size) {
    /*
        we're always going to have n-1 iterations
        because a value is always sorted every iteration,
        consequently the last value will be sorted by default.
    */
    for (int i = 0; i < size - 1; i++) {
        cout << "Iteration i: " << i << endl;
        // start/current position
        int pos = i;
        /*
            the scan begins at the postion after the current position.
            the current position is compared against every other element
            in the array, and if a smaller value is found, we replace the current
            index with the index of the smallest value.
        */
        for (int j = i + 1 ; j < size; j++) {
            //cout <<  "Iteration j: " << j << endl;
            if (arr[pos] > arr[j]) {
                pos = j;
            }
            //cout << "current value: " << arr[pos] << endl;
        }
        /* 
            if the index has changed i.e. a smaller value was found
            store the current position in a temp variable
            swap the current element with the new, smaller, element
            swap smaller elements previous position with the current
            position in temp.
        */
        if (pos != i) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
        for (int x = 0; x < size; x++) {
            cout << arr[x] << ", ";
        }
        cout << endl;
    }
}

void main() {
    int unsorted_array[] = {5,1,3,8,4,6,2,9,7};
    int length = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    selection_sort(unsorted_array, length); 
}