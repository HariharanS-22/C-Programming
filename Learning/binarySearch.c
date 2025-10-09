#include <stdio.h>

int binarySearch(int *arr, int n, int find){
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low + high)/2;
        if (arr[mid] == find) return mid;
        else if(find > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {2, 5, 4, 8, 3, 10, 9};
    int len = sizeof(arr)/sizeof(int);

    int find = 8;
    int find_index = binarySearch(arr, len, find);
    if(find_index != -1){
        printf("The element %d is found at the index : %d",find, find_index);
    }else{
        printf("The element is not found in the array\n");
    }
    return 0;
}