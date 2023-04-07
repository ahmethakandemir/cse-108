#include <stdio.h>

int main(){

    int input,inputtemp,counter = 0;
    while (counter < 3 || counter > 5)
    {
        counter = 0;
        printf("\nenter a number(3,4 or 5): ");
        scanf("%d",&input);
    
        inputtemp = input;

        if(input == 0) {
            counter = 1;
        }
        while(input != 0){
            input /= 10;
            counter++;
        }
        input = inputtemp;
    }
    printf("\nReversed number is: ");

    for(int i = 0; i< counter; i++){


            printf("%d",input % 10);
            input /= 10;

    }
    printf("\n");
    return 0;

}