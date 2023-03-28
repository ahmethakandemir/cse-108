#include <stdio.h>

int main(){
    int a, b, c, median;
    
    printf("Enter 3 integers between 0-100: ");
    scanf("%d%d%d",&a,&b,&c);
    
    if(a == b){
        printf("median number is %d\n",b);
        return 0;
    }
    else if(a == c){
        printf("median number is %d\n",c);
        return 0;
    }
    else if (b == c)
    {
        printf("median number is %d\n",b);
        return 0;
    }
    
    if(b > a){
        if (c > b)
        {
            printf("median number is %d\n",b);
        }
        else if(b > c){
            if(c > a){
                printf("median number is %d\n",c);
            }
            else if(a > c){
                printf("median number is %d\n",a);
            }
        }
    return 0;
    }

    if(a > b){
        if (b > c)
        {
            printf("median number is %d\n",b);
        }
        else if(c > b){
            if(a > c){
                printf("median number is %d\n",c);
            }
            else if(c > a){
                printf("median number is %d\n",a);
            }
        }
    return 0;   
    }
}