#include <stdio.h>

int main(){
    
    float z,x,y,max;
    // taking the input from user
    printf("enter the X value: ");
    scanf("%f",&x);
    printf("enter the Y value: ");
    scanf("%f",&y);

    if(x > y){
        max = x;
    }
    else{
        max = y;
    }

    z = (x / y) + (max/(x+y));
    printf("%f\n",z);
    return 0;

}