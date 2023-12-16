#include <stdio.h>
#include "checking.h"

#define MAX 50

int check(char *str,int len){
    if(caps_check(str) && small_check(str) && num_check(str) && sp_char(str) && (len>=12)){
        printf("\nYou have entered a strong password\n");
        return 1;
    }
    else{
        printf("\nThe password must contains \n");
        if(!(len>=12))
            printf("\n\t-> atleast 12 characters\n");

        if(! caps_check(str))
            printf("\n\t-> atleast one Capital character\n");
        
        if(! small_check(str))
            printf("\n\t-> atleast one small character\n");
        
        if(! num_check(str))
            printf("\n\t-> atleast one number character\n");

        if(! sp_char(str))
            printf("\n\t-> atleast one special character\n");
        
        return 0;
    }

}

int main(){
    char user[MAX], pass[MAX];
    int count=0;
    printf("\nEnter your username : ");
    scanf(" %[^\n]",user);
    printf("\nEnter your password : ");
    
    while(1){        
        char temp = getch();
        
        if(temp =='\n'|| temp == '\r'){
            pass[count]='\0';
            break;
        }
        else if(count < MAX - 1){
            pass[count++]=temp;
            printf("*");
        }
    }
    printf("\n");
    
    if(check(pass,count)){
        FILE *fp = fopen("credentials.csv","a+");
        fprintf(fp,"%s,%s\n",user,pass);
        fclose(fp);
    }
    else{
        printf("\nSo, Kindly try again \n");
    }

    return 0;
}