/*
Quick Sort:
 * Quick Sort is a "divide and conquer" sorting algorithm.
 * It works by selecting a pivot element, partitioning the array into
 * two parts:
 *    - elements less than or equal to the pivot
 *    - elements greater than the pivot
 * Then it recursively sorts the two subarrays.
 
Time Complexity:
 * Best Case   : O(n log n) → when the pivot splits the array evenly
 * Average Case: O(n log n)
 * Worst Case  : O(n^2) → occurs when the pivot is always the smallest or largest element

Space Complexity: 
 * O(log n) → due to recursive calls on the call stack
 */
#include <stdio.h>

void swap(int *num1 , int *num2);
void quickSort(int *arr, int len);
void quickSort_recursion(int *arr, int low, int high);
int partition(int *arr, int low, int high);

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
    
    quickSort(arr, len);
    
    printf("After sorting:\n");
    print_array(arr, len);

    return 0;
}

void swap(int *num1 , int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void quickSort(int *arr, int len){
    quickSort_recursion(arr, 0, len - 1);
}

void quickSort_recursion (int *arr, int low, int high){
    if (low < high){
        int pivot_index = partition(arr, low, high);
        quickSort_recursion(arr, low, pivot_index - 1);
        quickSort_recursion(arr, pivot_index + 1, high);
    }
}

int partition(int *arr, int low, int high){
    int pivot_value = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if (arr[j] <= pivot_value){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}
