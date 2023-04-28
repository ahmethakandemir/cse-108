#include <stdio.h>





void foo_min_max(int arr[], int n){
    arr[0] = -999999;
    arr[1] = 999999;
    printf("enter your array: ");
    int i = 0;
    while(i < n){
        scanf("%d",&arr[i + 2]);
        if(arr[i+2] > arr[0]){
            arr[0] = arr[i+2];
        }
        if (arr[i+2]<arr[1]){
            arr[1] = arr[i+2];
        }
        i++;
    }

}


int main(){
    int n;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int arr[n + 2];
    foo_min_max(arr,n);
    printf("\nmin value is: %d\nmax value is: %d\n", arr[1], arr[0]);

}