#include <stdio.h>
#include <string.h>
#include <ctype.h>

char flames[] = "FLAMES";
int n = 6 ;    // Length of FLAMES

void no_space__tolower(char *str){
    for(int i=0 ; str[i] != '\0' ;i++){
        if((65<=str[i]) && (str[i]<=90))
            str[i]=tolower(str[i]);

        if(str[i]==32){
            for(int j=i;str[j] != '\0';j++)
                str[j] = str[j+1];
        }
    }
}

void FLAMES(int num ,char flames[],int n){
    char temp[7];
    
    if(strlen(flames) != 1){

        int i = ((num % n) - 1 );
        //In case the remainder is zero, which implies the index be -1, the last element
        if(i == -1){
            i = n - 1;
            flames[i] = '\0';
        }else{         
            for( i ; flames[i]!='\0' ; i++){
                flames[i] = flames[i+1];
            }
        }
    
        strcpy(temp,flames);
                                     
        int j = (num % n) - 1;       // The index from which the swap need to be performed
        n = n - 1;                   // As one char is removed
        //We don't need to sort the string if the removed char is at the end i.e, remainder = 0
        if(j != -1){
            int k = 0;               // if the j exceeds the length of flames, then to begin from the first              
            for(int i=0 ; i<n ;i++){
                
                if(j<n){
                    flames[i] = temp[j];
                    j++;
                }else{
                    flames[i] = temp[k];
                    k++;
                }
            }   
        }
        //To recursively perform the same task with changed 'char flames' and decremented 'n'
        FLAMES(num,flames,n);
    }else
        return ;    
}
int distinct(char str1[],char str2[]){
    int index = 0 ;                                      //Index of the same_char
    char same_char[50]={};                               //To store the common char                                    

    no_space__tolower(str1);
    no_space__tolower(str2);
    //To find the common char
    for(int i=0;str1[i]!='\0';i++){
        int same = 0;
        for(int j=0;str2[j]!='\0';j++){
            if(str1[i]==str2[j]){
                // Removing the same char in the str2 to resist the extra occurrence
                for(int k=j;str2[k]!='\0';k++){
                    str2[k]= str2[k+1];
                }
                same = 1;
                break;
            }
        }
        if(same){
            same_char[index] = str1[i];
            index++;
        }
    }
    int num = strlen(str1) + strlen(str2) - strlen(same_char);
    return num;
}

int main(){
    char name1[50], name2[50];
    int ch;
    do{
        printf("\nEnter your name : ");
        scanf(" %[^\n]",name1);
        printf("\nEnter your crush name : ");
        scanf(" %[^\n]",name2);

        int num = distinct(name1,name2);
        
        FLAMES(num,flames,n);

        switch(flames[0]){
            case 'F' : {
                printf("\nThe relationship between you both comes to be 'FRIENDS'\n");
                break;
            }
            case 'L' : {
                printf("\nThe relationship between you both comes to be 'LOVE'\n");
                break;
            }
            case 'A' : {
                printf("\nThe relationship between you both comes to be 'AFFECTION'\n");
                break;
            }
            case 'M' : {
                printf("\nThe relationship between you both comes to be 'MARRIAGE'\n");
                break;
            }
            case 'E' : {
                printf("\nThe relationship between you both comes to be 'ENEMY'\n");
                break;
            }
            case 'S' : {
                printf("\nThe relation between you both comes to be 'SISTER'\n");
                break;
            }
            default : {
                printf("\nOuch ! We got an error. Please try again later\n");
                break;
            }
        }
        printf("\nWould you want to continue -> Press 1\n\nOr to exit                 -> Press 0 \n\nEnter your choice : ");
        scanf("%d",&ch);
        
    }while(ch == 1);
}
