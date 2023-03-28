#include <stdio.h>

int main(){
    char operation;
    int sub = '-',sum = '+', mult = '*', div = '/';
    int result,a,b,trying;
    
    printf("enter arithmetic operation (+,-,*,/): ");
    scanf("%s",&operation);

    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);

    if(operation == sub){
        result = a - b;
    }
    if(operation == sum){
        result = a + b;
    }
    if(operation == mult){
        result = a * b;
    }
    if(operation == div){
        result = a / b;
    }
    printf("Result: ");
    scanf("%d",&trying);
    if(trying == result){
        printf("Bravo, correct answer!\n");
    }
    else{
        printf("Wrong answer, try again.\n");
    }

}