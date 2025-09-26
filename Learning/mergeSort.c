/*
Merge Sort:
 * Merge Sort is a "divide and conquer" sorting algorithm.
 * It divides the array into two halves, recursively sorts each half,
 * and then merges the two sorted halves into a single sorted array.
 *
Time Complexity:
 * Best Case   : O(n log n)  (always divides array into halves and merges them)
 * Average Case: O(n log n)
 * Worst Case  : O(n log n)

Space Complexity: 
 * O(n) (uses temporary arrays for merging)
 */

#include <stdio.h>

void merge_sort(int *arr, int len);
void merge_sort_recursion (int *arr, int l, int r);
void merge_sorted_arrays(int *arr, int l, int m, int r);

void print_array(int *arr, int len){
    printf("Array : ");
    for (int i=0; i<len ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] ={ 9,4,8,1,7,0,3,2,5,6};
    int len = sizeof(arr)/ sizeof(arr[0]);
    print_array(arr, len);
    merge_sort(arr, len);
    printf("After sorting\n");
    print_array(arr, len);

    return 0;
}

void merge_sort(int *arr, int len){
    merge_sort_recursion(arr, 0, len - 1);
}

void merge_sort_recursion (int *arr, int l, int r){
    if ( l < r ){
        int m = l + (r-l) / 2;
    
        merge_sort_recursion(arr, l , m);
        merge_sort_recursion(arr, m + 1, r);

        merge_sorted_arrays(arr, l, m, r);
    }
}

void merge_sorted_arrays(int *arr, int l, int m, int r){
    int left_len = m - l + 1;
    int right_len = r - m ;

    int temp_left[left_len];
    int temp_right[right_len];

    for (int i = 0 ; i < left_len ; i++)
        temp_left[i] = arr[l+i];

    for (int j = 0 ; j < right_len ; j++)
        temp_right[j] = arr[m + j + 1];
    
    //                i  
    //  temp_left : 4 9 12
    //                j
    //  temp_right: 5 10 11
    //                  k 
    //        arr : 4 5 

    for (int i = 0, j = 0, k = l ; k <= r ; k++){
        if ((i < left_len) && ((j >= right_len) || temp_left[i] <= temp_right[j])){
            arr[k] = temp_left[i];
            i++;
        }else{
            arr[k] = temp_right[j];
            j++;
        }
    }
}
