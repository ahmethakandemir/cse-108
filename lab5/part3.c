#include <stdio.h>
int convertion(int num,int sayi);

int main(){
    char choice;
    int k = 0;
    int num;
    printf("\n1. Convert a number to decimal, binary, octal, and hexadecimal\n");
    printf("2. Quit\n");

    while(1){
        printf("\n\nenter your choice: ");
        scanf(" %c",&choice);
        switch (choice)
        {
        case '1':
            printf("enter a number: ");
            scanf("%d",&num);
            printf("\n\nDecimal equivalent: ");
            convertion(num,10);
            printf("Binary equivalent: ");
            convertion(num,2);
            printf("Octal equivalent: ");
            convertion(num,8);
            printf("Hexadecimal equivalent: ");
            convertion(num,16);
            break;
        case '2':
            printf("you exitted the program......\n");
            return 0;
        default:
            printf("invalid choice");
            break;
        }
    }
}

int convertion(int num,int sayi){
    int carpici = 1,temp,sum = 0;
    if(sayi != 16){

        while(num != 0){
            temp = num % sayi;
            temp *= carpici;
            carpici *= 10;
            sum += temp;
            num /= sayi;
        }
        printf("%d",sum);
        printf("\n");
        return 0;
    }
    else{
        printf("%X",num);
        return 0;
    }

    return 0;
}
