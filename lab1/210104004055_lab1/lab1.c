#include <stdio.h>

int main(){
    int entry;
    // taking the input from user
    printf("enter a value between 1,100: ");
    scanf("%d",&entry);
    // basic if else statements..
    if(entry % 3 == 0){

        printf("Fizz");
    }
    if(entry >= 5 && entry <= 50){

        printf("Buzz");
    }
    
    printf("\n");
    return 0;
}