#include <stdio.h>

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotateRight_N(int* nums, int len, int N) {
    N = N % len;
    if (N == 0) return;

    // Method 1 :
    // for(int n=0 ; n<N ; n++){
    //     int temp = nums[len-1];
    //     for(int i=len-1 ; i>0 ; i--){
    //         nums[i] = nums[i-1];
    //     }
    //     nums[0] = temp;
    // }

    // Method 2 :
    // int temp[N];
    // for(int i=len-N; i<len ; i++ ){
    //     temp[i-(len-N)] = nums[i];
    // }
    
    // for(int i=len-N-1 ; i>=0; i--){
    //     nums[i+N] = nums[i];
    // }

    // for(int i=0; i<N ; i++){
    //     nums[i] = temp[i];
    // }

    // Method 3: (Optimal)
    reverse(nums, 0, len-N-1);
    reverse(nums, len-N, len-1);
    reverse(nums, 0, len-1);
}

void rotateLeft_N(int* nums, int len, int N) {
    N = N % len;
    if (N == 0) return;

    // Method 1:
    // for(int n=0 ; n<N ; n++){
    //     int temp = nums[0];
    //     for(int i=1 ; i<len ; i++){
    //         nums[i-1] = nums[i];
    //     }
    //     nums[len-1] = temp;
    // }

    // Method 2:
    // int temp[N];
    // for(int i=0; i<N ; i++ ){
    //     temp[i] = nums[i];
    // }
    
    // for(int i=N ; i<len; i++){
    //     nums[i-N] = nums[i];
    // }

    // for(int i=len-N; i<len ; i++){
    //     nums[i] = temp[i - (len-N)];
    // }

    // Method 3: (Optimal)
    reverse(nums, 0, N-1);
    reverse(nums, N, len-1);
    reverse(nums, 0, len-1);
}

void print_array(int *arr, int len){
    printf("Array : ");
    for (int i=0; i<len ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(arr)/sizeof(int);
    print_array(arr,len);

    printf("Rotating right 3 times\n");
    rotateRight_N(arr,len,3);
    print_array(arr, len);

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("Rotating left 3 times\n");
    rotateLeft_N(arr1,len,3);
    print_array(arr1, len);
}