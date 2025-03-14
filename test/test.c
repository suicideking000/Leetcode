#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void main(){

    char tmp[100];
    scanf("%[^ ]",tmp);
    printf("%s\n",tmp);
    getchar();
    scanf("%s",tmp);
    printf("%s\n",tmp);
}