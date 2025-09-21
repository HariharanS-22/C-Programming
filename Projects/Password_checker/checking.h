//Checking for caps letter
int caps_check(char *a){
    
    for(int i=0; *(a+i)!='\0' ;i++){
        if(*(a+i)>=65 && *(a+i)<=90){
           return 1;
        }
    }
    return 0;
}

//Checking for small letter
int small_check(char *a){
    
    for(int i=0; *(a+i)!='\0' ;i++){
        if(*(a+i)>=97 && *(a+i)<=122){
            return 1;
        }
    }
    return 0;
}

//Checking for number
int num_check(char *a){
    
    for(int i=0; *(a+i)!='\0' ;i++){
        if(*(a+i)>=48 && *(a+i)<=57){
            return 1;
        }
    }
    return 0;
}

//Checking for special char
int sp_char(char *b){

    for(int i=0 ; *(b+i)!='\0' ;i++){
        if((*(b+i)>=33 && *(b+i)<=47) || (*(b+i)>=58 && *(b+i)<=64) || *(b+i)==95){
            return 1;
        }
    }
    return 0;
}