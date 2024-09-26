#include <iostream>
using namespace std;

// pushes the largest value all the way to the right by swapping
// the largest value on the left with their smaller neighbor
// on the right until the array is sorted
void bubble_sort (int arr[], int size) {
    //original array [8, 9, 2, 1, 10, 6, 7, 4, 3, 5]
    /*
        Iterate through the array 1 time less than the size. WHY?
        because you're essentially iterating through value pairs, and the
        largest value is going to be pushed to the end during the first iteration
        meaning you will only need to iterate through n-1 value pairs.
    */
    for (int i = 0; i < size - 1; i++) {
        cout << "iteration i: " << i << endl;
        /*
            iterate through the array n-1 times less than the size.
            This is because the largest value will have already been sorted
            to the end of the array every nth loop. SO this loop need only
            iterate through those numbers in the array that haven't been
            sorted. 

            Fully loops every nth loop until sorted.
        */
        for (int j = 0; j < size - i - 1; j++) {
            cout << "iteration j: " << j << endl;
            /*
                - if the current index is greater than it's neighbor
                - store it in a temporary variable
                - assign the current element to the neighbor's element
                - assign the neighbor's element to the temporary variable
                which stores the current element.
            */
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            // prints out the array
            for (int x = 0; x < size; x++) {
                    cout << arr[x] << ", ";
            }
            cout << endl;
        }
    }
}

int main () {
    int unsorted_array[] = {8,9,2,1,10,6,7,4,3,5};
    int length = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    bubble_sort(unsorted_array, length);
    return 0;
}