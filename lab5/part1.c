#include <stdio.h>
int game();
int ctof();
int ftoc();

int main(){

    game();


}
int game(){
    while(1){
        char choice;
        printf("\n\nTemperature Conversion Menu\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c",&choice);
        switch (choice)
        {
        case '1':
            ctof();
            break;
        case '2' :
            ftoc();
            break;
        case '3' :
            printf("you exitted the program\n");
            return 0;
            break;
        default:
            printf("invalid choice, please select again.");
            break;
        }

    }
    return 0;
}

int ctof(){
    float celc,fahren;
    
    printf("\nenter the temperature yo want to convert: ");
    scanf("%f",&celc);

    fahren = (celc*(1.8)) + 32;

    printf("%.2f celcius = %.2f fahrenheit.",celc, fahren);

    return 0;
}

int ftoc(){
    float fahren,celc;
    
    printf("\nenter the temperature yo want to convert: ");
    scanf("%f",&fahren);

    celc = (fahren-32)*(0.5555555);

    printf("%.2f fahrenheit = %.2f celcius.",fahren, celc);

    return 0;

}