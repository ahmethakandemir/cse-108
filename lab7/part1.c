#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mintry(char s[]){
    int len = strlen(s);
    int counter = 0,i,j;

    for (i = 0; i < len; i++) 
    {
        j = 0;
        while (s[i + j + 1] == s[i]) {
            j++;
        }

        counter++;
        i += j;
    }
    if(counter <= 3){
    }
    else{
        counter -= 1;
    }
    return counter;
}
int main() {
    char s[100];
    printf("\nEnter your string: ");
    scanf("%s", s);
    printf("\n Minimum tryings: %d\n", mintry(s));
    
    return 0;
}

