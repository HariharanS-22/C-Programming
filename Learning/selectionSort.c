/*
Selection Sort:
 * Selection Sort repeatedly selects the smallest (or largest) element
 * from the unsorted part of the array and places it at the beginning
 * of the unsorted section. The boundary between sorted and unsorted
 * parts moves forward with each iteration.

Time Complexity:
 * Best Case   : O(n^2) → still scans all elements to find the minimum
 * Average Case: O(n^2)
 * Worst Case  : O(n^2)
 * 
Space Complexity: 
 * O(1) → sorting is done in-place
 */

#include <stdio.h>

void print_array(int *arr, int len){
    printf("Array : ");
    for (int i=0; i<len ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int len);

int main(){
    int arr[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
    int len = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, len);

    printf("After sorting\n");
    selectionSort(arr, len);

    print_array(arr, len);

    return 0;
}

/*
For each position i:
  - Find the index of the smallest element in the unsorted part (i..n-1)
  - Swap it with the element at index i
*/
void selectionSort(int *arr, int len){
    for (int i = 0; i < len - 1; i++){
        int min_pos = i;                     

        for (int j = i + 1; j < len; j++){
            if (arr[j] < arr[min_pos])
                min_pos = j;
        }

        if (min_pos != i){
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}
