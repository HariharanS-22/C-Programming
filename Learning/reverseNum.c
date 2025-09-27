#include <stdio.h>

int main(){
    int num = 0, rev = 0;

    printf("Enter a number : ");
    scanf("%d",&num);

    while (num > 0){
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    printf("The reversed number : %d\n", rev);
    return 0;
}