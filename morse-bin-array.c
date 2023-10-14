#include<stdio.h>
#include<string.h>

int main(){
    char s[27] = "ETIANMSURWDKGOHVFLPJBXCYZQ";

    char input[100];
    fgets(input, sizeof(input), stdin);
    int parent=0;

    for(int i=0; i<= strlen(input); i++){
        if(input[i] == '.'){
            parent = (2*parent) + 1;
        }
        else if(input[i] == '-'){
            parent = (2*parent) + 2;

        }
        else{
            printf("%c", s[parent-1]);
            parent =0;
        }
    }
}