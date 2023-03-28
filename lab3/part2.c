#include <stdio.h>

int main(){
    int a,b,c;
    float average,af,bf,cf;
    printf("Enter your scores between 0-100: ");
    scanf("%f%f%f",&af,&bf,&cf);
    char gradea,gradeb,gradec;
    average = (af + bf + cf)/3;
    //turning into integer numbers to use it in switch statement.
    a = af; b = bf; c = cf;
    printf("Your letter grades are ");
    switch( a/10 )
    {
        case 10: 
        case 9: 
            printf("A+");
            break;
        case 8: 
            printf("A");
            break;
        case 7:
            printf("B+");
            break;
        case 6: 
            printf("B");
            break;
        case 5:
            printf("C");
            break;
        case 4:
            printf("D");
            break;
        default:
            printf("F");
            break;
    }
    printf(", ");
    switch( b/10 )
    {
        case 10: 
        case 9: 
            printf("A+");
            break;
        case 8: 
            printf("A");
            break;
        case 7: 
            printf("B+");
            break;
        case 6:  
            printf("B");
            break;
        case 5: 
            printf("C");
            break;
        case 4: 
            printf("D");
            break;
        default: 
            printf("F");
            break;
    }
    printf(" and ");
    switch( c/10 )
    {
        case 10: 
        case 9:  
            printf("A+");
            break;
        case 8:  
            printf("A");
            break;
        case 7: 
            printf("B+");
            break;
        case 6:  
            printf("B");
            break;
        case 5: 
            printf("C");
            break;
        case 4: 
            printf("D");
            break;
        default: 
            printf("F");
            break;
    }
    printf(" with an %.1f average.",average);
    return 0;
    
} 



