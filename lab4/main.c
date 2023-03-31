#include <stdio.h>
int n = 0;
int k = 0;
char sekil;
char virgul;
int nvalue;
FILE* fptr;
int square(int n);
int triangle(int n);
int write(int k);


int main(){
    
    write(k);

}

int write(int k){
    char c;
    int a;
    if (k == 0){
        printf("\nWelcome to Shape Reader! Please make your choice to continue:\n");
        printf("1-) Generate a shape file\n");
        //printf("2-) Read and draw a shape file\n");
        printf("2-) Terminate the program\n");

    }
    else{
        printf("\nWelcome to Shape Reader! Please make your choice to continue:\n");
        printf("1-) Generate a shape file\n");
        printf("2-) Read and draw a shape file\n");
        printf("3-) Terminate the program\n");
    }
    printf("\n");

    int choice;

    scanf("%d",&choice);

    printf("\n");

    if(choice == 1 && k == 0){


        FILE* fptr = fopen("drawing.txt","w");
	
	while(c!='e'){
        printf("Enter a character and an integer value: ");

        scanf(" %c%*c%d", &c, &a);

        fprintf(fptr,"%c,%d\n", c, a);
        }

        fclose(fptr);
    }
    k = 1;

    if (choice == 2){
    	FILE* fptr = fopen("drawing.txt","r");
    	while(fscanf(fptr, " %c,%d\n", &c, &a) == 2){  		
	        if (c == 'e'){
		    break;
		} 
		else if (c == 't'){
		    triangle(a - 2);
            		printf("\n");
		} 
		else if (c == 's'){
		    square(a);
		    printf("\n");
		 	
		}
    	}
        return 0;
    }
    
    if(choice == 3){
	printf("terminated!!");
    return 1; 
	
    	
    }

    return write(k);

}

int triangle(int n){
    fptr = fopen("drawing.txt","a");
    for (int i = 0; i < n + 1; i++){
        printf(" ");
    }
    printf("*\n");
    for (int i = 0; i < n; i++){
        for (k = i; k < n; k++){
            printf(" ");
        }
        printf("*");
        
        for (int j = 0;j < 2*i + 1; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
    
    }
    for(int i = 0;i < 2*n+3;i++){
        printf("*");
    }
    printf("\n\n");
    return 1;
}

int square(int n){

    for(int i = 0; i < n;i++){
        printf("* ");

    }
    printf("\n");
    for(int i = 0;i < n - 2;i++){
        printf("*");
        for(int i = 0;i < 2 * (n- 2) + 1;i++){
            printf(" ");
        }
        printf("*\n");
    }
    for(int i = 0; i < n;i++){
        printf("* ");
    }    


    return 1;
}

