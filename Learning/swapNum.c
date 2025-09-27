#include <stdio.h>

void swap_temp(int *num1, int *num2){
    int temp = 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swap_without_temp (int *num1, int *num2){
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

int main(){
    int num1, num2;
    printf("Enter two numbers : ");
    scanf("%d %d",&num1, &num2);
    printf("num1 : %d\nnum2 : %d\n",num1,num2);

    swap_temp(&num1, &num2);
    printf("After Swapping with temp var\nnum1 : %d\nnum2 : %d\n",num1,num2);

    printf("\nEnter two numbers : ");
    scanf("%d %d",&num1, &num2);
    swap_temp(&num1, &num2);
    printf("After Swapping without temp var\nnum1 : %d\nnum2 : %d\n",num1,num2);

    return 0;

}