#include <stdio.h>
FILE * fans;
void part1();
int part2();
int inputs();
int label();
int write();

int arr[50];
char labels[50];

int main(){

    //part1();
    part2();

}
void part1(){

    inputs();
    label();
    write();

}

int write(){
    for(int i = 0; arr[i] != '\0'; i++){
        printf("%d %c\n",arr[i],labels[i]);
    }
    return 0;
}

int label(){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] % 2 == 0){
            labels[i] = 'e';
        }
        else{
            labels[i] = 'o';
        }
    }
    return 0;
}

int inputs(){
    int k;
    int sentinel = -1;
    int i = 0;

    printf("Enter the integers(sentinel value = -1)\n");

    while(1){
        scanf("%d",&k);
        if(k == sentinel){
            break;
        }
        else{
            arr[i] = k;
        }
        i++;
    }
    printf("-----------------\n");
    return 0;
}










int part2(){

    char selection;
    int k = 0;
    float sum = 0;
    int counter = 0;
    int ages[30];
    char occup[30];
    float salary[30];
    char team[30];

    fans = fopen("fans.txt","r");
    int rows;

    fscanf(fans,"%d",&rows);
    fgetc(fans);

    for(int i = 0; i < rows; i++){
        fscanf(fans,"%d %c %f %c",&ages[i], &occup[i],&salary[i],&team[i]);
    }

    printf("select a team: ");
    scanf("%c",&selection);

    while(1){
        if(team[k] == selection){
            sum += salary[k];
            counter++;
        }
        if(k == rows){
            break;
        }
        k++;
    }

    if(counter != 0){
        printf("Average salaries of fans of %c: %.1f\n",selection, sum / counter );
    }
    else{
        printf("there is no fans if %c in the database\n", selection);
    }
    fclose(fans);
    return 0;


}
