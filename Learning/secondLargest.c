#include<stdio.h>

int secondLargest(int *arr, int n){
    int largest = arr[0];
    int sLargest = -1;
    
    for(int i=1 ; i<n ; i++){
        if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
        }else if(arr[i] > sLargest && arr[i]<largest){
            sLargest = arr[i];
        }
    }

    return sLargest;
}

int main(){
    int arr[] = {5, 85, 58, 84, 90, 45, 10};
    int len = sizeof(arr)/sizeof(int);
    int sLargest = secondLargest(arr,len);
    
    printf("Second Largest : %d\n",sLargest);
    return 0;
}