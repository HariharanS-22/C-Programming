/*
Insertion Sort:
 * Insertion Sort builds the sorted array one element at a time.
 * It takes each element (called "key" or "element") and inserts it into
 * the correct position in the already sorted part of the array.

Time Complexity:
 * Best Case   : O(n)       → when the array is already sorted
 * Average Case: O(n^2)     → when elements are in random order
 * Worst Case  : O(n^2)     → when the array is sorted in reverse order

Space Complexity: 
 * O(1)   → sorting is done in-place
 */
#include <stdio.h>

void insertionSort(int *arr, int len);

void print_array(int *arr, int len){
    printf("Array : ");
    for (int i=0; i<len ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] ={9,4,8,1,7,0,3,2,5,6};
    int len = sizeof(arr)/ sizeof(arr[0]);

    print_array(arr, len);
    printf("After sorting\n");
    insertionSort(arr, len );
    print_array(arr, len);
    
    return 0;
}

void insertionSort(int *arr, int len){
    for( int i = 1 ; i < len ; i++){
        int element = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > element){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j + 1] = element;
    }
}