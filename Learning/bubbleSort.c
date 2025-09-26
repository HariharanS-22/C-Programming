/*
Bubble Sort:
 * Bubble Sort is a simple comparison-based sorting algorithm.
 * It repeatedly steps through the array, compares adjacent elements,
 * and swaps them if they are in the wrong order.
 * The largest elements "bubble up" to the end of the array in each pass.

 Time Complexity:
 * Best Case   : O(n^2) in this code (array already sorted but still full passes are done)
 *               → O(n) if optimized by early stopping without extra outer loop.
 * Average Case: O(n^2) (random order elements)
 * Worst Case  : O(n^2) (array sorted in reverse order)

Space Complexity: 
 * O(1) (sorting is done in-place)
 */

#include <stdio.h>
#include <stdbool.h>
void bubbleSort(int *arr, int length) {
    
    bool Swapped = false;

    do {
        Swapped = false;
        for (int i = 0; i < length; i++) {                 // j < (length - 1 - i) - This implies that at i th iteration,
            for (int j = 0; j < (length - 1 - i); j++) {   // the last i elements will be sorted
                
                if (arr[j] > arr[j+1]) {                   // Compare with the next index
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    Swapped = true;                        // Track if any swap happened
                }
            }
        }
    } while (Swapped == true);                             // Stop if no swaps in a full pass
}

void print_array(int *arr, int length) {
    printf("Array : ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3,5,6,3,2,1,4,8,2};

    int len = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, len);
    bubbleSort(arr, len);
    printf("After Sorting\n");
    print_array(arr, len);

    return 0;
}
