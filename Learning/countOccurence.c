#include <stdio.h>
int firstOccurence(int *arr, int n, int target){
    int low = 0;
    int high = n-1;
    int index = n;
    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] >= target){
            index = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return index;
}

int lastOccurence(int *arr, int n, int target){
    int low = 0;
    int high = n-1;
    int index = n;
    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] > target){
            index = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return index - 1;
}

int main(){

    int arr[] = {2, 3, 4, 5, 5, 5, 8, 8, 9, 10};
    int len = sizeof(arr)/sizeof(int);

    int find = 8;
    int first = firstOccurence(arr, len, find);
    int last = lastOccurence(arr, len, find);
    printf("The target %d has\nFirst Occurence : %d\nLast Occurence : %d\n\nCount : %d\n",find, first, last, last-first+1 );
  
    return 0;

}