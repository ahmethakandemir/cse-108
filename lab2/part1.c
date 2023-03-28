#include <stdio.h>
#include <math.h>




int main(){
    // getting inputs and making calculations basically
    
    float edge,width,height,rad;
    printf("Enter the edge length for cube: ");
    scanf("%f",&edge);
    printf("Surface Area = %.2f, Volume = %.2f\n\n", 6*edge*edge, edge*edge*edge);

    printf("Enter side length for rectangular prism: ");
    scanf("%f",&edge);
    printf("Enter side width: ");
    scanf("%f", &width);
    printf("Enter side height: ");
    scanf("%f", &height);
    printf("Surface Area = %.2f, Volume = %.2f\n\n", ((width*height)+(width*edge)+(edge*height))*2,edge*width*height);

    printf("Enter the radius for sphere: ");
    scanf("%f",&rad);
    printf("Surface Area = %.2f, Volume = %.2f\n\n", 4*rad*rad*3.1415926, 3.1415926*1.333333*rad*rad*rad);

    printf("Enter the radius for cone: ");
    scanf("%f",&rad);
    printf("Enter the height: ");
    scanf("%f",&height);
    double a = 3.1415926*rad*(rad+sqrt(rad*rad + height*height));
    printf("Surface Area = %.2f, Volume = %.2f",a,0.333333*3.1415926*rad*rad*height);



}
