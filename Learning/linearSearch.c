#include <stdio.h>

int linearSearch(int *arr, int n, int find){
    for(int i = 0; i<n ; i++){
        if(arr[i] == find){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 5, 4, 8, 3, 10, 9};
    int len = sizeof(arr)/sizeof(int);

    int find = 8;
    int find_index = linearSearch(arr, len, find);
    if(find_index != -1){
        printf("The element %d is found at the index : %d",find, find_index);
    }else{
        printf("The element is not found in the array\n");
    }
    return 0;
}