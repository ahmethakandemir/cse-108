#include <stdio.h>

int main(){
    // getting inputs and making calculations basically
    float height,weight,bmi;
    printf("\n\nBMI calculation started!!!\n");
    printf("\nEnter your height: ");
    scanf("%f",&height);
    printf("Enter your weight: ");
    scanf("%f",&weight);

    bmi = weight/(height*height);
    printf("BMI = %.2f\n",bmi);
    if (bmi < 18.5){
        printf("BMI less than 18.5: underweight");
    }
    else if (bmi >= 18.5 && bmi < 25){
        printf("BMI between 18.5 and 24.9: average weight");
    }
    else if (bmi >= 25 && bmi < 30){
        printf("BMI between 25 and 29.9: overweight");
    }
    else if (bmi >= 30){
        printf("BMI over 30: obese");
    }
    printf("\n");
    return 0;
}