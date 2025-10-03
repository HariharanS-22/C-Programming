#include <stdio.h>
/*Note: 
    Outer loop --> Number of rows
    Inner loop --> Number of columns and relate them to number of rows to solve
*/
void pattern_1(int n){
/*  * * * *
    * * * *
    * * * *
    * * * *  */
    printf("Pattern 1:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_2(int n){
/*  * * * *
    *     *
    *     *
    * * * *  */
    printf("Pattern 2:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(((i==0) || (i == n-1)) || ((j == 0) || (j == n-1))) 
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }   
}
void pattern_3(int n){
/*  *
    * *
    * * *
    * * * *  */
    printf("Pattern 3:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_4(int n){
/*  1
    1 2
    1 2 3
    1 2 3 4  */
    printf("Pattern 4:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            printf("%d ",j+1);
        }
        printf("\n");
    }
}
void pattern_5(int n){
/*  1
    2 2
    3 3 3
    4 4 4 4  */
    printf("Pattern 5:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            printf("%d ",i+1);
        }
        printf("\n");
    }

}
void pattern_6(int n){
/*  * * * *
    * * *
    * *
    *       */
    printf("Pattern 6:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<= n-i-1 ; j++){
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_7(int n){
/*  1 2 3 4
    1 2 3
    1 2
    1      */
    printf("Pattern 7:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<= n-i-1 ; j++){
            printf("%d ",j+1);
        }
        printf("\n");
    }
}
void pattern_8(int n){
/*        *
        * *
      * * *
    * * * *  */
    printf("Pattern 8:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n; j++){
            if(j<n-i-1){ 
                printf("  ");
            }else{
                printf("* ");
            }
        }
        printf("\n");
    }
}
void pattern_9(int n){
/*  * * * *
      * * *
        * *
          *   */
    printf("Pattern 9:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n; j++){
            if(j<i){ 
                printf("  ");
            }else{
                printf("* ");
            }
        }
        printf("\n");
    }
}
void pattern_10(int n){
/*      *
      * * *
    * * * * *
  * * * * * * *  */
    printf("Pattern 10:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n-i-1; j++){
            printf("  ");
        }
        for(int k=0; k<2*i+1 ; k++){
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_11(int n){
/*  * * * * * * *
      * * * * *
        * * *
          *        */
    printf("Pattern 11:\n");
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<i; j++){
            printf("  ");
        }
        for(int k=0; k<2*(n-i)-1  ; k++){
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_12(int n){
/*      *
      * * *
    * * * * * 
  * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *       */
    
    printf("Pattern 12:\n");
    for (int i = 0; i < 2*n - 1; i++) {
        int space, star;
        if (i < n) {                 
            space = n - i - 1;
            star  = 2*i + 1;
        }else {                     
            space = i - (n - 1);
            star  = 2 * (2*n - 1 - i) - 1;
        }

        for (int j = 0; j < space; j++) {
            printf("  ");
        }
        for (int k = 0; k < star; k++) {
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_13(int n){
/*  *
    * *
    * * *
    * * * *
    * * * * *
    * * * *
    * * *
    * *
    *       */
    
    printf("Pattern 13:\n");
    for(int i=0; i<=2*n-1 ; i++){
        int stars = i;
        if(i>n) stars = 2*n - i;

        for(int j=0 ; j<stars ; j++){
            printf("* ");
        }
        printf("\n");
    }
}
void pattern_14(int n){
/*  1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1
*/    
    printf("Pattern 14:\n");
    for(int i=0 ; i<n ; i++){
        int val = 1;
        if (i%2 != 0) val = 0;
        for(int j=0 ; j<=i ; j++ ){
            printf("%d ",val);
            val = 1 - val;
        }
        printf("\n");
    }
}
void pattern_15(int n){
/*  1             1
    1 2         2 1 
    1 2 3     3 2 1
    1 2 3 4 4 3 2 1
*/    
    printf("Pattern 15:\n");
    for(int i=1 ; i<=n ; i++){
        //value
        for(int j=1 ; j<=i ;j++){
            printf("%d ",j);
        }
        //space
        for(int k = 1; k <= 2*(n-i); k++){
            printf("  ");
        }
        //value
        for(int j=i ; j>=1 ;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
}

int main(){
    int n = 0;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    pattern_1(n);
    pattern_2(n);
    pattern_3(n);
    pattern_4(n);
    pattern_5(n);
    pattern_6(n);
    pattern_7(n);
    pattern_8(n);
    pattern_9(n);
    pattern_10(n);
    pattern_11(n);
    pattern_12(n);
    pattern_13(n);
    pattern_14(n);
    pattern_15(n);

    printf("Pattern 16:\n");
    for(int i=0 ; i<n ; i++){
        for(char ch='A'; ch <= 'A'+ i ; ch++){
            printf("%c ",ch);
        }
        printf("\n");
    }

    printf("Pattern 17:\n");
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            printf("  ");
        }
        char ch='A';
        int middle = (2*i+1)/2;
        for(int k=0; k<2*i+1 ; k++){
            printf("%c ",ch);
            if(k < middle) ch++;
            else ch--;
        }
        printf("\n");
    }

    
    return 0;
}
