#include <stdio.h>
int lowerBound(int *arr, int n, int target){
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

int upperBound(int *arr, int n, int target){
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
    return index;
}

int main(){

    int arr[] = {2, 3, 4, 5, 8, 9, 10};
    int len = sizeof(arr)/sizeof(int);

    int find = 5;
    int lower_bound = lowerBound(arr, len, find);
    printf("The lower bound (find >= arr[%d]) : %d\n",lower_bound,lower_bound);

    int upper_bound = upperBound(arr, len, find);
    printf("The upper bound (find < arr[%d]) : %d\n",upper_bound,upper_bound);
  
    return 0;

}