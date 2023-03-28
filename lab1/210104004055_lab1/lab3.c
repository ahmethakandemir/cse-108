#include <stdio.h>

int main(){
    int age,exp;
    printf("enter your age: ");
    scanf("%d",&age);
    printf("enter your years of experience: ");
    scanf("%d",&exp);

    if(age < 20){

        if(exp <=10 && exp >= 0){
            printf("Your salary is 10.000");
        }
        else{
            printf("Error");
        }
    }

    if(age >= 20 && age <= 50){

        if(exp <=10 && exp >= 0){
            printf("Your salary is 15.000");
        }
        else{
            printf("Your salary is 20.000");
        }
    }

    if(age > 50){

        if(exp <=10 && exp >= 0){
            printf("Your salary is 20.000");
        }
        else{
            printf("Your salary is 25.000");
        }
    }
    printf("\n");
}